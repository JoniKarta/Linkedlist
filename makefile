CC= gcc

all: LinkedList

LinkedList:
	$(CC) -o linlst LinkedList.c utility.c

clean:
	rm -f linlst
	