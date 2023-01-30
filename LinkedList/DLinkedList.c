#include <stdio.h>
#include "DLinkedLIst.h"

void ListInit(List* plist) {
	plist->head->next = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}