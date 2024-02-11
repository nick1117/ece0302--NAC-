#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;


TEST_CASE( "Default constructor", "[ArrayList]" ) {
  ArrayList<int> list;
  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());
}

TEST_CASE( "copy constructor", "[ArrayList]" ) {
  ArrayList<int> list;
  for (size_t i = 0; i < 20; i++)
  {
    list.insert(i,i);
  }
  
  ArrayList<int> copyList(list);
  REQUIRE(list.getLength() == copyList.getLength());
  REQUIRE(list.getEntry(3) == copyList.getEntry(3));
  REQUIRE(list.getEntry(10) == copyList.getEntry(10));
}

TEST_CASE( "copy assignment", "[ArrayList]" ) {
  ArrayList<int> list;
  for (size_t i = 0; i < 20; i++)
  {
    list.insert(i,i);
  }
  ArrayList<int> copyList;
  copyList = list;
  REQUIRE(list.getLength() == copyList.getLength());
  REQUIRE(list.getEntry(3) == copyList.getEntry(3));
  REQUIRE(list.getEntry(10) == copyList.getEntry(10));
}

TEST_CASE( "insert", "[ArrayList]" ) {
  ArrayList<int> list;
  for (size_t i = 0; i < 20; i++)
  {
    list.insert(i,i);
  }
  list.insert(7,5);
  REQUIRE(list.getLength() == 21);
  REQUIRE(list.getEntry(7) == 5);
  REQUIRE(list.getEntry(8) == 7);
  REQUIRE(list.getEntry(20) == 19);
  REQUIRE_FALSE(list.getEntry(25));
}

TEST_CASE( "remove", "[ArrayList]" ) {
  ArrayList<int> list;
  ArrayList<int> nullList;
  for (size_t i = 0; i < 20; i++)
  {
    list.insert(i,i);
  }
  list.insert(7,5);
  list.remove(7);
  REQUIRE_FALSE(list.getEntry(7) == 5);
  REQUIRE(list.getEntry(7) == 7);
  list.remove(7);
  REQUIRE_FALSE(list.getEntry(20));
}

TEST_CASE( "clear", "[ArrayList]" ) {
  ArrayList<int> list;
  for (size_t i = 0; i < 20; i++)
  {
    list.insert(i,i);
  }
  list.clear();
  REQUIRE(list.isEmpty());
  REQUIRE(list.getLength() == 0);
}

TEST_CASE( "getEntry", "[ArrayList]" ) {
  ArrayList<int> list;
  for (size_t i = 0; i < 20; i++)
  {
    list.insert(i,i);
  }
  REQUIRE(list.getEntry(0) == 0);
  REQUIRE(list.getEntry(4) == 4);
  REQUIRE(list.getEntry(9) == 9);
  REQUIRE(list.getEntry(16) == 16);
  REQUIRE(list.getEntry(19) == 19);
  REQUIRE_FALSE(list.getEntry(20) == 20);
}

TEST_CASE( "setEntry", "[ArrayList]" ) {
  ArrayList<int> list;
  for (size_t i = 0; i < 20; i++)
  {
    list.insert(i,i);
    list.setEntry(i,20+i);
  }
  REQUIRE(list.getEntry(0) == 20);
  REQUIRE(list.getEntry(4) == 24);
  REQUIRE(list.getEntry(9) == 29);
  REQUIRE(list.getEntry(16) == 36);
  REQUIRE(list.getEntry(19) == 39);
  REQUIRE_FALSE(list.getEntry(20) == 40);
}

TEST_CASE( "getLength", "[ArrayList]" ) {
  ArrayList<int> list;
  for (size_t i = 0; i < 20; i++)
  {
    list.insert(i,i);
  }
  REQUIRE(list.getLength() == 20);
}

TEST_CASE( "isEmpty", "[ArrayList]" ) {
  ArrayList<int> list;
  REQUIRE(list.isEmpty());
  for (size_t i = 0; i < 20; i++)
  {
    list.insert(i,i);
  }
  list.clear();
  REQUIRE(list.isEmpty());
}
