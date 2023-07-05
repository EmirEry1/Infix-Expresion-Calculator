
#ifndef __STACK__
#define __STACK__

#include "StackItem.h"
class Stack
{
public:
	Stack();
	~Stack();
	void push(StackItem*);
	StackItem* pop();
	StackItem* top();
	bool isEmpty();
private:
	StackItem* head;
	StackItem* prev;

};

#endif