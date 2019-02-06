/*
 * testlivre.cpp
 *
 *  Created on: Jan 15, 2019
 *      Author: marceauclavel
 */


#include "Livre.h"
#include "tests.h"
#include "SousClasses.h"
#include <iostream>
#include <string>

using namespace std;

int testLivre(){

	Livre livre1 = Livre("Harry", "JK", "Editor1", 123456, 145, 271);
	Livre livre2 = Livre("Potter", "JB", "Editor2", 119999, 15, 211, "Ados", "indisponible");
	cout << livre1.getAuteur() << endl;
	cout << livre1.getEditeur() << endl;
	cout << livre1.getIsbn() << endl;
	cout << livre1.getBibliothequeOrigine() << endl;
	cout << livre1.getBibliothequeActuelle() << endl;
	cout << livre1.getPublicVise() << endl;
	cout << livre1.getEtat() << endl;

	livre2.affiche();
	livre1.affiche();

	cout << " " << endl;
	cout << livre1 << endl;

	return 1;
}

int testBD(){

	BD BD1 = BD("Tintin", "JK", "Editor1", 1234567890, 145, 271, "dessinateurDeOuf");
	BD1.affiche();

	return 1;
}

int testRecueilPoesie(){

	RecueilPoesie recueilPoesie1 = RecueilPoesie("baudelaire", "JK", "Editor1", 1234567890, 145, 271, "prose");
	recueilPoesie1.affiche();

	return 1;
}

int testRoman(){

	Roman roman1 = Roman("titreDeRoman", "JK", "Editor1", 1234567890, 145, 271, "New times roman");
	roman1.affiche();

	return 1;
}

int testPieceDeTheatre(){

	PieceDeTheatre pieceDeTheatre1 = PieceDeTheatre("titreDePieceDeTheatre", "JK", "Editor1", 1234567890, 145, 271, "New times roman");
	pieceDeTheatre1.affiche();

	return 1;
}

int testAlbum(){

	Album album1 = Album("titreD'Album", "JK", "Editor1", 1234567890, 145, 271, "New times roman");
	album1.affiche();

	return 1;
}

