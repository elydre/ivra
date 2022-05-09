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
	test.show(7);
}