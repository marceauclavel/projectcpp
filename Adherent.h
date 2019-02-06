/*
 * adherent.h
 *
 *  Created on: 15 janv. 2019
 *      Author: mfischer
 */

#ifndef ADHERENT_H_
#define ADHERENT_H_

#include <iostream>
#include <string>

#include "Bibliotheque.h"


using namespace std;


class Adherent {

protected :
	string nom;
	string prenom;
	string adresse;
	int numeroAdherent;
	Bibliotheque bibliotheque;
	int nbLivresAutorisesEmprunt ;
	Livre* listeLivresEmpruntes;
	int nbLivresEmpruntes;




public :
	Adherent ( string nom1, string prenom1, string adresse1, Bibliotheque bibliotheque1, int nbLivresAutorisesEmprunt1 = 5);

	friend ostream& operator<< (ostream&stream, const Adherent&v);

	void affiche(); // finalement on ne l'utilisera pas car elle affiche l'adresse et non le contenu de la liste de livres empruntés
	void emprunte(Livre* livre);
	void rend(Livre* livre);

	int static count;


	// getters and setters

	const string& getAdresse() const;
	void setAdresse(const string& adresse);
	const Livre* getListeLivresEmpruntes() const;
	void setListeLivresEmpruntes(Livre* listeLivresEmpruntes);
	int getNbLivresAutorisesEmprunt() const;
	void setNbLivresAutorisesEmprunt(int nbLivresAutorisesEmprunt);
	const string& getNom() const;
	void setNom(const string& nom);
	int getNumeroAdherent() const;
	void setNumeroAdherent(int numeroAdherent);
	const string& getPrenom() const;
	void setPrenom(const string& prenom);
	const Bibliotheque getBibliotheque() const;
	void setBibliotheque(const Bibliotheque& bibliotheque);


};



#endif /* ADHERENT_H_ */
