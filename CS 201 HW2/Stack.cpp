#include "Stack.h"

Stack::Stack() {
	
}


bool Stack::isEmpty() {
	return head == NULL;
}
StackItem* Stack::pop() {
	
	StackItem *temp1 = head;
	
	
		head = head->next;
		delete temp1;
	
	

	return NULL;
	
}
void Stack::push(StackItem* newItem) {
	if (head == NULL) {
		head = newItem;
	}
	else {
		//TODO: There may be some bugs here. Fix them.
		newItem->next = head;
		head = newItem;
	}
}
StackItem* Stack::top() {
	return head;
}
Stack::~Stack() {
	
	while (head->next!=NULL) {
		StackItem *dItem = head;
		head = head->next;
		delete dItem;
	}
	if (head != NULL) {
		delete head;
	}
		
	
}