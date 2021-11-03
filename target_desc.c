#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern const void *const __offload_func_table_end[];
extern const void *const __offload_var_table_end[];

const void *const __offload_func_table[0]
    __attribute__ ((__used__, visibility ("hidden"),
	section (".gnu.offload.funcs"))) =
{ };

const void *const __offload_var_table[0]
    __attribute__ ((__used__, visibility ("hidden"),
	section (".gnu.offload.vars"))) =
{ };

const void *const __OFFLOAD_TARGET_TABLE__[]
    __attribute__ ((__used__, visibility ("hidden"))) =
{
    &__offload_func_table, &__offload_func_table_end,
    &__offload_var_table, &__offload_var_table_end
};

#define DEBUG_LEVEL_OFFLOAD_MANAGER 1

void** offload_func_table;
uint32_t nb_offload_funcs;
void** offload_var_table;
uint32_t nb_offload_vars;

void
init_offload_manager(const void * offload_table)
{
    if (DEBUG_LEVEL_OFFLOAD_MANAGER > 0) {
        printf ("(target_table = %p { %p, %p, %p, %p })\n", offload_table,
	 ((void **) offload_table)[0], ((void **) offload_table)[1],
	 ((void **) offload_table)[2], ((void **) offload_table)[3]);
    }

    offload_func_table = ((void **) offload_table)[0];
    nb_offload_funcs   = ((uint64_t)((void **) offload_table)[1]
                        - (uint64_t)((void **) offload_table)[0]) / sizeof(void *);
    offload_var_table  = ((void **) offload_table)[2];
    nb_offload_vars    = ((uint64_t)((void **) offload_table)[3]
                        - (uint64_t)((void **) offload_table)[2]) / (sizeof(void *)*2);

    if (DEBUG_LEVEL_OFFLOAD_MANAGER > 0) {
        printf("nb_offload_funcs = %d\n", (int)nb_offload_funcs);
        printf("nb_offload_vars  = %d\n", (int)nb_offload_vars);
    }

    if (nb_offload_funcs) {
        if (DEBUG_LEVEL_OFFLOAD_MANAGER > 0) {
            printf("offload_func_table @%p\n", offload_func_table);
            for (int i = 0; i < nb_offload_funcs; i++)
                printf("Function %d @%p\n", i, offload_func_table[i]);
        }
    }

    if (nb_offload_vars) {
        if (DEBUG_LEVEL_OFFLOAD_MANAGER > 0) {
            printf("(offload_var_table = @%p\n", offload_var_table);
            for (int i = 0; i < nb_offload_vars; i++) {
                printf ("Variable %d @ %p ... %p\n", (int)i,
                    offload_var_table[2*i],
                    offload_var_table[2*i] + (uint64_t)offload_var_table[2*i+1]);
            }
        }
    }

    return;
}

void main(void)
{
    init_offload_manager(__OFFLOAD_TARGET_TABLE__);

    for(int i = 0; i < nb_offload_funcs; ++i){
        void (*test)(void) = offload_func_table[i];
        test();
    }
}

//gcc -c -shared -fPIC target_desc.c -o target_desc.o
