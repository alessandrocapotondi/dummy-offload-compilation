void __attribute__ ((__used__, section (".gnu.offload_funcs")))
    test(void)
{
    return;
}

void main(void)
{}

//gcc -c -fPIC -shared offload.c -o offload.o

//Link Everything
//gcc -fPIC -Wl,target_desc.o offload.o -Wl,target_offloadend.o -o offload.so
