#ifndef Implement_H
#define Implement_H

#include "readonly/Chain.h"

class Implement : public Chain
{
public:
  void InsertBack(int num);
  //Insert num to the end of the linked list

  void InsertAfter(int num1, int num2);
  //Insert num2 after the first occurrence of num1
  //If num1 doesn’t exist in the linked list, do nothing

  void Delete(int num);
  //Remove the first node (from the head) with the num from the linked list.
  //If num doesn’t exist in the linked list, do nothing.

  void DeleteAll(int num);
  //Remove all the nodes with num from the linked list.
  //If num doesn’t exist in the linked list, do nothing.
};

#endif
