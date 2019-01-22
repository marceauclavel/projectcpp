/*
 * TestAdherent.cpp
 *
 *  Created on: 15 janv. 2019
 *      Author: mfischer
 */



#include <stdio.h>
#include <iostream>
#include <string>
#include "Adherent.h"

using namespace std;

int main() {




	cout << "Entrée de 3 utilisateurs et affichage des données par la fonction affiche, qui appelle directement les attributs :" << endl;

	Adherent adherentA = Adherent("Fischer","Marion","Klaq","Bibliothèque de Cinq Avenues");
	Adherent adherentB = Adherent("Clavel", "Marceau","Octoloc","Bibliothèque de Réformés", 6);
	Adherent adherentC = Adherent("Amat","Hugo","Mouga","Bibliothèque de La Plaine");

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
	cout << "Inscrit dans la bibliothèque : " << adherentA.getBibliotheque() << endl;
	cout << "Autorisé(e) à emprunter jusqu'à " << adherentA.getNbLivresAutorisesEmprunt() << " livres" << endl;
	cout << "Livres en cours d'emprunt par cet adhérent : " << adherentA.getListeLivresEmpruntes() << endl;
	cout << "Les getter fonctionnent MAIS rendent l'adresse de 'Livres en cours d'emprunt par cet adhérent' et non pas son contenu" << endl;
	cout << " " << endl;

	adherentA.setNom("Gonzalez");
	adherentA.setPrenom("Paula");
	adherentA.setAdresse("Consulat");
	adherentA.setNumeroAdherent(4);
	adherentA.setBibliotheque("Bibliothèque de Réformés");
	adherentA.setNbLivresAutorisesEmprunt(9);
	adherentA.setListeLivresEmpruntes(NULL);

	cout << "Nom et prénom : " << adherentA.getNom() << " " << adherentA.getPrenom() << endl;
	cout << "Adresse : " << adherentA.getAdresse() << endl;
	cout << "Numéro d'adhérent : " << adherentA.getNumeroAdherent() << endl;
	cout << "Inscrit dans la bibliothèque : " << adherentA.getBibliotheque() << endl;
	cout << "Autorisé(e) à emprunter jusqu'à " << adherentA.getNbLivresAutorisesEmprunt() << " livres" << endl;
	cout << "Livres en cours d'emprunt par cet adhérent : " << adherentA.getListeLivresEmpruntes() << endl;
	cout << "Les setter fonctionnent " << endl;
	cout << " " << endl;

	adherentA.setNom("Fischer");
	adherentA.setPrenom("Marion");
	adherentA.setAdresse("Klaq");
	adherentA.setNumeroAdherent(1);
	adherentA.setBibliotheque("Bibliothèque de Cinq Avenues");
	adherentA.setNbLivresAutorisesEmprunt(5);
	adherentA.setListeLivresEmpruntes(NULL);

	cout << "L'adhérent A a été réinitialisé sur Marion Fischer" << endl;

	cout << " " << endl << " " << " " << endl;
	cout << " " << endl << " " << " " << endl;








	cout << "Test de la fonction emprunte" << endl;

	adherentA.affiche();
	adherentA.emprunte(654987321); // finalement on va faire des codes livres à 9 chiffres car à partir de 10 chiffres on a
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
	adherentA.emprunte(456789123);
	adherentA.emprunte(789123465);
	adherentA.emprunte(987654321);
	adherentA.emprunte(654321987);
	cout << adherentA << endl;
	cout << "On devrait donc avoir le message d'avertissement de la fonction emprunt s'il y a un emprunt supplémentaire :" << endl;
	adherentA.emprunte(147258369);
	cout << "C'est bien le cas." << endl;
	cout << " " << endl;
	cout << adherentA << endl;


	cout << " " << endl << " " << " " << endl;
	cout << " " << endl << " " << " " << endl;

	cout << "Tests de la fonction rend" << endl;
	cout << "Devrait renvoyer que ce n'est pas emprunté :" << endl;
	adherentA.rend(111111111);
	cout << " " << endl;
	cout << "Devrait supprimer le livre donné (654987321) puis (789123465) de la liste des livres empruntes de l'adherent :" << endl;
	adherentA.rend(654987321);
	cout << adherentA << endl;
	cout << " " << endl;
	adherentA.rend(789123465);
	cout << adherentA << endl;


	cout << " " << endl << " " << " " << endl;
	cout << " " << endl << " " << " " << endl;


	cout << "Suite des tests des fonctions emprunte et rend" << endl;
	adherentB.rend(100000009);
	adherentB.emprunte(00000001);
	adherentB.emprunte(00000002);
	cout << adherentB << endl;
	cout << " " << endl;
	adherentB.rend(00000001);
	cout << adherentB << endl;
	cout << " " << endl;
	adherentB.rend(00000002);
	cout << adherentB << endl;
	cout << " " << endl;



}
