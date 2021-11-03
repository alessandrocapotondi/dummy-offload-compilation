gcc -g -c -shared -fPIC target_desc.c -o target_desc.o
gcc -g -c -shared -fPIC target_descend.c -o target_descend.o
gcc -g -c -shared -fPIC target.c -o target.o

gcc -fPIC -Wl,target_desc.o target.o -Wl,target_descend.o -o target.so

# Disassemble
objdump -SD target.so > target.S

# Show Simbols
nm -S target.so
