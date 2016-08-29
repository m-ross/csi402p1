# Author: Marcus Ross
#         MR867434

p1: clean main.o insert.o stats.o bst.o
	gcc -g main.o insert.o stats.o bst.o -o p1
main.o: main.c const.h bst.h proto.h
	gcc -c main.c
insert.o: insert.c bst.h proto.h
	gcc -c insert.c
stats.o: stats.c bst.h proto.h
	gcc -c stats.c
bst.o: bst.c bst.h
	gcc -c bst.c
clean:
	rm -f *.o core