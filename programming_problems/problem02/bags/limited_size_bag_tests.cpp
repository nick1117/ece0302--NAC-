#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);

}


TEST_CASE("Default constructor", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

}

TEST_CASE("Copy Constructor", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  for (size_t i = 0; i < 20; i++)
  {
    b.add(i);
  }
  LimitedSizeBag<int> x(b);
  for (size_t i = 0; i < 20; i++)
  {
    REQUIRE(x.contains(i));
  }
}

TEST_CASE("copy assignment", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  for (size_t i = 0; i < 20; i++)
  {
    b.add(i);
  }
  LimitedSizeBag<int> x;
  x = b;
  for (size_t i = 0; i < 20; i++)
  {
    REQUIRE(x.contains(i));
  }
}

TEST_CASE("Testing add", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  for (size_t i = 0; i < 20; i++)
  {
    b.add(i);
  }
  REQUIRE(b.getCurrentSize()==20);
  REQUIRE(b.contains(19));
}

TEST_CASE("Testing remove", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  for (size_t i = 0; i < 20; i++)
  {
    b.add(i);
  }
  b.remove(11);

  REQUIRE(b.getCurrentSize()==19);
  REQUIRE_FALSE(b.contains(11));
}
TEST_CASE("Testing remove but only removing 1", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  for (size_t i = 0; i < 20; i++)
  {
    b.add(1);
  }
  b.remove(1);

  REQUIRE(b.getCurrentSize()==19);
  REQUIRE(b.getFrequencyOf(1) == 19);
}

TEST_CASE("isEmpty", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  for (size_t i = 0; i < 20; i++)
  {
    b.add(1);
    b.remove(1);
  }
  REQUIRE(b.isEmpty());
}

TEST_CASE("Clear", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  for (size_t i = 0; i < 80; i++)
  {
    b.add(1);
  }
  b.clear();
  REQUIRE(b.isEmpty());
  REQUIRE(b.getCurrentSize() == 0);
}

TEST_CASE("Testing get frequency", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  for (size_t i = 0; i < 10; i++)
  {
    if(i%2 == 0){
      b.add(1);
    }
    else{
      b.add(2);
    }
  }
  REQUIRE(b.getFrequencyOf(1) == 5);
  REQUIRE(b.getFrequencyOf(2) == 5);

}

TEST_CASE("contain", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  for (size_t i = 0; i < 10; i++)
  {
    b.add(1);
    if(i == 5){
      b.add(2);
    }
    else{
      b.add(1);
    }
  }
  REQUIRE(b.contains(2));
}

TEST_CASE("Test to see if add more then 100", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  for (size_t i = 0; i < 200; i++)
  {
    b.add(1);
  }
  REQUIRE_FALSE(b.add(1));
  REQUIRE(b.getCurrentSize() == 100);
}

TEST_CASE("Test to see if will remove when at size 0", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  REQUIRE_FALSE(b.remove(1));
}

TEST_CASE("Test to see if less then 100", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  for (size_t i = 0; i < 10; i++)
  {
    b.add(1);
  }
  for (size_t i = 0; i < 20; i++)
  {
    b.remove(1);
  }
  REQUIRE_FALSE(b.remove(1));
  REQUIRE(b.getCurrentSize()==0);
}


/*
TEST_CASE("To access MAXSIZE", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  REQUIRE(LimitedSizeBag<int>::maxsize == 100);
}

*/