gcc -c -shared -fPIC target_desc.c -o target_desc.o
gcc -c -shared -fPIC target_descend.c -o target_descend.o
gcc -c -shared -fPIC target.c -o target.o

gcc -Wl,target_desc.o target.o -Wl,target_descend.o -o target.so
