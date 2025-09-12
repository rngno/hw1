/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream> // i want this lol 

int main(int argc, char* argv[])
{
  Node* in2 = new Node(2, nullptr);
  Node* in = new Node(1, in2);
  Node* odds;
  Node* evens;
  std::cout << "Testing small sized linked list, only 1 odd and 1 even:" << std::endl;
  split(in, odds, evens);
  if(in == nullptr){
    std::cout << "Passed 1 odd 1 even test" << std::endl;
  }
  else{
    std::cout << "Failed 1 odd 1 even test" << std::endl;
  }
  delete in;
  delete in2;
  return 0;
}
