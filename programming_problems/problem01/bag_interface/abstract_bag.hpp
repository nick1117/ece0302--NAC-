#ifndef _ABSTRACT_BAG_HPP_
#define _ABSTRACT_BAG_HPP_

#include <cstdlib>

template<class T>class AbstractBag
{
  public:

      /** Retrievs the number of entries within the bag
      @return the integer value of the number of entries that currenly exist*/
    virtual std::size_t getCurrentSize() const = 0;

    /** Checks to see if Bag is empty
      @return true is it is empty or flase if it was not */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to the bag
      @post entry is stored in the bag and the number of items increases by 1
      @param entry object will be added as a new entry
      @return true if it was successfully added or false if it was not */
    virtual bool add(const T& entry) = 0;

    /** Removes an entry from the bag if possible
      @post entry is removed from the bag and the number of items decreases by 1
      @param entry object will be removed
      @return true if it was successfully removed or false if it was not */
    virtual bool remove(const T& entry) = 0;

    /** clears all entries from this the bag
      @post there are no items left in the bag and the number of items is zero */
    virtual void clear() = 0;

    /** finds out how many times a given entry occurs in the bag
      @param entry the entry that we want to count the frequency of
      @return the number of times the entry appears in the bag */
    virtual std::size_t getFrequencyOf(const T& entry) const = 0;

    /** Sees if a given entry is contained in the bag
      @param entry object that we want to see if is contained
      @return true if it contains the given entry or false if it does not */
    virtual bool contains(const T& entry) const = 0;

    /** 
      ~AbstractBag deletes the bag and frees up the memory that was used */
    virtual ~AbstractBag() { }
};

#endif