#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);


}
TEST_CASE("default constructor", "[DynamicBag]"){
  DynamicBag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
}

TEST_CASE("testing add", "[DynamicBag]"){
  DynamicBag<int> b;
  for (size_t i = 0; i < 20; i++)
  {
    b.add(i);
  }
  REQUIRE(b.getCurrentSize()==20);
  REQUIRE(b.contains(19));
}

TEST_CASE("testing add past 100", "[DynamicBag]"){
  DynamicBag<int> b;
  for (size_t i = 0; i < 200; i++)
  {
    b.add(i);
  }
  REQUIRE(b.getCurrentSize()==200);
}

TEST_CASE("testing remove", "[DynamicBag]"){
  DynamicBag<int> b;
  for (size_t i = 0; i < 20; i++)
  {
    b.add(i);
  }
  b.remove(11);

  REQUIRE(b.getCurrentSize()==19);
  REQUIRE_FALSE(b.contains(11));
}

TEST_CASE("testing remove to normal", "[DynamicBag]"){
  DynamicBag<int> b;
  b.remove(11);

  REQUIRE(b.getCurrentSize()==0);
  REQUIRE_FALSE(b.contains(11));
}

TEST_CASE("testing isempty", "[DynamicBag]"){
  DynamicBag<int> b;
  for (size_t i = 0; i < 20; i++)
  {
    b.add(1);
    b.remove(1);
  }
  REQUIRE(b.isEmpty());
}

TEST_CASE("testing getcurrentsize", "[DynamicBag]"){
  DynamicBag<int> b;
  for (size_t i = 0; i < 20; i++)
  {
    b.add(1);;
  }
  REQUIRE(b.getCurrentSize() == 20);
}

TEST_CASE("testing clear", "[DynamicBag]"){
  DynamicBag<int> b;
  for (size_t i = 0; i < 80; i++)
  {
    b.add(1);
  }
  b.clear();
  REQUIRE(b.isEmpty());
  REQUIRE(b.getCurrentSize() == 0);
}

TEST_CASE("testing getFrequencyOf", "[DynamicBag]"){
  DynamicBag<int> b;
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

TEST_CASE("testing contains", "[DynamicBag]"){
  DynamicBag<int> b;
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

TEST_CASE("copy constructor", "[DynamicBag]"){
  DynamicBag<int> b;
  for (size_t i = 0; i < 20; i++)
  {
    b.add(i);
  }
  DynamicBag<int> x(b);
  for (size_t i = 0; i < 20; i++)
  {
    REQUIRE(x.contains(i));
  }
} 

TEST_CASE("copy assignment", "[DynamicBag]"){
  DynamicBag<int> b;
  for (size_t i = 0; i < 20; i++)
  {
    b.add(i);
  }
  DynamicBag<int> x;
  x = b;
  for (size_t i = 0; i < 20; i++)
  {
    REQUIRE(x.contains(i));
  }
} 

