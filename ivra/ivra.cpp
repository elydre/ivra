// point d'entrée de l'application

#include "ivra.h"

using namespace std;

int main()
{
	IVRA test;
	test.test_class();
	test.set(5, 42);	// set 42 in the registe
	test.get(5, 1);		// get the int of registre[5] and push in ram[1]
	test.show(1);		// print the int of ram[1]
}