CC= gcc

all: LinkedList

LinkedList:
	$(CC) -o linlst LinkedList.c

clean:
	rm -f linlst
	