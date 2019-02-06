/*
 * Exemple.cpp
 *
 *  Created on: 24 janv. 2019
 *      Author: mfischer
 */

#include "tests.h"
#include "Adherent.h"
#include "Bibliotheque.h"
#include "Livre.h"

int exemple(){

	Bibliotheque alcazar = Bibliotheque("l'Alcazar BMVR", "58 Cours Belsunce, 13001 Marseille");
	Bibliotheque bibliotheque5av = Bibliotheque("Bibliothèque de 5 Avenue", "2 Impasse de l'Abbé Charles Marie Joseph Fissiaux, 13004 Marseille");
	Bibliotheque bibliothequeVP = Bibliotheque("Bibliothèque VieuxPort","VP - Marseille 13001");

	Livre livre1 = Livre("La Quête d'Ewilan", "Pierre Bottero", "Flammarion", 978104, alcazar.getCode(), alcazar.getCode(), "tout public", "libre");
	Livre livre2 = Livre("Harry Potter et la Chambre des Secrets", "JK Rowling", "Flammarion", 978080, alcazar.getCode(), alcazar.getCode(), "tout public", "libre");
	Livre livre3 = Livre("Le Comte de Monte-Cristo", "Alexandre Dumas", "Flammarion", 978957, bibliotheque5av.getCode(), bibliotheque5av.getCode(), "tout public", "libre");
	Livre livre4 = Livre("Jack et le Haricot magique", "Unknown", "Flammarion", 978853, bibliotheque5av.getCode(), bibliotheque5av.getCode(), "tout public", "libre");
	Livre livre5 = Livre("Le Portrait de Dorian Gray", "Oscar Wilde", "Flammarion", 978154, bibliothequeVP.getCode(), bibliothequeVP.getCode(), "tout public", "libre");
	Livre livre6 = Livre("La Trilogie des Charmettes", "Eric Boisset", "Flammarion", 978221, bibliothequeVP.getCode(), bibliothequeVP.getCode(), "tout public", "libre");

	alcazar.acheteLivre(&livre1);
	alcazar.acheteLivre(&livre2);
	bibliotheque5av.acheteLivre(&livre3);
	bibliotheque5av.acheteLivre(&livre4);
	bibliothequeVP.acheteLivre(&livre5);
	bibliothequeVP.acheteLivre(&livre6);

	cout << "\nVoici la liste de bibliothèques :\n" << endl;
	cout << alcazar << endl;
	cout << bibliotheque5av << endl;
	cout << bibliothequeVP << endl;

	Adherent adherent1 = Adherent("Mayol", "Jacques", "42 rue des profondeurs", alcazar, 6);
	Adherent adherent2 = Adherent("Fischer","Marion","Klaq",alcazar);
	Adherent adherent3 = Adherent("Clavel", "Marceau","Octoloc",bibliotheque5av, 6);
	Adherent adherent4 = Adherent("Amat","Hugo","Mouga",bibliothequeVP);

	cout << "\nVoici la liste des adhérents :\n" << endl;
	cout << adherent1 << endl;
	cout << adherent2 << endl;
	cout << adherent3 << endl;
	cout << adherent4 << endl;

	cout << "\n Les adhérents empruntent des livres dans leur bibliothèque \n" << endl;

	adherent1.emprunte(&livre1);
	adherent1.emprunte(&livre2);
	adherent3.emprunte(&livre3);

	cout << "\nVoici la liste des adhérents après emprunts:\n" << endl;
	cout << adherent1 << endl;
	cout << adherent2 << endl;
	cout << adherent3 << endl;
	cout << adherent4 << endl;

	cout << "\nUn adhérent essaye d'emprunter un livre qui n'est pas dans sa bibliothèque favorite\n" << endl;

	adherent4.emprunte(&livre4);

	cout << "\n La bibliothèque VieuxPort demande alors à la bibliothèque 5 avenue de lui prêter le livre 4\n " << endl;

	bibliotheque5av.afficherLivres();
	bibliothequeVP.afficherLivres();

	bibliothequeVP.demandeLivreA(&bibliotheque5av, livre4.getIsbn());

	bibliotheque5av.afficherLivres();
	bibliothequeVP.afficherLivres();

	cout << "Désormais, l'adhérent4 peut emprunter le livre 4 dans sa bibliothèque favorite !\n" << endl;

	adherent4.emprunte(&livre4);

	cout << adherent4 << endl;

	cout << "\n L'adhérent 4 rend le livre 4 après l'avoir lu \n" << endl;

	adherent4.rend(&livre4);

	cout << adherent4 << endl;

	cout << "\n La bibliothèque VieuxPort emprunte un livre à la bibliothèque Alcazar mais il est indisponible actuellement ! \n" << endl;

	bibliothequeVP.demandeLivreA(&alcazar, livre1.getIsbn());

	cout << "\n L'adhérent 1 rend le livre 1, la bibliothèque VieuxPort peut donc l'emprunter \n" << endl;

	adherent1.rend(&livre1);
	bibliothequeVP.demandeLivreA(&alcazar, livre1.getIsbn());
	bibliothequeVP.afficherLivres();

	cout << "\n La bibliothèque VieuxPort est dépassée par son nombre de livres, elle décide de rendre tous les livres empruntés \n" << endl;

	alcazar.afficherLivres();
	bibliotheque5av.afficherLivres();
	bibliothequeVP.afficherLivres();

	rendsTousLesLivres(&bibliothequeVP);

	alcazar.afficherLivres();
	bibliotheque5av.afficherLivres();
	bibliothequeVP.afficherLivres();


	return 1;
}



