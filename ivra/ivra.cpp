// point d'entrée de l'application

#include "ivra.h"

using namespace std;

int main()
{
	IVRA test;
	test.test_class();
	test.set(5, 30);
	test.set(6, 12);
	test.add(5, 6, 7);
	test.set(8, 42);
	test.is_egal(7, 8, 9);
	test.show(9);
}