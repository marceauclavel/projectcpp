/*
 * SousClasses.h
 *
 *  Created on: 15 janv. 2019
 *      Author: mclavel
 */

#ifndef SOUSCLASSES_H_
#define SOUSCLASSES_H_

#include "Livre.h"
#include <iostream>
#include <string>

class BD : public Livre {

protected :
	string dessinateur;

public :
	BD(string titre1, string auteur1, string editeur1, int isbn1, int bibliothequeOrigine1, int bibliothequeActuelle1, string dessinateur1, string publicVise1 = "tout public", string etat1 = "libre");
	virtual ~BD();

	const string& getDessinateur() const;
	void setDessinateur(const string& dessinateur);
	void affiche();

};

class RecueilPoesie : public Livre {

protected :
	string indicateur;

public :
	RecueilPoesie(string titre1, string auteur1, string editeur1, int isbn1, int bibliothequeOrigine1, int bibliothequeActuelle1, string indicateur1, string publicVise1 = "tout public", string etat1 = "libre");
	virtual ~RecueilPoesie();

	const string& getIndicateur() const;
	void setIndicateur(const string& indicateur);
	void affiche();

};

class Roman : public Livre {

protected :
	string genre;

public :
	Roman(string titre1, string auteur1, string editeur1, int isbn1, int bibliothequeOrigine1, int bibliothequeActuelle1, string genre1, string publicVise1 = "tout public", string etat1 = "libre");
	virtual ~Roman();

	const string& getGenre() const;
	void setGenre(const string& genre);
	void affiche();

};

class PieceDeTheatre : public Livre {

protected :
	string siecle;

public :
	PieceDeTheatre(string titre1, string auteur1, string editeur1, int isbn1, int bibliothequeOrigine1, int bibliothequeActuelle1, string siecle1, string publicVise1 = "tout public", string etat1 = "libre");
	virtual ~PieceDeTheatre();

	const string& getSiecle() const;
	void setSiecle(const string& siecle);
	void affiche();

};


class Album : public Livre {

protected :
	string type;

public :
	Album(string titre1, string auteur1, string editeur1, int isbn1, int bibliothequeOrigine1, int bibliothequeActuelle1, string type1, string publicVise1 = "tout public", string etat1 = "libre");
	virtual ~Album();

	const string& getType() const;
	void setType(const string& type);
	void affiche();

};








#endif /* SOUSCLASSES_H_ */
