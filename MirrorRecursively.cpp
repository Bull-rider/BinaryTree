/****************************************
 File Name: MirrorRecursively.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Thu 10 Jan 2019 04:21:24 PM CST
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
//执行二叉树的镜像转换
void MirrorRecursively(BinaryTreeNode *pNode)
{
	if((pNode==NULL)||(pNode->m_pLeft=NULL&&pNode->m_pRight))
		return;
	BinaryTreeNode *pTemp=pNode->m_pLeft;
	pNode->m_pLeft=pNode->m_pRight;
	pNode->m_pRight=pTemp;
	if(pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);
	if(pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);
}
//输出
void MirrorIteratively(BinaryTreeNode *pRoot)
{
	if(pRoot==nullptr)
		return;
	std::stack<BinaryTreeNode *> stackTreeNode;
	stackTreeNode.push(pRoot);
	while(stackTreeNode.size()>0)
	{
		BinaryTreeNode *pNode=stackTreeNode.top();
		stackTreeNode.pop();

		BinaryTreeNode *pTemp=pNode->m_pLeft;
		pNode->m_pLeft=pNode->m_pRight;
		pNode->m_pRight=pTemp;

		if(pNode->m_pLeft)
			stackTreeNode.push(pNode->m_pLeft);
		if(pNode->m_pRight)
			stackTreeNode.push(pNode->m_pRight);
	}
}
