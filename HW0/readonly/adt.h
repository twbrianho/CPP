#ifndef HWCPP_ADT_H
#define HWCPP_ADT_H


namespace HWCPP_ADT{

class ADT{

public:

	/**----------------------------------------------------------------------/
	 * @return: return your student ID as a const characters
	 *	e.g. return "101123456789"
	 **---------------------------------------------------------------------*/
	virtual const char* getStudentID();


	/**----------------------------------------------------------------------/
	 * @return: this function will return the sum of its parameters 
	 *  e.g.  sum(3,4) will return 7
	 **---------------------------------------------------------------------*/
	virtual int sum(int , int );

	/**----------------------------------------------------------------------/
	 * This function will swap the value of its parameters
	 **---------------------------------------------------------------------*/
	virtual void swap(int *, int *);


	/**----------------------------------------------------------------------/
	 * This function will swap the value of its parameters
	 **---------------------------------------------------------------------*/
	virtual void swap(int &, int &);

};


///our testing function
void eval( ADT & );


///our testing function
void eval( ADT * );

}


#endif