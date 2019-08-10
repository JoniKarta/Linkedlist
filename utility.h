/*
 * utility.h
 *
 *  Created on: 10 Aug 2019
 *      Author: jonubuntu
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#define TRUE 1
#define FALSE 0

struct Node {
	int data;
	struct Node *next;
}typedef node_t;

struct List {
	struct Node *head;
	struct Node *tail;
}typedef list_t;

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utility.h"

/*
 ============================================================================
 Description : Check if the linked list is empty.
 ============================================================================
 */
int isEmpty(struct List *list);


/*
 ============================================================================
 Description : Create empty list.
 ============================================================================
 */
struct List createEmptyList();


/*
 ============================================================================
 Description : Helper method to create new node and point him to the next
 	 	 	   Node if the list is empty then it will be pointed to null.
 ============================================================================
 */
struct Node* createNewNode(struct Node *node, int data);


/*
 ============================================================================
 Description : Insert node to the head of the linked list cover the case of
 	 	 	   empty linked list.
 ============================================================================
 */
void insertNodeToHead(struct List *lst, int data);


/*
 ============================================================================
 Description : Insert node to the tail of the linkedList cover the case of
 	 	 	   empty linked list.
 ============================================================================
 */
void insertNodeToTail(struct List *lst, int data);


/*
 ============================================================================
 Description : Display linked list in-order.
 ============================================================================
 */
void displayLinkedList(struct List *lst);


/*
 ============================================================================
 Description : Display linked list recursively in reverse order.
 ============================================================================
 */
void displayLinkedListRev(struct Node *first);


/*
 ============================================================================
 Description : Insert Node to linked list by position cover all cases
 (head, tail, in between).
 ============================================================================
 */
void insertByPosition(struct List *lst, int data, int pos);


/*
 ============================================================================
 Description : Count the number of nodes in given linked list.
 ============================================================================
 */
int countNodes(struct List *lst);


/*
 ============================================================================
 Description : Count the number of nodes in given linked list recursively.
 ============================================================================
 */
int countNodesRe(struct Node *first);


/*
 ============================================================================
 Description : Find a node in given linked list by it's data.
 ============================================================================
 */
struct Node* findNode(struct List *lst, int key);


/*
 ============================================================================
 Description : Find a node in given linked list by it's data improve the version
 	 	 	   if we found the key then it will be moved to head of the list.
 ============================================================================
 */
struct Node* improvementFindeNode(struct List* lst, int key);


/*
 ============================================================================
 Description : Find the maximum value in a given linked list
 ============================================================================
 */
int max(struct List* lst);


/*
 ============================================================================
 Description : Find the maximum value in a given linked list recursively
 ============================================================================
 */
int maxRecursive(struct Node* first);


/*
 ============================================================================
 Description : Find the middle node in a given linked list
 ============================================================================
 */
int midPoint(struct List* lst);


/*
 ============================================================================
 Description : Initialized a linked list with a given array.
 ============================================================================
 */
void initializeLinkedList(struct List *lst, int *arr, int size);



#endif /* UTILITY_H_ */
