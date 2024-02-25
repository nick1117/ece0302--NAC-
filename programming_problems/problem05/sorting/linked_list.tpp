#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList() : headPtr(nullptr), itemCount(0)
{
  
} //end default constructor

template <typename T>
LinkedList<T>::~LinkedList()
{
  //empty the existing linked list
	clear();
} // end destructor

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  itemCount = x.itemCount;
  Node<T>* origPtr = x.headPtr;
	//check if original is empty, if so make copy empty
	if (origPtr == nullptr) 
		headPtr = nullptr;
	else {
		//make copy of first node
		headPtr = new Node<T>();
		headPtr -> setItem(origPtr -> getItem());
		//copy remaining nodes
		Node<T>* newPtr = headPtr; 
		origPtr = origPtr -> getNext();
		while (origPtr != nullptr) {
			//get next item in list, and make new node with item, and link
			T nextItem = origPtr -> getItem();
			Node<T>* newNodePtr = new Node<T>(nextItem);
			newPtr -> setNext(newNodePtr);
			//shift pointers
			newPtr = newPtr -> getNext();
			origPtr = origPtr -> getNext();
		} // end while
	} // end if
} // end copy

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
	swap(x);
	return *this;
} // end = operator

template<typename T>
void LinkedList<T>::swap(LinkedList<T>& x) 
{
	std::swap(itemCount, x.itemCount);
	std::swap(headPtr, x.headPtr);
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  return (itemCount == 0);
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  return itemCount;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
	if ((position >= 0) && (position <= itemCount)) {
		Node<T>* newNodePtr = new Node<T>(item);
		if (position == 0) {
			newNodePtr -> setNext(headPtr);
			headPtr = newNodePtr;
		}
		else {
			Node<T>* prevPtr = getNodeAt(position-1);
			newNodePtr -> setNext( prevPtr -> getNext() );
			prevPtr -> setNext( newNodePtr );
		}
		itemCount++;
		return true;
	} 
	return false;
} //end insert

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
	if ((position >= 0) && (position < itemCount)) {
		Node<T>* curPtr = nullptr;
		if (position == 0) {
			curPtr = headPtr;
			headPtr = headPtr -> getNext();
		}
		else {
			Node<T>* prevPtr = getNodeAt(position - 1);
			curPtr = prevPtr -> getNext();
			prevPtr -> setNext( curPtr -> getNext() );
		}
		delete curPtr;
		itemCount--;
		return true;
	} 
	return false;
} //end remove;

template <typename T>
void LinkedList<T>::clear()
{
	while (!isEmpty())
	remove(0);
} // end clear

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
	if ((position >= 0) && (position < itemCount)) 
	{
		return getNodeAt(position)->getItem();
	}
	else throw(std::range_error("error in range"));
} // end getEntry

template <typename T>
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
	//This traverses the list and returns the node at position
	Node<T>* curPtr = headPtr;
	for (std::size_t next = 0; next < position; next++) {
		curPtr = curPtr -> getNext();
	}
	return curPtr;
} //end getNodeAt

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
	if((position >= 0) && (position < itemCount))
	getNodeAt(position)->setItem(newValue);
} //end setEntry
