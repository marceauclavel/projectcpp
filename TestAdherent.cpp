/*
 * TestAdherent.cpp
 *
 *  Created on: 15 janv. 2019
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

int testAdherent() {

	Bibliotheque bibliotheque1 = Bibliotheque("Bibliothèque de Cinq Avenues", "Cinq avenues - Longchamp");


	cout << "Entrée de 3 utilisateurs et affichage des données par la fonction affiche, qui appelle directement les attributs :" << endl;

	Adherent adherentA = Adherent("Fischer","Marion","Klaq",bibliotheque1);
	Adherent adherentB = Adherent("Clavel", "Marceau","Octoloc",bibliotheque1, 6);
	Adherent adherentC = Adherent("Amat","Hugo","Mouga",bibliotheque1);

	adherentA.affiche();
	adherentB.affiche();
	adherentC.affiche();

	cout << "REMARQUE : la fonction affiche rend l'adresse de 'Livres en cours d'emprunt par cet adhérent' et non pas son contenu" << endl;

	cout << " " << endl << " " << " " << endl;
	cout << " " << endl << " " << " " << endl;








	cout << "Test des getter et setter sur le premier des utilisateurs crées précedemment :" << endl;

	cout << "Nom et prénom : " << adherentA.getNom() << " " << adherentA.getPrenom() << endl;
	cout << "Adresse : " << adherentA.getAdresse() << endl;
	cout << "Numéro d'adhérent : " << adherentA.getNumeroAdherent() << endl;
	cout << "Inscrit dans la bibliothèque : " << adherentA.getBibliotheque().getNom() << endl;
	cout << "Autorisé(e) à emprunter jusqu'à " << adherentA.getNbLivresAutorisesEmprunt() << " livres" << endl;
	cout << "Livres en cours d'emprunt par cet adhérent : " << adherentA.getListeLivresEmpruntes() << endl;
	cout << "Les getter fonctionnent MAIS rendent l'adresse de 'Livres en cours d'emprunt par cet adhérent' et non pas son contenu" << endl;
	cout << " " << endl;

	adherentA.setNom("Gonzalez");
	adherentA.setPrenom("Paula");
	adherentA.setAdresse("Consulat");
	adherentA.setNumeroAdherent(4);
	adherentA.setBibliotheque(bibliotheque1);
	adherentA.setNbLivresAutorisesEmprunt(9);
	adherentA.setListeLivresEmpruntes(NULL);

	cout << "Nom et prénom : " << adherentA.getNom() << " " << adherentA.getPrenom() << endl;
	cout << "Adresse : " << adherentA.getAdresse() << endl;
	cout << "Numéro d'adhérent : " << adherentA.getNumeroAdherent() << endl;
	cout << "Inscrit dans la bibliothèque : " << adherentA.getBibliotheque().getNom() << endl;
	cout << "Autorisé(e) à emprunter jusqu'à " << adherentA.getNbLivresAutorisesEmprunt() << " livres" << endl;
	cout << "Livres en cours d'emprunt par cet adhérent : " << adherentA.getListeLivresEmpruntes() << endl;
	cout << "Les setter fonctionnent " << endl;
	cout << " " << endl;

	adherentA.setNom("Fischer");
	adherentA.setPrenom("Marion");
	adherentA.setAdresse("Klaq");
	adherentA.setNumeroAdherent(1);
	adherentA.setBibliotheque(bibliotheque1);
	adherentA.setNbLivresAutorisesEmprunt(5);
	adherentA.setListeLivresEmpruntes(NULL);

	cout << "L'adhérent A a été réinitialisé sur Marion Fischer" << endl;

	cout << " " << endl << " " << " " << endl;
	cout << " " << endl << " " << " " << endl;








	cout << "Test de la fonction emprunte avec tout d'abord encore affiche()" << endl;

	Livre livre1 = Livre("La Quête d'Ewilan", "Pierre Bottero", "Flammarion", 978104, bibliotheque1.getCode(), bibliotheque1.getCode(), "tout public", "libre");


	adherentA.affiche();
	adherentA.emprunte(&livre1); // finalement on va faire des codes livres à 9 chiffres car à partir de 10 chiffres on a
	// un message d'avertissement "Warning: overflow in implicit constant conversion [-Woverflow]" et ça fait des choses bizarres
	adherentA.affiche();
	cout << "Comme prévu, souci pour l'affichage du contenu de 'Livres en cours d'emprunt par cet adhérent'" << endl;
	cout << " " << endl << " " << " " << endl;
	cout << " " << endl << " " << " " << endl;




	cout << "Test de la fonction ostream qui remplacera affiche à l'avenir" << endl;
	cout << adherentA << endl;
	cout << "Cette fois-ci on affiche bien le contenu de 'Livres en cours d'emprunt par cet adhérent'" << endl;

	cout << " " << endl << " " << " " << endl;
	cout << " " << endl << " " << " " << endl;


	cout << "Test de la limite de nombre de livres empruntés de la fonction emprunt" << endl;

	Livre livre2 = Livre("Harry Potter et la Chambre des Secrets", "JK Rowling", "Flammarion", 978080, bibliotheque1.getCode(), bibliotheque1.getCode(), "tout public", "libre");
	Livre livre3 = Livre("Le Comte de Monte-Cristo", "Alexandre Dumas", "Flammarion", 978957, bibliotheque1.getCode(), bibliotheque1.getCode(), "tout public", "libre");
	Livre livre4 = Livre("Jack et le Haricot magique", "Unknown", "Flammarion", 978853, bibliotheque1.getCode(), bibliotheque1.getCode(), "tout public", "libre");
	Livre livre5 = Livre("Le Portrait de Dorian Gray", "Oscar Wilde", "Flammarion", 978154, bibliotheque1.getCode(), bibliotheque1.getCode(), "tout public", "libre");
	Livre livre6 = Livre("La Trilogie des Charmettes", "Eric Boisset", "Flammarion", 978221, bibliotheque1.getCode(), bibliotheque1.getCode(), "tout public", "libre");

	adherentA.emprunte(&livre2);
	adherentA.emprunte(&livre3);
	adherentA.emprunte(&livre4);
	adherentA.emprunte(&livre5);
	cout << adherentA << endl;
	cout << "On devrait donc avoir le message d'avertissement de la fonction emprunt s'il y a un emprunt supplémentaire :" << endl;
	adherentA.emprunte(&livre6);
	cout << "C'est bien le cas." << endl;
	cout << " " << endl;
	cout << adherentA << endl;


	cout << " " << endl << " " << " " << endl;
	cout << " " << endl << " " << " " << endl;

	cout << "Tests de la fonction rend" << endl;
	cout << "Devrait renvoyer que ce n'est pas emprunté :" << endl;
	adherentA.rend(&livre6);
	cout << " " << endl;
	cout << "Devrait rendre le livre donné (Le Comte de Monte-Cristo) puis (Jack et le Haricot magique) de la liste des livres empruntes de l'adherent :" << endl;
	adherentA.rend(&livre3);
	cout << adherentA << endl;
	cout << " " << endl;
	adherentA.rend(&livre4);
	cout << adherentA << endl;
	adherentA.rend(&livre5);
	adherentA.rend(&livre2);
	adherentA.rend(&livre1);
	cout << adherentA << endl;


	cout << " " << endl << " " << " " << endl;
	cout << " " << endl << " " << " " << endl;


	cout << "Suite des tests des fonctions emprunte et rend (Test changement disponibilité livre)" << endl;
	adherentB.emprunte(&livre1);
	adherentB.emprunte(&livre3);
	cout << adherentB << endl;
	cout << " " << endl;

	cout << "Etat livre 3 (Le Comte de Monte-Cristo) : " << livre3.getEtat() << endl;
	cout << " " << endl;


	adherentA.emprunte(&livre3);
	cout << adherentA << endl;
	cout << " " << endl;
	cout << adherentB << endl;
	cout << " " << endl;

	adherentB.rend(&livre3);
	cout << adherentB << endl;
	cout << " " << endl;
	adherentA.emprunte(&livre3);
	cout << adherentA << endl;


	cout << " " << endl << " " << " " << endl;
	cout << " " << endl << " " << " " << endl;

	cout << "Suite des tests de la fonction emprunte (Test : un adhérent essaye d'emprunter un livre dans une autre bibliotheque que celle où il est inscrit)" << endl;

	Bibliotheque bibliotheque2 = Bibliotheque("Bibliothèque de Réformés", "Réformés - Canebière");
	Livre livre7 = Livre("Le Parfum", "Patrick Süskind", "Flammarion", 978086, bibliotheque2.getCode(), bibliotheque2.getCode(), "tout public", "libre");
	Adherent adherentD = Adherent("Gonzalez","Paula","Consulat",bibliotheque2);

	cout << adherentC << endl;
	cout << " " << endl;
	adherentC.emprunte(&livre7);
	cout << adherentC << endl;
	cout << " " << endl;
	cout << adherentD << endl;
	cout << " " << endl;
	adherentD.emprunte(&livre7);
	cout << adherentD << endl;
	cout << " " << endl;

	return 1;

}
