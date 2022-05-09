#include "ivra.h"

using namespace std;

// tools

string readFile(const string& path) { // delftstack.com
	auto ss = ostringstream{};
	ifstream input_file(path);
	if (!input_file.is_open()) {
		cerr << "Impossible de lire le fichier - '"
			<< path << "'" << endl;
		exit(EXIT_FAILURE);
	}
	ss << input_file.rdbuf();
	return ss.str();
}

vector<string> split(string x, char delim) {
	x += delim; //includes a delimiter at the end so last word is also read
	vector<string> splitted;
	string temp = "";
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] == delim)
		{
			splitted.push_back(temp); //store words in "splitted" vector
			temp = "";
			i++;
		}
		temp += x[i];
	}
	return splitted;
}