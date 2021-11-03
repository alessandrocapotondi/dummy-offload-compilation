const void *const __offload_func_table_end[0]
    __attribute__ ((__used__, visibility ("hidden"),
    section (".gnu.offload.funcs"))) = { };

const void *const __offload_var_table_end[0]
    __attribute__ ((__used__, visibility ("hidden"),
	section (".gnu.offload.vars"))) = { };

//gcc -c -shared -fPIC target_offloadend.c -o target_offloadend.o
