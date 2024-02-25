#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	//base case - see if 
	if(currentStringVector.size()==0){
		//declare temporary string
		string temp = "";
		//loop through canidate string vector
		for (size_t i = 0; i < candidateStringVector.size(); i++)
		{
			//add to temporary string
			temp += candidateStringVector[i];
		}
		//check if it is a palindrome
		if(isPalindrome(temp)==true){
			//if it is increase number of palindromes and add to soln vector
			numP++;
			soln.push_back(candidateStringVector);
		}
	
	}
	else{
		
		for (size_t i = 0; i < currentStringVector.size(); i++) //current
		{
			vector<string> copyCan = candidateStringVector;
			vector<string> copyCur = currentStringVector;
			copyCan.push_back(copyCur[i]);
			copyCur.erase(copyCur.begin()+i);

			if(cutTest2(copyCan, copyCur)==true){
				recursiveFindPalindromes(copyCan,copyCur);
			}
		}
	}
	///use cut test 2
	// TODO need to implement this recursive function!
	
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	vector<string>strVector = {};
	numP = 0;
	vector<vector<string>> soln = {}; 
}

FindPalindrome::~FindPalindrome()
{
	//clear();
	//strVector.~vector();
	//soln.~vector();
}

int FindPalindrome::number() const
{
	return numP;
}

void FindPalindrome::clear()
{
	numP = 0;
	strVector.clear();
	soln.clear();
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	std::string Vect = "";
	for (size_t i = 0; i < stringVector.size(); i++)
	{
		Vect += stringVector[i];
	}
	convertToLowerCase(Vect);

	std::string check = "abcdefghijklmnopqrstuvwxyz";
	int countArray[26];

	for (size_t i = 0; i < 26; i++)
	{
		int count = 0;
		for (size_t j = 0; j < Vect.size(); j++)
		{
			if(check[i] == Vect[j]){
				count++;
			}
		}
		countArray[i] = count;
	}

	int oddValue = 0;
	for (size_t i = 0; i < 26; i++)
	{
		if(countArray[i]%2 != 0){
			oddValue++;
		}
	}

	if(oddValue > 1){
		return false;
	}

	return true;



	// std::string Vect = "";
	// for (size_t i = 0; i < stringVector.size(); i++)
	// {
	// 	Vect += stringVector[i];
	// }

	// //get the size of the stringVector
	// int size = Vect.size();
	// convertToLowerCase(Vect);
	// //a AA AaA
	// int singleOccurance = 0;
	// for (size_t i = 0; i < size; i++) //loop through string size twice
	// {
	// 	//set a count variable and initalize it to zero everytime we set the index we want to check
	// 	int count = 0;
	// 	//check our "check index" against every index in string
	// 	for (size_t j = 0; j < size; j++)
	// 	{	
	// 		if(Vect[i] == Vect[j]){
	// 			count = count + 1; //if the check index has the same value as another index, increase count
	// 		}
	// 	}
	// 	if(count%2 == 1){
	// 		singleOccurance = singleOccurance + 1;
	// 	}
	// 	//if the value is not even or if the value as occured once once more then one tim, return false
	// 	if(count%2 != 0){
	// 		if(singleOccurance != 1){ 
	// 			return false;
	// 		}
	// 	}
	// }
	// return true;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	std::string Vect1 = "";
	std::string Vect2 = "";
	for (size_t i = 0; i < stringVector1.size(); i++)
	{
		Vect1 += stringVector1[i];
	}
	for (size_t i = 0; i < stringVector2.size(); i++)
	{
		Vect2 += stringVector2[i];
	}
	convertToLowerCase(Vect1);
	convertToLowerCase(Vect2);
	std::string bigger;
	std::string smaller;
	if(Vect1.size() >= Vect2.size()){ // change from stringVector# to Vect#
		bigger = Vect1;
		smaller = Vect2;//
	}
	else{
		bigger = Vect2;
		smaller = Vect1;
	}
	int bigArray[26];
	int smallArray[26];
	for (size_t i = 0; i < 26; i++)
	{
		bigArray[i] = 0;
		smallArray[i] = 0;
	}
	for (size_t i = 0; i < bigger.length(); i++)
	{
		++bigArray[bigger[i]-97];
	}
	for (size_t i = 0; i < smaller.length(); i++)
	{
		++smallArray[smaller[i]-97];
	}
	for (size_t i = 0; i < 26; i++)
	{
		if(bigArray[i] < smallArray[i]){
			return false;
		}
	}
	return true;
}

