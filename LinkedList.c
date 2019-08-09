/*
 ============================================================================
 Name        : LinkedList2.c
 Author      : Jonathan karta.
 Version     :
 Description : Implementation of linked list
 ============================================================================
 */

/*
 ============================================================================
 Function    : LinkedList2.c
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


struct Node{
	int data;
	struct Node* next;
}typedef node_t;

struct List{
	struct Node* head;
	struct Node* tail;
}typedef list_t;

/*
 ============================================================================
 Function    : isEmpty
 Description : Check if the linkedlist is empty
 ============================================================================
 */

int isEmpty(struct List* list){
	if(list->head == NULL)
		return TRUE;
	return FALSE;
}

/*
 ============================================================================
 Function    : createEmptyList
 Description : Create empty list
 ============================================================================
 */

struct List createEmptyList(){
	struct List list;
	list.head = list.tail = NULL;
	return list;
}

/*
 ============================================================================
 Function    : createNewNode
 Description : Helper method to create new node and point him to the next
 	 	 	   Node.
 ============================================================================
 */

struct Node* createNewNode(struct Node* node, int data){
	struct Node* newNode = (struct Node*)calloc(1,sizeof(struct Node));
	newNode->data = data;
	newNode->next = node;
	return newNode;
}

/*
 ============================================================================
 Function    : insertNodeToHead
 Description : Insert node to the head of the linkedList cover the case of
 	 	 	   empty linkedlist.
 ============================================================================
 */

void insertNodeToHead(struct List* lst, int data){
	struct Node* newNode = createNewNode(lst->head,data);
	if(lst->head == NULL)
		lst->head = lst->tail = newNode;
	else
		lst->head = newNode;
}

/*
 ============================================================================
 Function    : insertNodeToTail
 Description : Insert node to the tail of the linkedList cover the case of
 	 	 	   empty linkedlist.
 ============================================================================
 */

void insertNodeToTail(struct List* lst, int data){
	struct Node* newNode = createNewNode(NULL, data);
	if(isEmpty(lst))
		lst->head = lst->tail = newNode;
	else{
		lst->tail->next = newNode;
		lst->tail = newNode;
	}

}

/*
 ============================================================================
 Function    : displayLinkedList
 Description : Display linkedlist inorder.
 ============================================================================
 */
void displayLinkedList(struct List* lst){
	struct Node* ptr = lst->head;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

/*
 ============================================================================
 Function    : displayLinkedListRev
 Description : Display linkedlist recursively in reverse order.
 ============================================================================
 */
void displayLinkedListRev(struct Node* first){
	struct Node* ptr = first;
	if(ptr != NULL){
		displayLinkedListRev(ptr->next);
		printf("%d ", ptr->data);
	}
}

/*
 ============================================================================
 Function    : insertByPosition
 Description : Insert Node to linkedlist by position cover all cases
 	 	 	   (head, tail, in between).
 ============================================================================
 */
void insertByPosition(struct List* lst, int data, int pos){
	if(pos == 0){
		struct Node* newNode = (struct Node*)calloc(sizeof(struct Node), 1);
		newNode->data = data;
		newNode->next = lst->head;
		lst->head = newNode;
	}else if (pos > 0){
		struct Node* p = lst->head;
		for(int i = 0; i < pos - 1 && p != NULL;i++ ){
			p = p->next;
		}
		if(p != NULL){
		struct Node* newNode = (struct Node*)calloc(sizeof(struct Node), 1);
		newNode->data = data;
		newNode->next = p->next;
		p->next = newNode;
		}

	}
}

/*
 ============================================================================
 Function    : countNodes
 Description : Count the number of nodes in given linkedlist
 ============================================================================
 */

int countNodes(struct List* lst){
	struct Node* p = lst->head;
	int counter = 0;
	while(p != NULL){
		counter++;
		p = p->next;
	}
	return counter;
}

int countNodesRe(struct Node* first){
	if (first == NULL){
		return 0;
	}
	return countNodesRe(first->next) + 1;
}

/*
 ============================================================================
 Function    : findNode
 Description : Find a node in given linkedlist by it's data
 ============================================================================
 */
struct Node* findNode(struct List* lst,int key){
	struct Node* p = lst->head;
	while(p != NULL){
		if( p->data == key){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

/*
 ============================================================================
 Function    : initializeLinkedList
 Description : Initialized a linkedlist with a given array.
 ============================================================================
 */
void initializeLinkedList(struct List* lst, int* arr, int size){
	for(int i = 0 ; i < size; i++){
		insertNodeToHead(lst,arr[i]);
	}
}

int main(void) {
	int arr[] = {10, 20, 30, 40, 50};
	struct List lst = createEmptyList();
	initializeLinkedList(&lst,arr,sizeof(arr)/ sizeof(int));
	displayLinkedList(&lst);
	printf("\n");
	insertNodeToHead(&lst,100);
	insertNodeToTail(&lst,44);
	displayLinkedList(&lst);
	printf("\nThe number of node in the linked list is %d\n",countNodes(&lst));

	return EXIT_SUCCESS;
}
