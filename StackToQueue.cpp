/****************************************
 File Name: StackToQueue.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Mon 07 Jan 2019 09:20:15 PM CST
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class cQueue
{
public:
	cQueue(void);
	~cQueue(void);

	void appendTail(const T &node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T> cQueue<T>::cQueue(void)
{
}
template <typename T> cQueue<T>::~cQueue(void)
{
}
//在队列中插入一个元素，把入队列的元素放入stack1中，
template <typename T> 
void cQueue<T>::appendTail(const T&element)
{
	stack1.push(element);
}
//元素出队列时，要把stack1中的元素放入stack2中然后取出stack2的栈顶//元素即可，如果stack2不为空直接出栈即可。
template <typename T>
T cQueue<T>::deleteHead()
{
	if(stack2.size()<=0)
	{
		while(stack1.size()>0)
		{
			T&data=stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if(stack2.size()==0)
		throw new exception("queue is empty");
	T head=stack2.top();
	stack2.pop();
}
