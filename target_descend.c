const void *const __offload_funcs_end[0]
    __attribute__ ((__used__, visibility ("hidden"),
    section (".gnu.offload_funcs"))) = { };

const void *const __offload_vars_end[0]
    __attribute__ ((__used__, visibility ("hidden"),
	section (".gnu.offload_vars"))) = { };

//gcc -c -shared -fPIC target_offloadend.c -o target_offloadend.o
