#include <stdio.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack) {
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->topIndex == -1) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void SPush(Stack* pstack, Data data) {
	(pstack->topIndex) ++;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack) {
	if (!SIsEmpty(&pstack)) {
		return (pstack->stackArr[pstack->topIndex]);
		//pstack->stackArr[pstack->topIndex] = NULL;
		(pstack->topIndex)--;
	}
	else {
		exit(-1);
	}
}
Data SPeek(Stack* pstack) {
	if (!SIsEmpty(&pstack)) {
		return (pstack->stackArr[pstack->topIndex]);
	}
	else {
		exit(-1);
	}
}