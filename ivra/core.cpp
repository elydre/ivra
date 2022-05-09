/*     _             _
  ___ | | _   _   __| | _ __   ___
 / _ \| || | | | / _` || '__| / _ |
|  __/| || |_| || (_| || |   |  __/
 \___||_| \__, | \__,_||_|    \___|
		  |___/
___________________________________

 - cod� en : UTF-8
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

void IVRA::show(int id) {
	std::cout << rgt[id] << std::endl;
}

void IVRA::add(int id1, int id2, int exit) {
	rgt[exit] = rgt[id1] + rgt[id2];
}