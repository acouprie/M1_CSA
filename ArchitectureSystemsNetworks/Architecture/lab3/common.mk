#PREFIX=arm-linux-gnueabi-
PREFIX=arm-none-eabi-
CC=$(PREFIX)gcc
CFLAGS=-I .. -Wall -g  -fno-stack-protector
LDFLAGS=-nostartfiles -static -Ttext=0
BSIM=../../bin/boardsim

all: $(WORK).elf

$(WORK).elf: $(WORK).o
	$(CC) $(CFLAGS) -o $@ ../startup.s $< $(LDFLAGS)

CMD=$(BSIM) $(BOARD) $(WORK).elf
run: $(WORK).elf
	$(CMD)

clean:
	-rm -rf $(WORK).elf *.o *.bsim

debug:
	gdb --args $(CMD)

mdebug:
	valgrind $(CMD)
