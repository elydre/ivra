// include

#pragma once

#include <iostream>

// en-têtes

class IVRA {
private:
	int rgt[64] = { 0 };

public:
	void test_class();
	void set(int id, int val);
	void get(int id, int to);
	void show(int to);
	void add(int id1, int id2, int exit);
	void is_egal(int id1, int id2, int exit);
};