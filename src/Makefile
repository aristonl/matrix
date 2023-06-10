PROG=matrix

CC=gcc
CFLAGS=-O2 -pedantic --std=c89 -g

$(PROG): main.o
	$(CC) -o $@ main.o $(CFLAGS)

clean:
	rm -rf *.o $(PROG)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

main.o: main.c
