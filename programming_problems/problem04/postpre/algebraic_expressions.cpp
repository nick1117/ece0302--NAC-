#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include <stack>

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

// Convert the input expression postfix to prefix
// Preconditions: postfix is a valid postfix expression
//size - return size
//top - access next element
//push - insert an elemnt
//pop - remove top element
//swap - swap contents
void convert(string &postfix, string &prefix) {

  std::stack<string> obj;
  //get length of postfix and loop throught it
  size_t length = postfix.size();
  for(size_t i = 0; i < length; i++){
    //set the index of postfix to a character value c
    char c = postfix[i];
    //if the value is not an operator and is a letter, push it onto obj
    if(isalpha(c)){
      obj.push(string(1,c));
    }
    //if the index is an operator
    else if(isoperator(c)){
      //save the right most value and remove it
      string alpha2 = obj.top();
      obj.pop();
      //save the new right most value and remove it
      string alpha1 = obj.top();
      obj.pop();
      //create a new string with the format below
      string resultant = c + alpha1 + alpha2;
      //push this resultant to the object
      obj.push(resultant);
    }
    //else output error message
    else{
      std::cout << "Error";
      return;
    }
    //set prefix to the obj at the end of loop
    prefix = obj.top();


  }

  
}
