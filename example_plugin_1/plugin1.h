

#include "Interface.hpp"



class TestingClass : public MyPrinter
{
public:
	TestingClass() : MyPrinter(111) {}
	~TestingClass(){}

	void PrintSomething() override {
		std::cout << "Printing from plugin 1.\n";
		return;
	}
};

extern "C" MyPrinter* CreatePrinter()
{
	return new TestingClass();
}







