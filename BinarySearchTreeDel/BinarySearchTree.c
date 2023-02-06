#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

// BST�� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst) {
	return getData(bst);
}

// BST�� ������� ������ ����(����� �������� ����)
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

// BST�� ������� ������ Ž��
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
	BTreeNode* pVRoot = MakeBTreeNode(); // ���� ��Ʈ ���;

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

	//������ ��尡 �ܸ������ ���
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	//������ ��尡 �ϳ��� �ڽ� ��带 ���� ���
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

	//������ ��尡 �ڽĳ�带 2�� ��� ���� ���
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