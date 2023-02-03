#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
#include "BinaryTreeTraverse.h"

void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNOdeData(BTreeNode* bst) {
	return getData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data) {
	BTreeNode* pNode = NULL;
	BTreeNode* cNode = *pRoot;
	BTreeNode* nNode = NULL;

	while (cNode!=NULL) {
		pNode = cNode;

		if (cNode->data < data)
		    cNode = GetRightSubTree(cNode);

		else if (cNode->data > data)
		    cNode = GetLeftSubTree(cNode);
	}

	nNode = MakeBTreeNode;
	SetData(nNode, data);

	if (GetData(pNode) < data)
		MakeRightSubTree(pNode, nNode);
	else if (GetData(pNode)> data)
		MakeLeftSubTree(pNode, nNode);
}


BTreeNode* BSTSearch(BTreeNode* bst, BSTData target) {

}
