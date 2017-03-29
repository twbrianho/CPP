#include "implement.h"


const char* Implement::getStudentID()
{
	return "103033213";
}

int Implement::sum( int a , int b)
{
	return a + b;
}

void Implement::swap( int *a, int *b )
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Implement::swap( int &a, int & b)
{
	int temp = a;
  a = b;
  b = temp;
}
