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


using namespace std;


class Adherent {

protected :
	string nom;
	string prenom;
	string adresse;
	int numeroAdherent;
	string bibliotheque;
	int nbLivresAutorisesEmprunt ;
	// int* listeLivresEmpruntes = new int[ nbLivresAutorisesEmprunt ];
	int *listeLivresEmpruntes;
	int nbLivresEmpruntes;




public :
	Adherent ( string nom1, string prenom1, string adresse1, string bibliotheque1, int nbLivresAutorisesEmprunt1 = 5);

	friend ostream& operator<< (ostream&stream, const Adherent&v);

	void affiche();
	void emprunte(int codeLivre);
	void rend(int codeLivre);

	int static count;


	// getters and setters

	const string& getAdresse() const;
	void setAdresse(const string& adresse);
	const string& getBibliotheque() const;
	void setBibliotheque(const string& bibliotheque);
	int* getListeLivresEmpruntes() const;
	void setListeLivresEmpruntes(int* listeLivresEmpruntes);
	int getNbLivresAutorisesEmprunt() const;
	void setNbLivresAutorisesEmprunt(int nbLivresAutorisesEmprunt);
	const string& getNom() const;
	void setNom(const string& nom);
	int getNumeroAdherent() const;
	void setNumeroAdherent(int numeroAdherent);
	const string& getPrenom() const;
	void setPrenom(const string& prenom);


};








#endif /* ADHERENT_H_ */
