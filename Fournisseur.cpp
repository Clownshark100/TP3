/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 
* Auteur:
*******************************************/
#include "Fournisseur.h"

Fournisseur::Fournisseur(const string & nom, const string & prenom, int identifiant, const string & codePostal) : Usager(nom, prenom, identifiant, codePostal), satisfaction_{ {} }
{
}

vector<Produit*> Fournisseur::obtenirCatalogue() const
{
	return contenuCatalogue_;
}

Satisfaction Fournisseur::obtenirSatisfaction() const
{
	return satisfaction_;
}

void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{
	satisfaction_ = satisfaction;
}

void Fournisseur::noter(int appreciation)
{
	satisfaction_.niveaux_[appreciation]++;
}

void Fournisseur::ajouterProduit(Produit * produit)
{
	contenuCatalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit * produit)
{
	for (int i = 0; i < contenuCatalogue_.size(); i++) {
		if (contenuCatalogue_[i] == produit) {
			contenuCatalogue_.erase(contenuCatalogue_.begin() + i);
		}
	}
}

Fournisseur & Fournisseur::operator=(const Fournisseur & fournisseur)
{
	Usager::operator=(fournisseur);
	satisfaction_ = fournisseur.satisfaction_;
	contenuCatalogue_ = fournisseur.contenuCatalogue_;

	return *this;
}

ostream & operator<<(ostream & os, Fournisseur & fournisseur)
{
	os << static_cast<Usager&>(fournisseur);

	os << "\t notes:" << endl;

	for (int i = 0; i < NIVEAUX_SATISFACTION; i++) {

		cout << "\t\t" << i << ":" << fournisseur.satisfaction_.niveaux_[i] << endl;

	}
	return os;
}
