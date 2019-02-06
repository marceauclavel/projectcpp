/*
 * SousClasses.cpp
 *
 *  Created on: 15 janv. 2019
 *      Author: mclavel
 */

#include "SousClasses.h"
#include <string>

/* CLASSE BD */

BD::BD(string titre1, string auteur1, string editeur1, int isbn1, int bibliothequeOrigine1, int bibliothequeActuelle1, string dessinateur1, string publicVise1 , string etat1):Livre(titre1, auteur1, editeur1, isbn1, bibliothequeOrigine1, bibliothequeActuelle1, publicVise1, etat1){

	dessinateur = dessinateur1;

}

BD::~BD(){

}

const string& BD::getDessinateur() const {
	return dessinateur;
}

void BD::setDessinateur(const string& dessinateur) {
	this->dessinateur = dessinateur;
}

void BD::affiche(){
	Livre::affiche();
	cout << " Ce livre est une BD et le dessinateur est" << dessinateur << endl;
}


/* CLASSE RECUEILPOESIE */

RecueilPoesie::RecueilPoesie(string titre1, string auteur1, string editeur1, int isbn1, int bibliothequeOrigine1, int bibliothequeActuelle1, string indicateur1, string publicVise1 , string etat1):Livre(titre1, auteur1, editeur1, isbn1, bibliothequeOrigine1, bibliothequeActuelle1, publicVise1, etat1){

	indicateur = indicateur1;

}

RecueilPoesie::~RecueilPoesie(){

}

const string& RecueilPoesie::getIndicateur() const {
	return indicateur;
}

void RecueilPoesie::setIndicateur(const string& indicateur) {
	this->indicateur = indicateur;
}

void RecueilPoesie::affiche(){
	Livre::affiche();
	cout << " Ce livre est un recueil de poésie, écrit en " << indicateur << endl;
}


/* CLASSE ROMAN */

Roman::Roman(string titre1, string auteur1, string editeur1, int isbn1, int bibliothequeOrigine1, int bibliothequeActuelle1, string genre1, string publicVise1 , string etat1):Livre(titre1, auteur1, editeur1, isbn1, bibliothequeOrigine1, bibliothequeActuelle1, publicVise1, etat1){

	genre = genre1;

}

Roman::~Roman(){

}

const string& Roman::getGenre() const {
	return genre;
}

void Roman::setGenre(const string& genre) {
	this->genre = genre;
}

void Roman::affiche(){
	Livre::affiche();
	cout << " Ce livre est un roman de genre " << genre << endl;
}



/* CLASSE PIECEDETHEATRE */

PieceDeTheatre::PieceDeTheatre(string titre1, string auteur1, string editeur1, int isbn1, int bibliothequeOrigine1, int bibliothequeActuelle1, string siecle1, string publicVise1 , string etat1):Livre(titre1, auteur1, editeur1, isbn1, bibliothequeOrigine1, bibliothequeActuelle1, publicVise1, etat1){

	siecle = siecle1;

}

PieceDeTheatre::~PieceDeTheatre(){

}

const string& PieceDeTheatre::getSiecle() const {
	return siecle;
}

void PieceDeTheatre::setSiecle(const string& siecle) {
	this->siecle = siecle;
}

void PieceDeTheatre::affiche(){
	Livre::affiche();
	cout << " Ce livre est une pièce de théatre, datant du siècle " << siecle << endl;
}

/* CLASSE ALBUM */

Album::Album(string titre1, string auteur1, string editeur1, int isbn1, int bibliothequeOrigine1, int bibliothequeActuelle1, string type1, string publicVise1 , string etat1):Livre(titre1, auteur1, editeur1, isbn1, bibliothequeOrigine1, bibliothequeActuelle1, publicVise1, etat1){

	type = type1;

}

Album::~Album(){

}

const string& Album::getType() const {
	return type;
}

void Album::setType(const string& type) {
	this->type = type;
}

void Album::affiche(){
	Livre::affiche();
	cout << " Ce livre est un Album de type " << type << endl;
}
