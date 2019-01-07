/****************************************
 File Name: ConstructBinaryTree.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Mon 07 Jan 2019 05:05:40 PM CST
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

struct BinaryTreeNode
{
	int			value;//节点的值
	BinaryTreeNode *pLeft;//左子树
	BinaryTreeNode *pRight;//右子树
};
BinaryTreeNode *ConstructCore(int *startPreorder,int *endPreorder,int startInorder,int *endInorder);

BinaryTreeNode *Construct(int *preorder,int *inorder,int length)
{
	if(preorder==nullptr||inorder==nullptr||length<=0)
		return nullptr;
	return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}
BinaryTreeNode *ConstructCore(int *startPreorder,int *endPreorder,int startInorder,int *endInorder)
{
	//前序遍历序列的第一个节点是根节点
	int rootValue=startPreorder[0];
	BinaryTreeNode *root=new BinaryTreeNode();//创建一个新树
	root->value=rootValue;
	root->pLeft=root->pRight=nullptr;

	if(startPreorder==endPreorder)
	{
		if(startInorder==endInorder&&*startPreorder==*startInorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}
	//在中序遍历中找到根节点的值
	int *rootInorder=startInorder;
	while(rootInorder<=endInorder&&*rootInorder!=rootValue)
		++rootInorder;
	if(rootInorder==endInorder&&*rootInorder!=rootValue)
		throw std::exception("Invalid input.");

	int leftLength=rootInorder-startInorder;
	int *leftPreorderEnd=startPreorder+leftLength;
	//构建左子树
	if(leftLength>0)
	{
		root->pLeft=ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1);
	}
	//构建右子树
	if(leftLength<endPreorder-startPreorder)
	{
		root->pRight=ConstructCore(leftPreorderEnd+1,endPreorder,rootInorder+1,endInorder);
	}
	return root;
}
