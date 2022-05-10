// point d'entrée de l'application

#include "ivra.h"

using namespace std;

int main()
{
	string work_dir = "/home/pf4/Documents/GitHub/ivra/ivra/";
	vector<string> sortie = start_parse(work_dir + "code.ivr");
	
	IVRA obj;

	start_inter(sortie, obj);
}