// point d'entrée de l'application

#include "ivra.h"

using namespace std;

int main()
{
	string work_dir = "C:/Users/pf4/fichiers/GitHub/elydre/ivra/ivra/";
	vector<string> sortie = start_parse(work_dir + "code.ivr");
	
	IVRA obj;

	start_inter(sortie, obj);
}