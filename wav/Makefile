PROG=wav

CC=gcc
CFLAGS=-O2 -pedantic --std=c89 -g

$(PROG): main.o
	$(MAKE) -C lib
	$(CC) -o $@ main.o lib/wav.o $(CFLAGS)

clean:
	rm -rf *.o $(PROG)
	$(MAKE) -C lib clean

.c.o:
	$(CC) $(CFLAGS) -c $*.c

main.o: main.c lib/wav.h