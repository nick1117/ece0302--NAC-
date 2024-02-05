#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() 
{
  size = 0;
  //limit = 0;
  empty = true;
}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T>& x)
{
  size = x.size;
  //limit = 0;
  Bag = new T[size];
  for (size_t i = 0; i < size; i++)
  {
    *(Bag + i) = *(x.Bag + i);
  }
  
  
  //std::swap(Bag, x.Bag);
  //std::swap(size, x.size);
}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  size = 0;
  empty = true;
  //delete[] Bag; //need to remove this to be able to run tests???
  Bag = nullptr;
  size = 0;

}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{  
  swap(x);
  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x) {
  std::swap(Bag, x.Bag);
  std::swap(size, x.size);
}


template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  //increase the size of bag
  size = size + 1;
  Bag[size] = item; //add item to bag
  empty = false; //bag is not empty
  //check to see that the item was added
  if(Bag[size] == item){
    //if success return true
    return true;
  }
  else{
    //if not return false
    return false;
  }
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  bool found = false;
  size_t i;
  for (i = 0; i < size; i++)
  {
    //if the item is detected, break the loop
    if(Bag[i] == item){
      found = true;
      break;
    }
  }
  if(found == false){ //if item not found, return false
    return false; 
  }
  //decrease the size by 1
  size = size - 1; 
  //check to see the status of empty
  if(size == 0){
    empty = true;
  }
  else{
    empty = false;
  }
  //pick back up at the same point but move the array values down one
  for (size_t j = i; j < size; j++)
  {
    Bag[j] = Bag[j+1];
  } 
  
  return true;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return empty; //return if bag is empty or not
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return size; //return the size of Bag
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  //loop through bag
  for (size_t i = 0; i < size; i++)
  {
    //if bag at the index matches the passed item, return true
    if(Bag[i]==item){
      return true;
    }
  }
  return false;
}

template<typename T>
void DynamicBag<T>::clear()
{
  //clear dynamic data and set values to zero
  for (size_t i = 0; i < size; i++)
  {
    Bag[i] = 0;
  }
  size = 0;
  //make empty true
  empty = true;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  int count = 0;
  //loop through Bag and count item
  for (size_t i = 0; i < size; i++)
  {
    //if the item at the index matches the passed item, increase the count variable
    if(Bag[i]==item){
      count++;
    }
  }
  return count; //return final value
};
