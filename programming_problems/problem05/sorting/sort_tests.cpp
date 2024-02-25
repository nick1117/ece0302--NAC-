#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"
#include "sort.hpp"

// write your test cases here
TEST_CASE("Test case", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, 100);
  lst.insert(1, 4);
  lst.insert(2, 10);
  lst.insert(3, 25);
  lst.insert(4, 11);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 4);
  REQUIRE(sorted.getEntry(1) == 10);
  REQUIRE(sorted.getEntry(2) == 11);
  REQUIRE(sorted.getEntry(3) == 25);
}

TEST_CASE("Test case: char", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, 'z');
  lst.insert(1, 'd');
  lst.insert(2, 'b');
  lst.insert(3, 'c');
  lst.insert(4, 'a');

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 'a');
  REQUIRE(sorted.getEntry(1) == 'b');
  REQUIRE(sorted.getEntry(2) == 'c');
  REQUIRE(sorted.getEntry(3) == 'd');
}

TEST_CASE("Test case: long list", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, 'z');
  lst.insert(1, 'd');
  lst.insert(2, 'b');
  lst.insert(3, 'c');
  lst.insert(4, 'a');
  lst.insert(5, 'e');
  lst.insert(6, 'g');
  lst.insert(7, 'h');
  lst.insert(8, 'f');
  lst.insert(9, 'j');
  lst.insert(10, 'i');
  lst.insert(11, 'k');


  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 'a');
  REQUIRE(sorted.getEntry(1) == 'b');
  REQUIRE(sorted.getEntry(2) == 'c');
  REQUIRE(sorted.getEntry(3) == 'd');
  REQUIRE(sorted.getEntry(4) == 'e');
  REQUIRE(sorted.getEntry(5) == 'f');
  REQUIRE(sorted.getEntry(6) == 'g');
  REQUIRE(sorted.getEntry(7) == 'h');
  REQUIRE(sorted.getEntry(8) == 'i');
  REQUIRE(sorted.getEntry(9) == 'j');
  REQUIRE(sorted.getEntry(10) == 'k');
  REQUIRE(sorted.getEntry(11) == 'z');

}