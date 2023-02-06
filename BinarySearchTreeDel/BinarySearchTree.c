#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

// BST의 생성 및 초기화
void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst) {
	return getData(bst);
}

// BST를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode** pRoot, BSTData data) {
	BTreeNode* pNode = NULL;    // parent node
	BTreeNode* cNode = *pRoot;    // current node
	BTreeNode* nNode = NULL;    // new node

	while (cNode != NULL)
	{
		if (data == GetData(cNode)) {
			return;
		}
		pNode = cNode;
		if (GetData(cNode) > data) {
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}
	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != NULL) {
		if (data < GetData(pNode)) {
			MakeLeftSubTree(pNode, nNode);
		}
		else {
			MakeRightSubTree(pNode, nNode);
		}
	}
	else {
		*pRoot = nNode;
	}

}

// BST를 대상으로 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target) {
	BTreeNode* cNode = bst;    // current node
	BSTData cd;    // current data

	while (cNode != NULL)
	{
		cd = GetData(cNode);
		if (target == cd) {
			return cNode;
		}
		else if (target < cd) {
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}
	return NULL;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target) {
	BTreeNode* pVRoot = MakeBTreeNode(); // 가상 루트 노드;

	BTreeNode* pNode = pVRoot;    // parent node
	BTreeNode* cNode = *pRoot;    // current node
	BTreeNode* dNode;    // delete node

	ChangeRightSubTree(pVRoot, *pRoot);

	while (cNode != NULL && GetData(cNode)!= target) {
		pNode = cNode;
		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)
		return NULL;
	dNode = cNode;

	//삭제할 노드가 단말노드인 경우
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	//삭제할 노드가 하나의 자식 노드를 갖는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) != NULL) {
		BTreeNode* dcNode=NULL;

		if (GetRighttSubTree(dNode) != NULL) {
			dcNode = GetRightSubTree(dNode);
		}
		else if (GetLeftSubTree(pNode) == dNode) {
			dcNode = GetRightSubTree(dNode);
		}

		if (GetLeftSubTree(pNode) == dNode) {
			ChangeLeftSubTree(pNode, dcNode);
		}
		else {
			ChangeRightSubTree(pNode, dcNode);
		}
	}

	//삭제할 노드가 자식노드를 2개 모두 갖는 경우
	else {
		BTreeNode* mNode = GetRightSubTree(dNode);
		BTreeNode* mpNode = dNode;
		int delData;

		while (GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));
		if (GetLeftSubTree(mpNode) == mNode) {
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		}
		else {
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		}
		dNode = mNode;
		SetData(dNode, delData);
	}
	if (GetRightSubTree(pVRoot) != *pRoot) {
		*pRoot = GetRightSubTree(pVRoot);
	}

	free(pVRoot);
	return dNode;
}