

#include "Interface.hpp"



class TestingClass : public MyPrinter
{
public:
	TestingClass() : MyPrinter(222) {}
	~TestingClass(){}

	void PrintSomething() override {
		std::cout << "This is printing from plugin 2.\n";
		return;
	}
};

extern "C" MyPrinter* CreatePrinter()
{
	return new TestingClass();
}







