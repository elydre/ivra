#include "ivra.h"

using namespace std;

vector<string> start_parse(string file_name) {
	string code = readFile(file_name);

	while (code.find_first_of("\n") != string::npos) {
		code.replace(code.find("\n"), 1, ";");
	}

	while (code.find_first_of("\t") != string::npos) {
		code.replace(code.find("\t"), 1, "");
	}

	return split(code, ';');
}