/*
 * SousClasses.h
 *
 *  Created on: 15 janv. 2019
 *      Author: mclavel
 */

#ifndef SOUSCLASSES_H_
#define SOUSCLASSES_H_

#include "livre.h"
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

};




#endif /* SOUSCLASSES_H_ */
