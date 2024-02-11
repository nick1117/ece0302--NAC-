#include "linked_list.hpp"
#include <iostream>


template<class T>
Node<T>* LinkedList<T>::getPointerTo(std::size_t position) const 
{
  //check if position is valid
  if(position < itemCount){
    //create ptr to node
    Node<T>* curPtr;
    //set to the head ptr
    curPtr = headPtr;
    //loop through until reaches position and move the ptr along
    for(std::size_t i = 0; i < position; i++){
      curPtr = curPtr->getNext();
    }
    return curPtr; //return that pointer
  }
}


template <typename T>
LinkedList<T>::LinkedList()
{
  //TODO
  headPtr = nullptr;
  itemCount = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  //TODO

  headPtr = nullptr;
  itemCount = 0;
  
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  //TODO
  //If the headptr to x is null then set the list head ptr to null
  if(x.headPtr == nullptr){
    headPtr = nullptr;
    itemCount = 0;
  }
  //If not...
  else{
    //Set item count and create and set a ptr to the Headptr of x
    itemCount = x.itemCount;
    Node<T>* xPtr;
    xPtr = x.headPtr;
    //Set the item where the head pointer for x is pointing at to our list
    headPtr = new Node<T>();
    headPtr->setItem(xPtr->getItem());
    //have the pointer point to the next position of X
    xPtr = xPtr->getNext();
    //create a dummyPtr and set it to where head ptr is pointer to
    Node<T>* dummyPtr;
    dummyPtr = headPtr;
    
    while(xPtr != nullptr){ //loop until we reach the end of the pointer to x
      //store the value of the item that the pointer to x is now pointing at
      T NodeValue = xPtr->getItem();
      //create a pointer and have it point to a new node contructed with the new value
      Node<T>* tempPtr;
      tempPtr = new Node<T>(NodeValue);
      //set the next node in reference to our lists headerpointer as the value of the node
      dummyPtr->setNext(tempPtr);
      //shift both pointers
      xPtr = xPtr->getNext();
      dummyPtr = dummyPtr->getNext();
    }
  }

}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  //TODO
  swap(x);
  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  //TODO
  std::swap(itemCount, x.itemCount);
  std::swap(headPtr, x.headPtr);
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  //TODO
  if(itemCount == 0){
    return true;
  }
  return false;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  //TODO
  return itemCount;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  //TODO
  //check to see if position is valid - true if it is, false if not
  bool ableToInsert = (position >= 0) && (position <= itemCount);

  if(ableToInsert)
  {
    //create a pointer to a node initialized with item
    Node<T>* newNodePtr = new Node<T>(item);
    //if it is the first position
    if(position == 0)
    {
      //have the new node ptr point to the next pointafter the head ptr
      newNodePtr->setNext(headPtr);
      //set head ptr to newnodeptr
      headPtr = newNodePtr;
    }
    else //if it is not the first position
    {
      //create a ptr to node position -1
      Node<T>* prevPtr = getPointerTo(position-1);
      //have newNodePtr point to the position which is the node after the node prevPtr is pointing to
      newNodePtr->setNext(prevPtr->getNext());
      //have the prevPtr point to the newNode ptr next in line
      prevPtr->setNext(newNodePtr);
    }
    //increment item cout
    itemCount++;

  }
  //return true if value
  return ableToInsert;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //check if position is valid
  bool ableToRemove = (position >= 0) && (position <= itemCount);

  if(ableToRemove)
  {
    //create a ptr which will point to what we want to delete
    Node<T>* DeletePtr = nullptr;
    if(position == 0) //check if edge case
    {
      //set the delete ptr to headptr and move head ptr by 1
      DeletePtr = headPtr;
      headPtr = headPtr->getNext();
    }
    else
    {
      //create a prevpointer pointing to poistion -1
      Node<T>* prevPtr = getPointerTo(position-1);
      //set the delete pointer to where position is
      DeletePtr = prevPtr->getNext();
      //set the prevPtr to point to the point after position
      prevPtr->setNext(DeletePtr->getNext());
    }
    //delete the node and decrease item count by 1
    DeletePtr->setNext(nullptr); 
    delete DeletePtr; 
    DeletePtr = nullptr; 
    itemCount--;

  }
  return ableToRemove;
}

template <typename T>
void LinkedList<T>::clear()
{
  //clear header ptr and set item count to 0
  headPtr = nullptr;
  itemCount = 0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //check if position is valid
  if((position >= 0) && (position < itemCount))
  {
    //get a pointer to where position is
    Node<T>* newNodePtr = getPointerTo(position);
    //return that item
    return newNodePtr->getItem();
  }
  return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //check if position valid
  if((position >= 0) && (position <= itemCount))
  {
    //create a ptr with the value of newValue
    Node<T>* newNodePtr = new Node<T>(newValue);
    if(position == 0) //check edge case
    {
      //set this ptr to one after haeder ptr
      newNodePtr->setNext(headPtr);
      //set header pointer to that ptr
      headPtr = newNodePtr;
    }
    else
    {
      //cerate pointer pointing to position before
      Node<T>* prevPtr = getPointerTo(position-1);
      //have newNodePtr point to the position which is the node after the node prevPtr is pointing to
      newNodePtr->setNext(prevPtr->getNext());
      //have the prevPtr point to the newNode ptr next in line
      prevPtr->setNext(newNodePtr);
    }

  }
  
}


