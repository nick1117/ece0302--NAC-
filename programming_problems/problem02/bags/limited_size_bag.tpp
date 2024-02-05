#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() 
{
  size = 0;
  empty = true;
}

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag(LimitedSizeBag<T>& x)
{
  size = 0;
  empty = true;
  std::swap(Bag, x.Bag);
  std::swap(size, x.size);
}


template<typename T>
LimitedSizeBag<T>& LimitedSizeBag<T>::operator=(LimitedSizeBag<T> x)
{  

  return *this;
}
  
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if(size >= 100){ //make sure bag isnt too big and if it is return false
    empty = false;
    return false;
  }
  else{ //if it isnt too big, add item to end of the Bag
    size += 1;
    Bag[size-1] = item;
    empty = false;
    return true;
  }
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  size_t i;
  //make sure it is not completely empty
  if(size <= 0){
    //ensure bag is empty
    empty = true;
    return false;
  }
  else{ //if Bag is not empty
    //loop throught Bag
    bool found = false;
    for (i = 0; i < size; i++)
    {
      //if the item is detected, break the loop
      if(Bag[i] == item){
        found = true;
        break;
      }
    }
    if(found == false){
      return false;
    }
    //decrease the size by 1
    size = size - 1; 
    //pick back up at the same point but move the array values down one
    for (size_t j = i; j < size; j++)
    {
      Bag[j] = Bag[j+1];
    } 
    
    //check to see the status of empty
    if(size == 0){
      empty = true;
    }
    else{
      empty = false;
    }
    return true;
  }
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  return empty; //return status of empty
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return size; //return the current size
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  for (size_t i = 0; i < size; i++)
  {
    //check to see if item at the index matches
    if(Bag[i]==item){
      //if it does return true
      return true;
    }
  }
  return false;
}

template<typename T>
void LimitedSizeBag<T>::clear()
{
  //loop through bag and empty it
  for (size_t i = 0; i < size; i++)
  {
    Bag[i] = 0;
  }
  size = 0;
  //make empty true
  empty = true;
  
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  int count = 0;
  for (size_t i = 0; i < size; i++)
  {
    //check to see if the item matches that in bag
    if(Bag[i]==item){
      //if it does increase count
      count++;
    }
  }
  
  return count;
};
