/*
 ============================================================================
 Name        : LinkedList.c
 Author      : Jonathan karta.
 Version     :
 Description : Implementation of linked list
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utility.h"

int main(void) {
	int arr[] = { 10, 20, 30, 40, 50 };
	int testValue = 100;
	struct List lst = createEmptyList();
	printf("Initialized linked list: \n");
	initializeLinkedList(&lst, arr, sizeof(arr) / sizeof(int));
	displayLinkedList(&lst);

	printf("Insert a value %d to the head of the list: \n",testValue);
	insertNodeToHead(&lst,testValue);
	displayLinkedList(&lst);

	printf("Insert a value %d to the tail of the list: \n", (testValue%21));
	insertNodeToTail(&lst,(testValue%21));
	displayLinkedList(&lst);

	printf("Insert a value %d in position Three : \n", testValue%7);
	insertByPosition(&lst,testValue%7, 3);
	displayLinkedList(&lst);
	printf("The middle point in the linked list is %d \n",midPoint(&lst));
	printf("The number of node in the linked list is %d\n",countNodes(&lst));
	printf("The maximum value in this linked list is %d\n",maxRecursive(lst.head));
	printf("Does the value %d is in the list? %s  \n",testValue%7,findNode(&lst,testValue%7)? "value exist.":"value isn't exists.");

	return EXIT_SUCCESS;
}
