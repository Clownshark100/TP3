/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 26 fevrier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*******************************************/
#include "Fournisseur.h"
/**
* ¨Constructeur par parametres 
*/
Fournisseur::Fournisseur(const string & nom, const string & prenom, int identifiant, const string & codePostal) : Usager(nom, prenom, identifiant, codePostal), satisfaction_{ {0,0,0,0,0} }
{
}
/**
* accesseur de contenuCatalogue_.
*/
vector<Produit*> Fournisseur::obtenirCatalogue() const
{
	return contenuCatalogue_;
}
/**
* accesseur de satisfaction_.
*/
Satisfaction Fournisseur::obtenirSatisfaction() const
{
	return satisfaction_;
}
/**
* modificateur de satisfaction_.
*/
void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{
	satisfaction_ = satisfaction;
}
/**
* Incrémente le niveau de satisfaction du fournisseur
*/
void Fournisseur::noter(const int appreciation) 
{
	satisfaction_.niveaux_[appreciation]++;
}
/**
* ajoute un produit au catalogue
*/
void Fournisseur::ajouterProduit(Produit * produit)
{
	contenuCatalogue_.push_back(produit);
}
/**
* enleve un produit du catalogue
*/
void Fournisseur::enleverProduit(Produit * produit)
{
	for (int i = 0; i < contenuCatalogue_.size(); i++) {
		if (contenuCatalogue_[i] == produit) {
			contenuCatalogue_.erase(contenuCatalogue_.begin() + i);
		}
	}
}
/**
* copie les attributs d'un fournisseur en parametre au fournisseur.
*/
Fournisseur & Fournisseur::operator=(const Fournisseur & fournisseur)
{
	Usager::operator=(fournisseur);
	satisfaction_ = fournisseur.satisfaction_;
	contenuCatalogue_ = fournisseur.contenuCatalogue_;

	return *this;
}
/**
* affiche les attributs de fournisseur
*/
ostream & operator<<(ostream & os, Fournisseur & fournisseur)
{
	os << static_cast<Usager&>(fournisseur);

	os << "\t notes:" << endl;

	for (int i = 0; i < NIVEAUX_SATISFACTION; i++) {

		cout << "\t\t" << i << ":" << fournisseur.satisfaction_.niveaux_[i] << endl;

	}
	return os;
}
