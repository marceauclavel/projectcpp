/*
 * TestBibliotheque.cpp
 *
 *  Created on: 23 janv. 2019
 *      Author: mfischer
 */




#include <stdio.h>
#include <iostream>
#include <string>

#include "tests.h"
#include "Adherent.h"
#include "Bibliotheque.h"
#include "Livre.h"

using namespace std;

int testBibliotheque() {

	Bibliotheque bibliotheque1 = Bibliotheque("Bibliothèque de Réformés","Réformés-Canebière");
	Bibliotheque bibliotheque2 = Bibliotheque("Bibliothèque de Cinq Avenues","Cinq Avenues - Longchamp");
	Bibliotheque bibliotheque3 = Bibliotheque("Bibliothèque VieuxPort","VP - Marseille 13001");

	cout << "Tests des getters et setters" << endl;

	cout << "Nom de la bibliothèque : " << bibliotheque1.getNom() << endl;
	cout << "Adresse de la bibliotheque : " << bibliotheque1.getAdresse() << endl;
	cout << "Code de la Bibliotheque : " << bibliotheque1.getCode() << endl;
	cout << "Livres actuels de la bibliothèque : " << bibliotheque1.getListeLivresActuels() << endl;
	cout << "Problème habituel adresse et non contenu" << endl ;


	cout << " " << endl << " " << " " << endl;
	cout << " " << endl << " " << " " << endl;

	cout << "Test ostream de Bibliotheque" << endl;

	cout << bibliotheque1 << endl;
	cout << bibliotheque2 << endl;

	Livre livre1 = Livre("titre", "auteur", "editeur", 12345, bibliotheque1.getCode(), bibliotheque1.getCode());
	Livre livre2 = Livre("titre2", "auteur2", "editeur2", 123245, bibliotheque1.getCode(), bibliotheque1.getCode());
	Livre livre3 = Livre("titre3", "auteur3", "editeur3", 1234245, bibliotheque1.getCode(), bibliotheque1.getCode());
	Livre livre4 = Livre("titre4", "auteur4", "editeur4", 4, bibliotheque1.getCode(), bibliotheque1.getCode());
	Livre livre5 = Livre("titre5", "auteur5", "editeur5", 5, bibliotheque2.getCode(), bibliotheque2.getCode());
	Livre livre6 = Livre("titre6", "auteur6", "editeur6", 6, bibliotheque3.getCode(), bibliotheque3.getCode());

	cout << livre1 << endl;

	bibliotheque1.afficherLivres();
	bibliotheque1.acheteLivre(&livre1);
	bibliotheque1.acheteLivre(&livre2);
	bibliotheque1.afficherLivres();
	bibliotheque1.supprimeLivre(livre1.getCode());
	bibliotheque1.afficherLivres();

	cout << "testons la demande d'un livre entre 2 bibliothèques !" << endl;

	cout << livre2.getBibliothequeActuelle() << endl;

	bibliotheque2.demandeLivreA(&bibliotheque1, 123245);
	bibliotheque1.afficherLivres();
	bibliotheque2.afficherLivres();

	cout << livre2.getBibliothequeActuelle() << endl;


	cout << "Test de rendage de livres\n\n" << endl;

	cout << livre2.getBibliothequeActuelle() << endl;

	bibliotheque1.afficherLivres();
	bibliotheque2.afficherLivres();
	bibliotheque2.rendTousLesLivreA(&bibliotheque1);
	bibliotheque1.afficherLivres();
	bibliotheque2.afficherLivres();


	cout << livre2.getBibliothequeActuelle() << endl;

	cout << "Test rendage de la totalité des livres d'une bibliotheque\n\n" << endl;

	bibliotheque1.acheteLivre(&livre4);
	bibliotheque2.acheteLivre(&livre5);
	bibliotheque3.acheteLivre(&livre6);

	bibliotheque1.afficherLivres();
	bibliotheque2.afficherLivres();
	bibliotheque3.afficherLivres();

	bibliotheque3.demandeLivreA(&bibliotheque1, 4);
	bibliotheque3.demandeLivreA(&bibliotheque2, 5);

	bibliotheque1.afficherLivres();
	bibliotheque2.afficherLivres();
	bibliotheque3.afficherLivres();

	rendsTousLesLivres(&bibliotheque3);

	bibliotheque1.afficherLivres();
	bibliotheque2.afficherLivres();
	bibliotheque3.afficherLivres();

	return 1;

}
