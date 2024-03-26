#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

TEST_CASE("Testing Priority Queue", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  pq.add(1);
  pq.add(2);
  pq.add(3);
  pq.add(4);

  REQUIRE(pq.peek() == 4);
  pq.remove();
  REQUIRE(pq.peek() == 3);
  pq.remove();
  REQUIRE(pq.peek() == 2);
  pq.remove();
  REQUIRE(pq.peek() == 1);
  pq.remove();
  REQUIRE(pq.isEmpty());
  // TODO
  
}

TEST_CASE("Testing Priority Queue with strings", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  pq.add('a');
  pq.add('b');
  pq.add('c');
  pq.add('d');

  REQUIRE(pq.peek() == 'd');
  pq.remove();
  REQUIRE(pq.peek() == 'c');
  pq.remove();
  REQUIRE(pq.peek() == 'b');
  pq.remove();
  REQUIRE(pq.peek() == 'a');
  pq.remove();
  REQUIRE(pq.isEmpty());
  // TODO
  
}

TEST_CASE("Testing isEmpty", "[sorted linked list]") {
  SortedList<char,List<char>> lst;
  REQUIRE(lst.isEmpty());

  lst.insert('a');
  REQUIRE(!lst.isEmpty());

  lst.removeAt(0);
  REQUIRE(lst.isEmpty());
}

TEST_CASE("Testing getLength", "[sorted linked list]") {
  SortedList<char,List<char>> lst;
  REQUIRE(lst.getLength() == 0);

  lst.insert('b');
  REQUIRE(lst.getLength() == 1);

  lst.insert('a');
  REQUIRE(lst.getLength() == 2);

  lst.removeAt(0);
  REQUIRE(lst.getLength() == 1);

  lst.removeAt(0);
  REQUIRE(lst.getLength() == 0);
}

TEST_CASE("Testing insert", "[sorted linked list]") {
  SortedList<char,List<char>> lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  for (int i = 0; i < 26; ++i) {
    REQUIRE(lst.getEntry(i) == 'a' + i);
  }
}

TEST_CASE("Testing remove", "[sorted linked list]") {
  SortedList<char,List<char>> lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  lst.removeAt(5);
  REQUIRE(lst.getLength() == 25);
  REQUIRE(lst.getEntry(5) == 'g');

  lst.removeAt(11);
  REQUIRE(lst.getLength() == 24);
  REQUIRE(lst.getEntry(11) == 'n');

  lst.removeAt(0);
  REQUIRE(lst.getLength() == 23);
  REQUIRE(lst.getEntry(0) == 'b');

  lst.removeAt(22);
  REQUIRE(lst.getLength() == 22);
  REQUIRE(lst.getEntry(21) == 'y');
}

TEST_CASE("Testing clear", "[sorted linked list]") {
  SortedList<char,List<char>> lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  lst.clear();
  REQUIRE(lst.getLength() == 0);

  c = 'a';
  while (c <= 'j') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 10);

  SortedList<char,List<char>> lst_empty;
  lst_empty.clear();
  REQUIRE(lst_empty.getLength() == 0);
}

TEST_CASE("Testing getEntry", "[sorted linked list]") {
  SortedList<char,List<char>> lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  for (int i = 0; i < 26; ++i) {
    REQUIRE(lst.getEntry(i) == 'a' + i);
  }
}

TEST_CASE("Testing getPosition empty", "[sorted linked list]") {
  SortedList<char,List<char>> lst;
  
  // empty list
  REQUIRE(lst.getPosition('a') == -1);
}

TEST_CASE("Testing getPosition", "[sorted linked list]") {
  SortedList<char,List<char>> lst;
  
  lst.insert('a');
  lst.insert('d');
  lst.insert('e');
  lst.insert('c');
  lst.insert('b');

  REQUIRE(lst.getPosition('a') == 0);
  REQUIRE(lst.getPosition('b') == 1);
  REQUIRE(lst.getPosition('c') == 2);
  REQUIRE(lst.getPosition('d') == 3);
  REQUIRE(lst.getPosition('e') == 4);
  // not in list
  REQUIRE(lst.getPosition('f') == -1);

}

TEST_CASE("Testing copy", "[sorted linked list]") {
  SortedList<char,List<char>> lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  SortedList<char,List<char>> lst_copy = lst;

  REQUIRE(lst_copy.getLength() == 26);

  for (int i = 0; i < 26; ++i) {
    REQUIRE(lst_copy.getEntry(i) == lst.getEntry(i));
  }
}

TEST_CASE("Testing copy empty", "[sorted linked list]") {
  SortedList<char,List<char>> lst;
  SortedList<char,List<char>> lst_copy = lst;

  REQUIRE(lst.getLength() == 0);
  REQUIRE(lst_copy.getLength() == 0);
}

TEST_CASE("Testing assignment", "[sorted linked list]") {
  SortedList<char,List<char>> lst;
  SortedList<char,List<char>> lst_copy;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  lst_copy = lst;

  REQUIRE(lst_copy.getLength() == 26);

  for (int i = 0; i < 26; ++i) {
    REQUIRE(lst_copy.getEntry(i) == lst.getEntry(i));
  }
}

TEST_CASE("Testing assignment to/from empty", "[sorted linked list]") {
  SortedList<char,List<char>> lst;
  SortedList<char,List<char>> lst_copy;

  lst_copy = lst;

  REQUIRE(lst.getLength() == 0);
  REQUIRE(lst_copy.getLength() == 0);
}

TEST_CASE("Testing exceptions", "[sorted linked list]") {
  SortedList<char,List<char>> lst;

  CHECK_THROWS_AS(lst.removeAt(0), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(0), std::range_error);
  CHECK_THROWS_AS(lst.remove(0), std::range_error);

  lst.insert('a');
  lst.insert('b');
  lst.insert('c');
  lst.insert('d');

  CHECK_THROWS_AS(lst.removeAt(4), std::range_error);
  CHECK_THROWS_AS(lst.removeAt(5), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(4), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(5), std::range_error);

  CHECK_THROWS_AS(lst.removeAt(-1), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(-1), std::range_error);
}