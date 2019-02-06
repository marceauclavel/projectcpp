/*
 * livre.h
 *
 *  Created on: Jan 15, 2019
 *      Author: marceauclavel
 */

#ifndef LIVRE_H_
#define LIVRE_H_

#include <string>

using namespace std;

class Livre {

protected:

	int code;
	string auteur;
	string titre;
	string editeur;
	int isbn;
	string publicVise;
	string etat;
	int bibliothequeOrigine;
	int bibliothequeActuelle;

public:

	int static count;

	Livre(string titre1, string auteur1, string editeur1, int isbn1, int bibliothequeOrigine1, int bibliothequeActuelle1, string publicVise1 = "tout public", string etat1 = "libre");
	virtual ~Livre();

	friend ostream& operator<< (ostream&stream, const Livre&v);

	Livre();
	Livre(const Livre&l, int nouvelleBibliotheque);


	void affiche();



	const string& getAuteur() const;
	void setAuteur(const string& auteur);

	int getBibliothequeActuelle() const;
	void setBibliothequeActuelle(int bibliothequeActuelle);

	int getBibliothequeOrigine() const;
	void setBibliothequeOrigine(int bibliothequeOrigine);

	int getCode() const;
	void setCode(int code);

	const string& getEditeur() const;
	void setEditeur(const string& editeur);

	const string& getEtat() const;
	void setEtat(const string& etat);

	int getIsbn() const;
	void setIsbn(int isbn);

	const string& getPublicVise() const;
	void setPublicVise(const string& publicVise);

	string getTitre() const;
	void setTitre(const string& titre);



};



#endif /* LIVRE_H_ */
