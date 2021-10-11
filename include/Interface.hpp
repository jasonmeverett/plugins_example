


#include <stdio.h>
#include <iostream>
#include <string>




class MyPrinter
{
	public:
	MyPrinter() : testVal(111) {}
	MyPrinter(int testVal) : testVal(testVal) {}
	int testVal = 0;

	virtual void PrintSomething() = 0;

};



