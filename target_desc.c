extern const void *const __offload_funcs_end[];
extern const void *const __offload_vars_end[];

const void *const __offload_func_table[0]
    __attribute__ ((__used__, visibility ("hidden"),
	section (".gnu.offload_funcs"))) =
{ };

const void *const __offload_var_table[0]
    __attribute__ ((__used__, visibility ("hidden"),
	section (".gnu.offload_vars"))) =
{ };

const void *const __OFFLOAD_TARGET_TABLE__[]
    __attribute__ ((__used__, visibility ("hidden"))) =
{
    &__offload_func_table, &__offload_funcs_end,
    &__offload_var_table, &__offload_vars_end
};

#ifdef __cplusplus
extern "C"
#endif
void target_register_lib (const void *);

/* This should be called from every library with offloading.  */
#ifdef __cplusplus
extern "C"
#endif
void
target_register_lib (const void *target_table)
{
  //TRACE ("(target_table = %p { %p, %p, %p, %p })", target_table,
  //	 ((void **) target_table)[0], ((void **) target_table)[1],
  //	 ((void **) target_table)[2], ((void **) target_table)[3]);

  //last_loaded_library = (void *) target_table;
}

__attribute__((constructor))
static void
init (void)
{
    target_register_lib (__OFFLOAD_TARGET_TABLE__);
}

//gcc -c -shared -fPIC target_desc.c -o target_desc.o
