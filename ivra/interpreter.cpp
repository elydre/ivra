#include "ivra.h"

using namespace std;

void start_inter(vector<string> code, IVRA obj, int while_id) {
	int to_pass = 0;
	while (obj.get_rgt(while_id)) {
		for (int i = 0; i < code.size(); i++) {
			string ligne = code[i];
			vector<string> args = split(ligne, ' ');
			string mode = args[0];

			if (mode == "end"){
				to_pass--;
			}

			if (to_pass){
				continue;
			}

			else if (mode == "test_class") {
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

			else if (mode == "while")
			{
				vector<string> new_code;
				for (int j = i; j < code.size(); j++) {
					new_code.push_back(code[j]);
				}
				start_inter(new_code, obj, stoi(args[1]));
				to_pass++;
			}
		}
	}	
}