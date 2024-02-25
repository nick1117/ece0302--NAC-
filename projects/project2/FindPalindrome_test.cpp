#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test adding a non-allowable word", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}


TEST_CASE("test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("test simple palindrome", "[FindPalindrome]"){
	FindPalindrome b;
	//adding 4 items
	REQUIRE(b.add("Even"));
	REQUIRE(b.add("Odd"));
	REQUIRE(b.add("Never"));
	REQUIRE(b.add("Or"));
	REQUIRE(b.number() == 1);
}

TEST_CASE("testing number of palindromes", "[FindPalindrome]"){
	FindPalindrome b;
	//adding a few items
	REQUIRE(b.add("y"));
	REQUIRE(b.add("e"));
	REQUIRE(b.add("s"));
	REQUIRE(b.add("t"));
	//checking for the number of palindromes
	REQUIRE(b.number() == 0);
	b.clear(); //clear the vector
	//add a few items
	REQUIRE(b.add("yey"));
	//checking for the number of palindromes
	REQUIRE(b.number() == 1);//this is where your test failed
	b.clear(); //clear the vector
	//add a few items
	REQUIRE(b.add("yet"));
	//checking for the number of palindromes
	REQUIRE(b.number() == 0);
	b.clear(); //clear the vector
	//add a few items
	REQUIRE(b.add("yet"));
	REQUIRE(b.add("tey"));
	//checking for the number of palindromes
	REQUIRE(b.number() == 2);
	b.clear(); //clear the vector
	//add a few items
	REQUIRE(b.add("ye"));
	REQUIRE(b.add("tey"));
	//checking for the number of palindromes
	REQUIRE(b.number() == 1);
}

TEST_CASE("Add vector", "[FindPalindrome]"){
	FindPalindrome b;
	std::vector<std::string> raceCar;
	raceCar = {"race","car"};
	b.add(raceCar);
	REQUIRE(b.number() == 1);
	
}

TEST_CASE("test cut test 1", "[FindPalindrome]"){
	FindPalindrome b;
	std::vector<std::string> str;
	str = {"ab","c","ba"};
	REQUIRE(b.cutTest1(str));
	std::vector<std::string> str2;
	str2 = {"ab","ba"};
	REQUIRE(b.cutTest1(str));
	
}

TEST_CASE("test cut test 2", "[FindPalindrome]"){
	FindPalindrome b;
	std::vector<std::string> str1;
	std::vector<std::string> str2;
	str1 = {"Taco","Cat"};
	str2 = {"Taco"};
	REQUIRE(b.cutTest2(str1,str2));
	
}