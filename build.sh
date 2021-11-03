gcc -g -c -shared -fPIC target_desc.c -o target_desc.o
gcc -g -c -shared -fPIC target_descend.c -o target_descend.o
gcc -g -c -shared -fPIC target.c -o target.o

gcc -g -fPIC -Wl,target_desc.o target.o -Wl,target_descend.o -o target.elf

# Disassemble
objdump -SD target.elf > target.S

# Show Simbols
nm -S target.elf

# Remove useless sections and transform it to loadable binary
objcopy --only-section=.gnu.offload.funcs --only-section=.gnu.offload.vars -O binary target.elf target.bin
