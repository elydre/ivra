#include "ivra.h"

using namespace std;

void start_inter(vector<string> code, IVRA obj) {
	for (int i = 0; i < code.size(); i++) {
		string ligne = code[i];
		vector<string> args = split(ligne, ' ');
		string mode = args[0];

		if (mode == "test_class") {
			obj.test_class();
		}
		else if (mode == "set") {
			obj.set(stoi(args[1]), stoi(args[2]));
		}
		else if (mode == "show") {
			obj.show(stoi(args[1]));
		}

		else if (mode == "add") {
			obj.add(stoi(args[1]), stoi(args[2]), stoi(args[3]));
		}

		else if (mode == "sub") {
			obj.sub(stoi(args[1]), stoi(args[2]), stoi(args[3]));
		}

		else if (mode == "mul") {
			obj.mul(stoi(args[1]), stoi(args[2]), stoi(args[3]));
		}

		else if (mode == "div") {
			obj.div(stoi(args[1]), stoi(args[2]), stoi(args[3]));
		}

		else if (mode == "is_egal") {
			obj.is_egal(stoi(args[1]), stoi(args[2]), stoi(args[3]));
		}
	}
}