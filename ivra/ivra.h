// include

#pragma once

#include <iostream>

// en-têtes

class IVRA {
private:
	int ram[6] = { 0 };
	int rgt[64] = { 0 };

public:
	void test_class();
	void set(int id, int val);
	void get(int id, int to);
	void show(int to);
};