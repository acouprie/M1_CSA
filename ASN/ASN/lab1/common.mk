#PREFIX=arm-linux-gnueabi-
PREFIX=arm-none-eabi-
CC=$(PREFIX)gcc
CFLAGS=-I .. -Wall -g -march=armv4t
LDFLAGS=-nostartfiles -static -Ttext=0
BSIM=../../bin/boardsim

all: $(WORK).elf

$(WORK).elf: $(WORK).o
	$(CC) $(CFLAGS) -o $@ ../startup.s $< $(LDFLAGS)

run: $(WORK).elf
	$(BSIM) $(BOARD) $(WORK).elf

clean:
	-rm -rf $(WORK).elf *.o *.bsim
