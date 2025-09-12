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
  
  delete odds;
  delete evens;
  in2 = new Node(3, nullptr);
  in = new Node(1, in2);
  odds = nullptr;
  evens = nullptr;

  std::cout << "Test 2 odds, no evens" << std::endl;
  split(in, odds, evens);
  if(in == nullptr){
      std::cout << "Passed 2 odds test" << std::endl;
    }
  else{
      std::cout << "Failed 2 odds test" << std::endl;
  }

  delete odds;
  delete evens;
  in2 = new Node(4, nullptr);
  in = new Node(2, in2);
  odds = nullptr;
  evens = nullptr;

  std::cout << "Test 2 evens, no odds" << std::endl;
  split(in, odds, evens);
  if(in == nullptr){
      std::cout << "Passed 2 evens test" << std::endl;
    }
  else{
      std::cout << "Failed 2 evens test" << std::endl;
  }

  delete odds;
  delete evens;
  in2 = new Node(0, nullptr);
  in = new Node(0, in2);
  odds = nullptr;
  evens = nullptr;

  std::cout << "Test empty list" << std::endl;
  split(in, odds, evens);
  if(in == nullptr){
      std::cout << "Passed empty test" << std::endl;
    }
  else{
      std::cout << "Failed empty test" << std::endl;
  }

  delete odds;
  delete evens;
  return 0;
}
