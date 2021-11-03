#define __OFFLOAD              __attribute__ ((__used__, section (".gnu.offload.text")))
#define __OFFLOAD_DATA         __attribute__ ((__used__, section (".gnu.offload.data")))
#define __OFFLOAD_TABLE        __attribute__ ((__used__, section (".gnu.offload.funcs")))
#define __OFFLOAD_TABLE_DATA   __attribute__ ((__used__, section (".gnu.offload.vars")))

#include <stdint.h>

__OFFLOAD void test(void)
{
    printf("Test Function 1\n");
    return;
}

__OFFLOAD_DATA uint32_t a[16];
__OFFLOAD_DATA uint32_t b[16];
__OFFLOAD_DATA uint32_t c[16];

__OFFLOAD void test2(void)
{
    printf("Test Function 2\n");

    for(int i = 0; i < 16; i++){
        a[i] = i;
        b[i] = 1;
        c[i] = 0;
    }
        
    for(int i = 0; i < 16; i++)
        printf("%x, ",c[i]);
    printf("\n");

    for(int i = 0; i < 16; i++){
        c[i] = a[i] + b[i];
    }

    for(int i = 0; i < 16; i++)
        printf("%x, ",c[i]);
    printf("\n");

    return;
}

__OFFLOAD_TABLE void * offload_funcs [] = 
{
    (void *) test,
    (void *) test2
};

__OFFLOAD_TABLE_DATA void * offload_vars [] = 
{
    (void *) a, (void *) (sizeof(uint32_t)*16),
    (void *) b, (void *) (sizeof(uint32_t)*16),
    (void *) c, (void *) (sizeof(uint32_t)*16),
};

//gcc -c -fPIC -shared offload.c -o offload.o

//Link Everything
//gcc -fPIC -Wl,target_desc.o offload.o -Wl,target_offloadend.o -o offload.so
