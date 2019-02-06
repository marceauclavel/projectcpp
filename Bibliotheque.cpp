/*
 * bibliotheque.cpp
 *
 *  Created on: 23 janv. 2019
 *      Author: mfischer
 */

#include "Bibliotheque.h"
#include "Livre.h"

#include <iostream>
#include <string>

Bibliotheque** bibliotheques = new Bibliotheque* [10];


using namespace std;


int Bibliotheque :: count = 1;




Bibliotheque :: Bibliotheque (string nom1, string adresse1) {
	nom = nom1;
	adresse = adresse1;
	code = count;
	listeLivresActuels = new Livre* [ 10 ];
	capaciteRestante = 10;
	nbrMaxAccueilLivres = 10;
	bibliotheques[count-1] = this;
	count ++;


}




ostream& operator<<(ostream& stream, const Bibliotheque&bib){
stream << "Fiche Bibliothèque" << endl
		<< "Nom : " << bib.nom << endl
		<< "Adresse : " << bib.adresse << endl
		<< "Code : " << bib.code << endl
		<< "Liste des livres actuels : " << '[';
for (int i=0; i<bib.nbrMaxAccueilLivres; i++){
	if (bib.listeLivresActuels[i] != nullptr){
	stream << "- " <<  bib.listeLivresActuels[i]->getTitre()<<" ";
	}
}
stream << "]" << endl
		<< "Capacité max de livres actuellement : " << bib.nbrMaxAccueilLivres << endl
		<< "Nombre de livres (empruntés ou non par un adhérent actuellement) : " << bib.nbrMaxAccueilLivres - bib.capaciteRestante << endl;

return stream;
}





void Bibliotheque :: afficherLivres() {

	cout << "Liste des livres de la bibliotheque " << nom << endl;
	for (int i=0; i<nbrMaxAccueilLivres; i++){
		if (listeLivresActuels[i] != nullptr){
			cout << listeLivresActuels[i]->getTitre() << endl;
		}

	}
	cout << "\n" << endl;
}

void Bibliotheque :: acheteLivre(Livre* livre){

	listeLivresActuels[10-capaciteRestante] = livre;
	capaciteRestante -- ;
}

void Bibliotheque :: supprimeLivre(int codeLivre){

	bool livreExiste = false;

	for (int i=0; i<nbrMaxAccueilLivres; i++){
		if (listeLivresActuels[i] != nullptr){
			if (listeLivresActuels[i]->getCode() == codeLivre){

				listeLivresActuels[i] = nullptr;
				livreExiste = true;
				cout << "Le livre a bien été supprimé\n" << endl;
			}
		}


		}
	if (livreExiste == false){
					cout << "Ce livre n'existe malheureusement pas dans cette bibliothèque :'( " << endl;
				}

}

void Bibliotheque :: demandeLivreA(Bibliotheque* bibliotheque, int isbn){

	for (int i=0; i< bibliotheque->nbrMaxAccueilLivres - bibliotheque->capaciteRestante ; i++){

		if (bibliotheque->listeLivresActuels[i] != nullptr){
			if (bibliotheque->listeLivresActuels[i]->getIsbn() == isbn and bibliotheque->listeLivresActuels[i]->getEtat() == "libre"){
				Livre* livre = bibliotheque->listeLivresActuels[i];
				int nouvelleBibliotheque = this->getCode();
				this->acheteLivre(livre);
				bibliotheque->supprimeLivre(bibliotheque->listeLivresActuels[i]->getCode());
				livre->setBibliothequeActuelle(nouvelleBibliotheque);


			}
			else {
				if (bibliotheque->listeLivresActuels[i]->getIsbn() == isbn and bibliotheque->listeLivresActuels[i]->getEtat() == "indisponible") {
					cout << "Ce livre est actuellement emprunté par un adhérent" << endl;
				}

			}
		}

	}

}

void Bibliotheque :: rendTousLesLivreA( Bibliotheque* bib){

	for (int i=0; i< this->nbrMaxAccueilLivres - this->capaciteRestante ; i++){

			if (this->listeLivresActuels[i] != nullptr){
				if (this->listeLivresActuels[i]->getBibliothequeOrigine() == bib->getCode() and this->listeLivresActuels[i]->getEtat() == "libre"){
					Livre* livre = this->listeLivresActuels[i];

					this->supprimeLivre(livre->getCode());
					bib->acheteLivre(livre);
					livre->setBibliothequeActuelle(bib->getCode());

				}
			}

		}


}


// getters et setters

const string& Bibliotheque :: getAdresse() const {
	return adresse;
}

void Bibliotheque :: setAdresse(const string& adresse) {
	this->adresse = adresse;
}

int Bibliotheque :: getCode() const {
	return code;
}

void Bibliotheque :: setCode(int code) {
	this->code = code;
}


const string& Bibliotheque :: getNom() const {
	return nom;
}

void Bibliotheque :: setNom(const string& nom) {
	this->nom = nom;
}

Livre** Bibliotheque :: getListeLivresActuels() {
	return listeLivresActuels;
	}

void Bibliotheque :: setListeLivresActuels(Livre**& listeLivresActuels) {
	this->listeLivresActuels = listeLivresActuels;
	}



void rendsTousLesLivres(Bibliotheque* bibl1){
	for (int i=0; i< Bibliotheque::count -1 ; i++){
		if(bibl1 != bibliotheques[i]){
			bibl1->rendTousLesLivreA(bibliotheques[i]);
		}
	}
}
