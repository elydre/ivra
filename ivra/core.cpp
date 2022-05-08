/*     _             _
  ___ | | _   _   __| | _ __   ___
 / _ \| || | | | / _` || '__| / _ |
|  __/| || |_| || (_| || |   |  __/
 \___||_| \__, | \__,_||_|    \___|
		  |___/
___________________________________

 - codé en : UTF-8
 - langage : c++
 - GitHub  : github.com/elydre
 - Licence : GNU GPL v3
*/

#include "ivra.h"

void IVRA::test_class() {
	std::cout << "that run!" << std::endl;
}

void IVRA::set(int id, int val) {
	rgt[id] = val;
}

void IVRA::get(int id, int to) {
	ram[to] = rgt[id];
}

void IVRA::show(int to) {
	std::cout << ram[to] << std::endl;
}