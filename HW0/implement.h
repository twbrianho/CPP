#ifndef HW1CPP_IMPLEMENT_H
#define HW1CPP_IMPLEMENT_H

#include "readonly/adt.h"

// Note that you should NOT modify the name of the class "Implement",
class Implement : public HWCPP_ADT::ADT
{

public:

	//write your code in implement.cpp
	const char* getStudentID();

	//write your code in implement.cpp
	int sum(int , int );

	//don't forget to implement the remaining swap functions.
	void swap(int *, int *);

	/**----------------------------------------------------------------------/
	 * This function will swap the value of its parameters
	 **---------------------------------------------------------------------*/
	void swap(int &, int &);
};

#endif