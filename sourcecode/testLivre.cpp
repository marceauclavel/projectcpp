/*
 * testlivre.cpp
 *
 *  Created on: Jan 15, 2019
 *      Author: marceauclavel
 */


#include "livre.h"
#include "tests.h"
#include <iostream>
#include <string>

using namespace std;

int testLivre1(){

	Livre livre1 = Livre(1, "JK", "Editor", 1234567890, 145, 271);
	cout << livre1.getAuteur() << endl;

	return 1;
}
