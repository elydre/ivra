// point d'entrée de l'application

#include "ivra.h"

using namespace std;

int main()
{
	IVRA test;
	test.test_class();
	test.set(5, 42);	// set 42 in the registe
	test.show(5);		// print the int of ram[1]
}