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
	std::cout << rgt[id];
}

void IVRA::add(int id1, int id2, int exit) {
	rgt[exit] = rgt[id1] + rgt[id2];
}

void IVRA::sub(int id1, int id2, int exit) {
	rgt[exit] = rgt[id1]- rgt[id2];
}

void IVRA::mul(int id1, int id2, int exit) {
	rgt[exit] = rgt[id1] * rgt[id2];
}

void IVRA::div(int id1, int id2, int exit) {
	rgt[exit] = rgt[id1] / rgt[id2];
}

void IVRA::mod(int id1, int id2, int exit) {
	rgt[exit] = rgt[id1] % rgt[id2];
}

void IVRA::bool_or(int id1, int id2, int exit) {
	if (rgt[id1] || rgt[id2]) {
		rgt[exit] = 1;
	}
}

void IVRA::bool_not(int id) {
	if (rgt[id]) {
		rgt[id] = 0;
	}
	else {
		rgt[id] = 1;
	}
}

void IVRA::is_egal(int id1, int id2, int exit) {
	rgt[exit] = rgt[id1] == rgt[id2];
}

void IVRA::is_sup(int id1, int id2, int exit) {
	rgt[exit] = rgt[id1] > rgt[id2];
}

int IVRA::get_rgt(int id) {
	return rgt[id];
}

void IVRA::cp(int id1, int exit) {
	rgt[exit] = rgt[id1];
}