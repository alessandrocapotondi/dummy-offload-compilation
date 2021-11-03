void __attribute__ ((__used__, section (".gnu.offload_funcs")))
    test(void)
{
    return;
}

void __attribute__ ((__used__, section (".gnu.offload_funcs")))
    test2(void)
{
    int a = *(int *) 0x0004;
    int b = *(int *) 0x0008;
    int c = *(int *) 0x000b;

    c = a + b;
    return;
}


void main(void)
{}

//gcc -c -fPIC -shared offload.c -o offload.o

//Link Everything
//gcc -fPIC -Wl,target_desc.o offload.o -Wl,target_offloadend.o -o offload.so
