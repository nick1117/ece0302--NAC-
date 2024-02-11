#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() 
{
  arraySize = 0;
  ListArray = new T[arraySize];
  //delete [] ListArray;
}

template <typename T>
ArrayList<T>::~ArrayList() 
{ 
  arraySize = 0;
  delete [] ListArray;
  ListArray = nullptr;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs)
{
  arraySize = rhs.arraySize;
  if (arraySize == 0)
  {
    ListArray = nullptr;
  }
  else 
  {
    ListArray = new T[arraySize];
  }  
  std::copy(rhs.ListArray, (rhs.ListArray + rhs.arraySize), ListArray);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs){
  swap(rhs);
  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList& rhs) 
{
  std::swap(ListArray, rhs.ListArray);
  std::swap(arraySize, rhs.arraySize);
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept {
  if(arraySize == 0){
    return true;
  }
  return false;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept {
  return arraySize;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  if(position < 0 || position > arraySize){
    return false;
  }
  arraySize++;
  T* DummyArray = new T[arraySize];
  size_t i;

  for (i = 0; i < position; i++) //note
  {
    DummyArray[i] = ListArray[i];
  }

  DummyArray[position] = item; //i = 5

  for (i = position+1; i < (arraySize); i++)
  {
    DummyArray[i] = ListArray[i-1];
  }
  delete [] ListArray;
  ListArray = DummyArray;
  DummyArray = nullptr;
  
  return true;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  if(position < 0 || position >= arraySize){
    return false;
  }

  arraySize--;
  T* DummyArray = new T[arraySize];
  size_t i;

  for (i = 0; i < position; i++) //note
  {
    DummyArray[i] = ListArray[i];
  }
  for (i = position; i < (arraySize); i++)
  {
    DummyArray[i] = ListArray[i+1];
  }
  
  delete [] ListArray;
  ListArray = DummyArray;
  //delete DummyArray;
  DummyArray = nullptr;

  return true;;
}

template <typename T>
void ArrayList<T>::clear() 
{
  arraySize = 0;
  //delete ListArray;
  ListArray = nullptr;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  if(position > arraySize || position < 0){
    return T();
  }
  return ListArray[position];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) 
{
  if(position > arraySize || position < 0){
    
  }
  else{
  ListArray[position] = newValue;
  }
}



