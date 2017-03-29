#include "adt.h"

#include <iostream>
#include <cstring>


const char* HWCPP_ADT::ADT::getStudentID()
{

	throw "HWCPP_ADT::ADT::getStudentID";
}

int HWCPP_ADT::ADT::sum( int , int )
{
	throw "HWCPP_ADT::ADT::sum";

}

void HWCPP_ADT::ADT::swap( int *, int * )
{
	throw "HWCPP_ADT::ADT::swap PTR";

}

void HWCPP_ADT::ADT::swap( int &, int & )
{
	throw "HWCPP_ADT::ADT::swap REF";

}


void HWCPP_ADT::eval( ADT & adtInstance )
{ 
	try{ 
	
		int x=10;
		int y=20;

		adtInstance.swap(x,y);
		if (x!=20 || y!=10)
		{
			throw "swap(x,y) is not correct";
		}

		adtInstance.swap(&x,&y);
		if (x!=10 || y!=20)
		{
			throw "swap(x,y) is not correct";
		}


		const char* id = adtInstance.getStudentID();
		if (id == NULL || strlen(id) < 4 )
		{
			throw "getStudentID is not correct";
		}

		
		if ( adtInstance.sum(x,y) != 30 )
		{
			throw "sum(x,y) is not correct";
		} 

		std::cout << " -- PASS -- " << std::endl;


	}catch(const char* str){
		 
		std::cout<<"* NOT PASS BASIC TEST : ["<<str<<"]"<<std::endl;

	}
	 
}


void HWCPP_ADT::eval( ADT * adtInstance )
{
	eval(*adtInstance);
}



