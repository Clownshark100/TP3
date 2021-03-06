/********************************************
* Titre: Travail pratique #3 - Fournisseur.h
* Date: 26 fevrier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
* Fournisseur est un usager qui contient un catalogue de produits et l'appreciation du fournisseur.
*******************************************/

#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
const int NIVEAUX_SATISFACTION = 5;
struct Satisfaction {
	int niveaux_[NIVEAUX_SATISFACTION];
};

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"
using namespace std;
class Produit;
class Fournisseur : public Usager
{
public:
	Fournisseur(const string&  nom, const string& prenom, int identifiant, const string& codePostal);
		
	vector<Produit*> obtenirCatalogue() const;
	Satisfaction obtenirSatisfaction() const;
	
	void modifierSatisfaction(Satisfaction satisfaction);	
	void noter(const int appreciation);

	void ajouterProduit(Produit* produit);
	void enleverProduit(Produit* produit);	
	Fournisseur& operator=(const Fournisseur& fournisseur);

	friend ostream& operator<<(ostream & os, Fournisseur& fournisseur);

private:
	Satisfaction satisfaction_;
	vector<Produit*> contenuCatalogue_;	
};

#endif