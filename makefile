.SUFFIXES:	.c .o
CC = gcc
CFLAGS = -g

.c.o:
	$(CC) $(CFLAGS) -c $<

p3:	main.o initialize.o helpers.o
	gcc main.o initialize.o helpers.o  -o p3

main.o: main.c database.h 
initialize.o: initialize.c database.h
helpers.o: helpers.c

clean:
	rm -f core p2 *.o
