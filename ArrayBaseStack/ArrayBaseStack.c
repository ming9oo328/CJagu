#include <stdio.h>
#include <stdlib.h>
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
	pstack->topIndex +=1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		exit(-1);
	}
	else {
		int tmp = pstack->topIndex;
		pstack->topIndex-=1;
		return(pstack->stackArr[tmp]);
	}
}
Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		exit(-1);
	}
	else {
		return(pstack->stackArr[pstack->topIndex]);
	}
}