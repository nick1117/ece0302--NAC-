#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(LinkedList<T> unsorted_list) 
{
  // TODO
  //bubble sort
  int length = LinkedList<T>::getLength();
  int swap;
	do{
		swap = 0;
		for (size_t i = 0; i < length - 1; i++)
		{
			for (size_t j = 0; j < length - 1; j++)
			{
				T index = LinkedList<T>::getEntry(i);
				T indexNext = LinkedList<T>::getEntry(i+1);
				if(index > indexNext){
					LinkedList<T>::setEntry(i,indexNext);
					LinkedList<T>::setEntry(i+1,index);
					swap++;
				}
			}
		}
	}while(swap>0);
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(SortedLinkedList<T> x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength() const noexcept
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  // TODO
  int length = LinkedList<T>::getLength();
  int i;
  if (length == 0){
    LinkedList<T>::insert(0, item);
  }
  else{
    for (i = 0; i < length; i++)
    {
      if(LinkedList<T>::getEntry(i)>item){
        break;
      }
    }
    LinkedList<T>::insert(i, item);
  }
  
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  // TODO
  int length = LinkedList<T>::getLength();

  for (size_t i = 0; i < length; i++)
  {
    if(LinkedList<T>::getEntry(i)==item){
      LinkedList<T>::remove(i);
      break;
    }
  }
  
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  // TODO
  LinkedList<T>::remove(position);
  
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position) const
{
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& item)
{
  // TODO
  int length = LinkedList<T>::getLength();

  for (size_t i = 0; i < length; i++)
  {
    if(LinkedList<T>::getEntry(i)==item){
      return i; 
    }
  }
  return -1;
}
