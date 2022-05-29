// point d'entrée de ivra

#include "ivra.h"

using namespace std;

int main()
{
	// string work_dir = "/home/pf4/Documents/GitHub/ivra/ivra/";
	string work_dir = "C:/Users/pf4/fichiers/GitHub/elydre/ivra/ivra/";
	vector<string> sortie = start_parse(work_dir + "code.ivr");
	
	IVRA obj;

	obj.set(0, 1);

	start_inter(sortie, obj, 0);
}