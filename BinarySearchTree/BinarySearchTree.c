#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
#include "BinaryTreeTraverse.h"

void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst) {
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data) {
	BTreeNode* pNode = NULL;
	BTreeNode* cNode = *pRoot;
	BTreeNode* nNode = NULL;

	while (cNode!=NULL) {

		if (GetData(cNode) == data)
			return;
		pNode = cNode;
		if (GetData(cNode) < data)
			cNode = GetRightSubTree(cNode);

		else if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);

	}
	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != NULL) {
		if (GetData(pNode) < data)
			MakeRightSubTree(pNode, nNode);
		else if (GetData(pNode) > data)
			MakeLeftSubTree(pNode, nNode);
	}
	else
		*pRoot = nNode;
}


BTreeNode* BSTSearch(BTreeNode* bst, BSTData target) {
	BTreeNode* cNode = bst;
	BTData cd;

	while (cNode != NULL) {
		cd = GetData(cNode);

		if (cd == target)
			return cNode;
		else if (cd < target)
			cNode = GetRightSubTree(cNode);
		else if (cd > target)
			cNode = GetLeftSubTree(cNode);
	}
}
