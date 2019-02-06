/*
 * Bibliotheque.h
 *
 *  Created on: 23 janv. 2019
 *      Author: mfischer
 */

#ifndef BIBLIOTHEQUE_H_
#define BIBLIOTHEQUE_H_

#include <iostream>
#include <string>

#include "Livre.h"
#include "SousClasses.h"

using namespace std;


class Bibliotheque {

protected :
	string nom;
	string adresse;
	int code;
	Livre** listeLivresActuels;
	int nbrMaxAccueilLivres;
	int capaciteRestante;



public :



	Bibliotheque (string nom1= "Unknown", string adresse1 = "Unknown");


	friend ostream& operator<< (ostream&stream, const Bibliotheque&bib);

	int static count;

	void afficherLivres();
	void acheteLivre(Livre* livre);
	void supprimeLivre(int codeLivre);
	void demandeLivreA(Bibliotheque* bibliotheque, int isbn);
	void rendTousLesLivreA( Bibliotheque* bib);


	// getters et setters

	const string& getAdresse() const;
	void setAdresse(const string& adresse);
	int getCode() const;
	void setCode(int code);

	const string& getNom() const;
	void setNom(const string& nom);

	Livre** getListeLivresActuels();
	void setListeLivresActuels(Livre**& listeLivresActuels);


};


void rendsTousLesLivres(Bibliotheque* bibl1);


#endif /* BIBLIOTHEQUE_H_ */
