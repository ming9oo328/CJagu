#include <stdio.h>
#include "DBLinkedList.h"

void ListInit(List* plist) {
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if (plist->head != NULL) {
		newNode->next = plist->head->next;
		plist->head->prev = newNode;
	}
	newNode->prev = NULL;
	plist->head= newNode; //헤드를 처음으로 위치를 바꿔준다

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata) {

}

int LNext(List* plist, Data* pdata) {

}

int LPrevious(List* plist, Data* pdata) {

}

int LCount(List* plist) {
	plist->numOfData
}