/** Adds a new string to this FindPalindrome instance and computes the
	   number of palindrome sentences possible. Note that the new string must
	   be unique per the definition in the project description.
	   @post  If successful, the string has been added to the FindPalindrome
	    and instance, and the sentence palindromes in the instance 
	    have been recomputed.
	   @param value  The string to add to the instance of FindPalindrome.
	   @return  True if addition was successful, or false if not. */
bool FindPalindrome::add(const string & value)
{
	//check if valid
	string str = value;
	convertToLowerCase(str);
  	std::size_t found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
	if (found!=std::string::npos)
  	{
		//return false if not valid
    	return false;
  	}

	std::vector<std::string> tempStringVector;
	for (size_t i = 0; i < strVector.size(); i++)
	{
		tempStringVector.push_back(strVector[i]);
		convertToLowerCase(tempStringVector[i]);
	}

	for (size_t i = 0; i < strVector.size(); i++)
	{
		if(str == tempStringVector[i]){
			return false;
		}
	}
	
	strVector.push_back(value);
	numP = 0;
	soln.clear();
	if(cutTest1(strVector)==true){
		//numP = 0;
		//soln.clear();
		vector<string> emptyVect;
		recursiveFindPalindromes(emptyVect,strVector);
		return true;
	}

	return true;
}

/** Adds a new vector of strings to this FindPalindrome instance and
	   computes the number of palindrome sentences possible. Note: You may
	   not implement this method by repeatedly calling the add(string) method
	   as this would be very inefficient. Implementing this method by repeatedly
	   calling add(string) will result in a grade of zero for the project. Again,
	   note that the strings added must be unique per the project description.
	   @post  If successful, the vector of strings has been added to the 
	    FindPalindrome instance, and the sentence palindromes for the instance 
	    have been recomputed.
	   @param stringVector  The vector of strings to add to the instance of
	    FindPalindrome.
	   @return  True if addition was successful, or false if not. */
bool FindPalindrome::add(const vector<string> & stringVector)
{
	//check to see if stringVector has any characters that are not letter
	//change the value at a certian index to lower case and add it to a tempVector variable
	//if the value at a certain index is not a letter, return false
	std::vector<std::string> stringVectorTemp = {};
	string temp = "";
	for (size_t i = 0; i < stringVector.size(); i++)
	{
		temp = stringVector[i];
		convertToLowerCase(temp);
		std::size_t found = temp.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
		if (found!=std::string::npos)
		{
			//return false if not valid
			return false;
		}
		stringVectorTemp.push_back(temp);

	}

	//convert all the values in the main strVector to lower case
	std::vector<std::string> tempStrVector = {};
	string temp2 = "";
	for (size_t i = 0; i < strVector.size(); i++)
	{
		temp2 = strVector[i];
		convertToLowerCase(temp2);
		tempStrVector.push_back(temp2);
		
	}

	//loop over both vectors and see if they ever equal eachother
	for (size_t i = 0; i < strVector.size(); i++)
	{
		for (size_t j = 0; j < stringVector.size(); j++)
		{
			if(tempStrVector[i] == stringVectorTemp[j]){
				return false;
			}
		}
		
	}
	for (size_t i = 0; i < stringVector.size(); i++)
	{
		strVector.push_back(stringVector[i]);
	}
	numP = 0;
	soln.clear();
	if(cutTest1(strVector)==true){
		//numP = 0;
		//soln.clear();
		vector<string> emptyVect;
		recursiveFindPalindromes(emptyVect,strVector);
		return true;
	}

	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	return soln;
}

