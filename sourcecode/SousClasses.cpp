/*
 * SousClasses.cpp
 *
 *  Created on: 15 janv. 2019
 *      Author: mclavel
 */

#include "SousClasses.h"
#include <string>

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
