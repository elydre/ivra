// include

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

// core.cpp
class IVRA {
private:
	int rgt[64] = { 0 };

public:
	void test_class();
	void set(int id, int val);
	void show(int to);
	void add(int id1, int id2, int exit);
	void sub(int id1, int id2, int exit);
	void mul(int id1, int id2, int exit);
	void div(int id1, int id2, int exit);
	void is_egal(int id1, int id2, int exit);
};

// parser.cpp
vector<string> start_parse(string file_name);

// tool.cpp
string readFile(const string& path);
vector<string> split(string x, char delim = ' ');

// interpreter.cpp
void start_inter(vector<string> code, IVRA obj);