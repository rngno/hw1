/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  // base case for recursion, only need to know if in is empty
  if(in == nullptr){
    // since in is empty, there isn't anything to split
    odds = nullptr;
    evens = nullptr;
    return;
  }

  // actual recursion call
  split(in->next, odds, evens);

  // in retrospect this condition is kind of pointless but i'm leaving it in (im tired)
  if(in != nullptr){
    // evens handling
    if(in->value%2 == 0){
      in->next = evens;
      evens = in;
    }
    // odds handling
    else{
      in->next = odds;
      odds = in;
    }

  }
  // now stop using in per requirements in assignment
  in = nullptr;
}

/* If you needed a helper function, write it here */
