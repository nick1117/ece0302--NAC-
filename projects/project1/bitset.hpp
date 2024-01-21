#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>

class Bitset{
public:

  // default constructor
  Bitset();

  // Set size of bitset with passed int
  Bitset(intmax_t size);

  // COnstructor with string input
  Bitset(const std::string & value);

  // Destructor
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // return size of Bitset
  intmax_t size() const;

  // return true if valid bitset
  bool good() const;

  // Turn bit at index to one
  void set(intmax_t index);

  // Turn bit at index to zero
  void reset(intmax_t index);

  // Turn bit at index to opposite state
  void toggle(intmax_t index);

  // return value of bit at index
  bool test(intmax_t index);

  // return string that is representitive of the bitset
  std::string asString() const;

private:
  uint8_t* Bitset_pointer;
  uintmax_t length;
  bool valid;
};

#endif
