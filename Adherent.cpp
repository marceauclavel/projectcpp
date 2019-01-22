/*
 * adherent.cpp
 *
 *  Created on: 15 janv. 2019
 *      Author: mfischer
 */


#include "Adherent.h"

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Adherent :: count = 0;

Adherent :: Adherent ( string nom1, string prenom1, string adresse1, string bibliotheque1, int nbLivresAutorisesEmprunt1) {
	nom = nom1;
	prenom = prenom1;
	adresse = adresse1;
	numeroAdherent = count + 1;
	bibliotheque = bibliotheque1;
	nbLivresAutorisesEmprunt = nbLivresAutorisesEmprunt1;
	listeLivresEmpruntes = new int [ nbLivresAutorisesEmprunt ];
	//listeLivresEmpruntes = NULL;
	nbLivresEmpruntes = 0;
	count++;
}


ostream& operator<<(ostream& stream, const Adherent&adh){
stream << "Fiche Adhérent" << endl
		<< "Nom et prénom : " << adh.nom << " " << adh.prenom << endl
		<< "Adresse : " << adh.adresse << endl
		<< "Numéro d'adhérent : " << adh.numeroAdherent << endl
		<< "Inscrit dans la bibliothèque : " << adh.bibliotheque << endl
		<< "Autorisé(e) à emprunter jusqu'à " << adh.nbLivresAutorisesEmprunt << " livres" << endl
		<< "Emprunte actuellement " << adh.nbLivresEmpruntes << " livre(s)" << endl
		<< "Livres en cours d'emprunt par cet adhérent : " << '[';
for (int i=0; i<adh.nbLivresAutorisesEmprunt; i++){
	stream << adh.listeLivresEmpruntes[i]<<" ";
}
stream << "]" << endl;
return stream;
}

//		<< " " << endl
//
//		v.taille << endl << '[';
//for (int i=0; i<v.taille; i++){
//	stream << v.coordonnees[i]<<" ";
//}
//stream << "]" << endl;
//return stream;
//}



void Adherent :: affiche() {

	cout << "Nom et prénom : " << nom << " " << prenom << endl;
	cout << "Adresse : " << adresse << endl;
	cout << "Numéro d'adhérent : " << numeroAdherent << endl;
	cout << "Inscrit dans la bibliothèque : " << bibliotheque << endl;
	cout << "Autorisé(e) à emprunter jusqu'à " << nbLivresAutorisesEmprunt << " livres" << endl;
	cout << "Livres en cours d'emprunt par cet adhérent : " << listeLivresEmpruntes << endl;
	cout << " " << endl;
}


void Adherent :: emprunte(int codeLivre) {
	if (nbLivresEmpruntes < nbLivresAutorisesEmprunt) {
		listeLivresEmpruntes[ nbLivresEmpruntes ] = codeLivre;
		nbLivresEmpruntes ++;
	} else {
		cout << "Nombre maximal de livres empruntés autorisés déjà atteint" << endl;
	};
}



void Adherent :: rend(int codeLivre) {
	// On va d'abord vérifier si le livre est effectivement emprunté par l'utilisateur :

	int verifieEmprunt = 0;
	int position = 0; // Si le livre est actuellement emprunté, on veut savoir sa position dans la liste des livres empruntes
	for (int i=0; i< nbLivresAutorisesEmprunt; i=i+1){
		if (codeLivre == listeLivresEmpruntes[i]) {
		verifieEmprunt ++;
		position = i;
		}
	}

	// Si le livre n'est pas actuellement emprunté par l'adhérent, on le signale :
	if (verifieEmprunt == 0) {
		cout << "Ce livre n'est pas actuellement emprunté par cet adhérent" << endl;
	}


	// Si le livre est effectivement actuellement emprunté par l'adhérent :
	else {
		listeLivresEmpruntes[ position ] = listeLivresEmpruntes[ nbLivresEmpruntes -1 ];
		listeLivresEmpruntes[ nbLivresEmpruntes -1 ] = 0;
		nbLivresEmpruntes --;
	}

}

//	bool found = (std::find(*listeLivresEmpruntes.begin(), *listeLivresEmpruntes.end(), codeLivre) != *listeLivresEmpruntes.end());
//	// permet de savoir si le livre est effectivement emprunté par l'adhérent actuellement


//	if (found == false) {
//		cout << "Ce livre n'est pas actuellement emprunté par cet adhérent" << endl;
//	}
//
//
//	else {
//		int listeLivresEmpruntesIntermediaire = new int [ nbLivresAutorisesEmprunt ];
//		for (int i=0; i< nbLivresAutorisesEmprunt; i=i+1){
//			int d = 0;
//			if (codeLivre != listeLivresEmpruntes[i]){
//				listeLivresEmpruntesIntermediaire[d] = listeLivresEmpruntes[i];
//				d ++;
//			} // fermeture if
//		} // fermeture for
//		*listeLivresEmpruntes = listeLivresEmpruntesIntermediaire;
//		nbLivresEmpruntes --;
//	}
//
//};




// getters and setters


const string& Adherent :: getAdresse() const {
	return adresse;
}

void Adherent :: setAdresse(const string& adresse) {
	this->adresse = adresse;
}

const string& Adherent :: getBibliotheque() const {
	return bibliotheque;
}

void Adherent :: setBibliotheque(const string& bibliotheque) {
	this->bibliotheque = bibliotheque;
}

int* Adherent :: getListeLivresEmpruntes() const {
	return listeLivresEmpruntes;
}

void Adherent :: setListeLivresEmpruntes(int* listeLivresEmpruntes1) {
	this->listeLivresEmpruntes = listeLivresEmpruntes;
}

int Adherent :: getNbLivresAutorisesEmprunt() const {
	return nbLivresAutorisesEmprunt;
}

void Adherent :: setNbLivresAutorisesEmprunt(int nbLivresAutorisesEmprunt) {
	this->nbLivresAutorisesEmprunt = nbLivresAutorisesEmprunt;
}

const string& Adherent :: getNom() const {
	return nom;
}

void Adherent :: setNom(const string& nom) {
	this->nom = nom;
}

int Adherent :: getNumeroAdherent() const {
	return numeroAdherent;
}

void Adherent :: setNumeroAdherent(int numeroAdherent) {
	this->numeroAdherent = numeroAdherent;
}

const string& Adherent :: getPrenom() const {
	return prenom;
}

void Adherent :: setPrenom(const string& prenom) {
	this->prenom = prenom;
}



