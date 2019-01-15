/*
 * testlivre.cpp
 *
 *  Created on: Jan 15, 2019
 *      Author: marceauclavel
 */


#include "livre.h"
#include "tests.h"
#include "SousClasses.h"
#include <iostream>
#include <string>

using namespace std;

int testLivre(){

	Livre livre1 = Livre("Harry", "JK", "Editor1", 1234567890, 145, 271);
	Livre livre2 = Livre("Potter", "JB", "Editor2", 1199999890, 15, 211, "Ados", "Emprunte");
	cout << livre1.getAuteur() << endl;
	cout << livre1.getEditeur() << endl;
	cout << livre1.getIsbn() << endl;
	cout << livre1.getBibliothequeOrigine() << endl;
	cout << livre1.getBibliothequeActuelle() << endl;
	cout << livre1.getPublicVise() << endl;
	cout << livre1.getEtat() << endl;

	livre2.affiche();
	livre1.affiche();

	return 1;
}

int testBD(){

	BD BD1 = BD("Harry", "JK", "Editor1", 1234567890, 145, 271, "dessinateurDeOuf");
	cout << BD1.getDessinateur() << endl;

	return 1;
}


