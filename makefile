AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
CC=arm-none-eabi-gcc

ASFLAGS=-mthumb
CFLAGS= -std=gnu11 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2
LDFLAGS=-z muldefs

OBJ := main.o cb_execute.o sub_bg_init.o task_loader.o tiles_load.o string_print.o decrypt_and_print.o load_icons.o task_02.o)
OBJ := $(addprefix build/,$(OBJ))

all: main.bin
	@:

main.bin: $(OBJ)
	$(LD) $(LDFLAGS) -T linker.lsc -T bpre.ld -o build/linked $(OBJ)
	$(OBJCOPY) -O binary build/linked $@

build/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ $<

build/%.o: src/%.asm
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) build/linked
