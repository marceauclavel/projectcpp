/*
 * livre.cpp
 *
 *  Created on: Jan 15, 2019
 *      Author: marceauclavel
 */


#include "livre.h"
#include <string>
#include <iostream>

using namespace std;

int Livre::count = 0;


Livre::Livre(string titre1, string auteur1, string editeur1, int isbn1, int bibliothequeOrigine1, int bibliothequeActuelle1, string publicVise1, string etat1){

	count ++;

	titre = titre1;
	code = count;
	auteur = auteur1;
	editeur = editeur1;
	isbn = isbn1;
	bibliothequeOrigine = bibliothequeOrigine1;
	bibliothequeActuelle = bibliothequeActuelle1;
	publicVise = publicVise1;
	etat = etat1;

}

Livre::~Livre(){

}

void Livre::affiche(){
	cout << "\n " << getTitre() << ", écrit par " << getAuteur() << " aux éditions " << getEditeur() << ".\n Son numéro d'ISBN est: " << getIsbn() << " et c'est un livre pour les " << getPublicVise() << endl;
}


/*  GETTERS AND SETTERS  */


const string& Livre::getAuteur() const {
		return auteur;
	}

	void Livre::setAuteur(const string& auteur) {
		this->auteur = auteur;
	}

	int Livre::getBibliothequeActuelle() const {
		return bibliothequeActuelle;
	}

	void Livre::setBibliothequeActuelle(int bibliothequeActuelle) {
		this->bibliothequeActuelle = bibliothequeActuelle;
	}

	int Livre::getBibliothequeOrigine() const {
		return bibliothequeOrigine;
	}

	void Livre::setBibliothequeOrigine(int bibliothequeOrigine) {
		this->bibliothequeOrigine = bibliothequeOrigine;
	}

	int Livre::getCode() const {
		return code;
	}

	void Livre::setCode(int code) {
		this->code = code;
	}

	const string& Livre::getEditeur() const {
		return editeur;
	}

	void Livre::setEditeur(const string& editeur) {
		this->editeur = editeur;
	}

	const string& Livre::getEtat() const {
		return etat;
	}

	void Livre::setEtat(const string& etat) {
		this->etat = etat;
	}

	int Livre::getIsbn() const {
		return isbn;
	}

	void Livre::setIsbn(int isbn) {
		this->isbn = isbn;
	}

	const string& Livre::getPublicVise() const {
		return publicVise;
	}

	void Livre::setPublicVise(const string& publicVise) {
		this->publicVise = publicVise;
	}

	const string& Livre::getTitre() const {
		return titre;
	}

	void Livre::setTitre(const string& titre) {
		this->titre = titre;
	}


