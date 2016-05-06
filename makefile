AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
CC=arm-none-eabi-gcc

ASFLAGS=-mthumb
CFLAGS= -std=gnu11 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2
LDFLAGS=-z muldefs

all: launch cb_execute sub_bg_init task_loader tiles_load string_print decrypt_and_print load_icons task_02
	$(LD) $(LDFLAGS) -T linker.lsc -T bpre.ld -o "build\linked.o" "build\main.o" "build\cb_execute.o" "build\sub_bg_init.o" "build\task_loader.o" "build\tiles_load.o" "build\string_print.o" "build\decrypt_and_print.o" "build\load_icons.o" "build\task_02.o"
	$(OBJCOPY) -O binary "build\linked.o" "main.bin"
	
launch:
	$(CC) $(CFLAGS) -c "src\main.c" -o "build\main.o"
	
cb_execute:
	$(CC) $(CFLAGS) -c "src\cb_execute.c" -o "build\cb_execute.o"

sub_bg_init:
	$(CC) $(CFLAGS) -c "src\sub_bg_init.c" -o "build\sub_bg_init.o"
	
task_loader:
	$(CC) $(CFLAGS) -c "src\task_loader.c" -o "build\task_loader.o"
	
tiles_load:
	$(CC) $(CFLAGS) -c "src\tiles_load.c" -o "build\tiles_load.o"
	
string_print:
	$(CC) $(CFLAGS) -c "src\string_print.c" -o "build\string_print.o"
	
decrypt_and_print:
	$(CC) $(CFLAGS) -c "src\decrypt_and_print.c" -o "build\decrypt_and_print.o"
	
load_icons:
	$(AS) $(ASFLAGS) -c "src\load_icons.asm" -o "build\load_icons.o"
	
task_02:
	$(CC) $(CFLAGS) -c "src\task_02.c" -o "build\task_02.o"
	
clean:
	rm build\*.*