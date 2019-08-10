#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utility.h"

/*
 ============================================================================
 Description : Check if the linked list is empty.
 ============================================================================
 */

int isEmpty(struct List *list) {
	if (list->head == NULL)
		return TRUE;
	return FALSE;
}

/*
 ============================================================================
 Description : Create empty list.
 ============================================================================
 */

struct List createEmptyList() {
	struct List list;
	list.head = list.tail = NULL;
	return list;
}

/*
 ============================================================================
 Description : Helper method to create new node and point him to the next
 	 	 	   Node if the list is empty then it will be pointed to null.
 ============================================================================
 */

struct Node* createNewNode(struct Node *node, int data) {
	struct Node *newNode = (struct Node*) calloc(1, sizeof(struct Node));
	newNode->data = data;
	newNode->next = node;
	return newNode;
}

/*
 ============================================================================
 Description : Insert node to the head of the linked list cover the case of
 	 	 	   empty linked list.
 ============================================================================
 */

void insertNodeToHead(struct List *lst, int data) {
	struct Node *newNode = createNewNode(lst->head, data);
	if (lst->head == NULL)
		lst->head = lst->tail = newNode;
	else
		lst->head = newNode;
}

/*
 ============================================================================
 Description : Insert node to the tail of the linkedList cover the case of
 	 	 	   empty linked list.
 ============================================================================
 */

void insertNodeToTail(struct List *lst, int data) {
	struct Node *newNode = createNewNode(NULL, data);
	if (isEmpty(lst))
		lst->head = lst->tail = newNode;
	else {
		lst->tail->next = newNode;
		lst->tail = newNode;
	}

}

/*
 ============================================================================
 Description : Display linked list in-order.
 ============================================================================
 */
void displayLinkedList(struct List *lst) {
	struct Node *ptr = lst->head;
	printf("Linked list: [");
	while (ptr != NULL) {
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	printf("||]");

	printf("\n");
}

/*
 ============================================================================
 Description : Display linked list recursively in reverse order.
 ============================================================================
 */
void displayLinkedListRev(struct Node *first) {
	struct Node *ptr = first;
	if (ptr != NULL) {
		displayLinkedListRev(ptr->next);
		printf("%d ", ptr->data);
	}
}

/*
 ============================================================================
 Description : Insert Node to linked list by position cover all cases
 (head, tail, in between).
 ============================================================================
 */
void insertByPosition(struct List *lst, int data, int pos) {
	if (pos == 0) {
		struct Node *newNode = (struct Node*) calloc(sizeof(struct Node), 1);
		newNode->data = data;
		newNode->next = lst->head;
		lst->head = newNode;
	} else if (pos > 0) {
		struct Node *p = lst->head;
		for (int i = 0; i < pos - 1 && p != NULL; i++) {
			p = p->next;
		}
		if (p != NULL) {
			struct Node *newNode = (struct Node*) calloc(sizeof(struct Node),
					1);
			newNode->data = data;
			newNode->next = p->next;
			p->next = newNode;
			if (p == lst->tail) {
				lst->tail = newNode;
			}

		}

	}
}

/*
 ============================================================================
 Description : Count the number of nodes in given linked list.
 ============================================================================
 */
int countNodes(struct List *lst) {
	struct Node *p = lst->head;
	int counter = 0;
	while (p != NULL) {
		counter++;
		p = p->next;
	}
	return counter;
}

/*
 ============================================================================
 Description : Count the number of nodes in given linked list recursively.
 ============================================================================
 */
int countNodesRe(struct Node *first) {
	if (first == NULL) {
		return 0;
	}
	return countNodesRe(first->next) + 1;
}

/*
 ============================================================================
 Description : Find a node in given linked list by it's data.
 ============================================================================
 */
struct Node* findNode(struct List *lst, int key) {
	struct Node *p = lst->head;
	while (p != NULL) {
		if (p->data == key) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

/*
 ============================================================================
 Description : Find a node in given linked list by it's data improve the version
 	 	 	   if we found the key then it will be moved to head of the list.
 ============================================================================
 */
struct Node* improvementFindeNode(struct List* lst, int key){
	struct Node* q, *p;
	p = lst->head;
	while(p != NULL){
		if(p->data == key){
			q->next = p->next;
			p->next = lst->head;
			lst->head = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}
/*
 ============================================================================
 Description : Find the maximum value in a given linked list
 ============================================================================
 */
int max(struct List* lst){
	struct Node* p = lst->head;
	int max = INT_MIN;
	while(p != NULL){
		if(p->data > max)
			max = p->data;
		p = p->next;
	}
	return max;
}
/*
 ============================================================================
 Description : Find the maximum value in a given linked list recursively
 ============================================================================
 */

int maxRecursive(struct Node* first){
	int max = INT_MIN;
	if(first == NULL)
		return max;
	max = maxRecursive(first->next);
	return first->data > max ? first->data : max;


}

/*
 ============================================================================
 Description : Find the middle node in a given linked list
 ============================================================================
 */
int midPoint(struct List* lst){
	struct Node* slow = lst->head;
	struct Node* fast = lst->head;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}

/*
 ============================================================================
 Description : Initialized a linked list with a given array.
 ============================================================================
 */
void initializeLinkedList(struct List *lst, int *arr, int size) {
	for (int i = 0; i < size; i++) {
		insertNodeToHead(lst, arr[i]);
	}
}


