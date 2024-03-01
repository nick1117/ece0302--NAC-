
/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() 
{
	headPtr = nullptr;
	currentSize = 0;
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	clear();
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	if(currentSize != 0)
		return false;
	return true;
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* tempPtr;
	tempPtr = nullptr;
	tempPtr = new Node<ItemType>(newItem, headPtr);
	headPtr = tempPtr;
	currentSize++;
	
	return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	if(currentSize == 0 || headPtr == nullptr){
		throw logic_error("Size of stack is null");
	}
	ItemType returnItem;
	returnItem = headPtr->getItem();
	
	return returnItem;
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	if(currentSize == 0 || headPtr == nullptr){
		return false;
	}
	Node<ItemType>* tempPtr;
	tempPtr = headPtr;
	headPtr = headPtr->getNext();
	delete tempPtr;
	tempPtr = nullptr;
	currentSize--;

	return true;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	while(!isEmpty()){
		pop();
	}
}  // end clear

