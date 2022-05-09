// point d'entrée de l'application

#include "ivra.h"

using namespace std;

int main()
{
	IVRA test; // 1+2*3
	test.test_class();
	test.set(5, 1);
	test.set(6, 2);
	test.add(5, 6, 7);
	test.set(8, 3);
	test.mul(7, 8, 9);
	test.show(9);
	
}