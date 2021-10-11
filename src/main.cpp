
#include "Interface.hpp"
#include <iostream>
#include <dlfcn.h>
#include <fstream>

int main(int argc, char ** argv)
{
	std::string plugin_name;
	std::ifstream plugin_file;
	plugin_file.open("/plugin_testing/plugin_to_load");
	std::getline(plugin_file, plugin_name);
	plugin_file.close();


	void * plugin_handle = dlopen(plugin_name.c_str(),RTLD_NOW);
	
	if (!plugin_handle) {
        	/* fail to load the library */
        	fprintf(stderr, "Handle Error: %s\n", dlerror());
        	return EXIT_FAILURE;
    	}
		
	dlerror();
	MyPrinter* (*fptr)(void);
	fptr = (MyPrinter* (*)(void))dlsym(plugin_handle,"CreatePrinter");	
	
	MyPrinter* pluginPrinter = (*fptr)();

 	std::cout << "Plugin output:\n--------------\n";
	pluginPrinter->PrintSomething();	
	return 0;
}



