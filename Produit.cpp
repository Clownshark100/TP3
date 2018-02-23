/********************************************
* Titre: Travail pratique #3 - Produit.cpp
* Date: 25 fevrier 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*******************************************/

#include "Produit.h"
/**
* Constructeur par parametres et par défault.
*/
Produit::Produit(Fournisseur& fournisseur,const string& nom, int reference, double prix,TypeProduit type): fournisseur_(fournisseur),nom_(nom), reference_(reference), prix_(prix), type_(type) {
	fournisseur_.ajouterProduit(this);
}

/**
* Destructeur de produit, retire le produit du catalogue de fournisseur.
*/
Produit::~Produit() {
	fournisseur_.enleverProduit(this);
}

// Methodes d'acces
/**
* accesseur de nom_.
*/
string Produit::obtenirNom() const
{
	return nom_;
}
/**
* accesseur de reference_.
*/
int Produit::obtenirReference() const
{
	return reference_;
}
/**
* accesseur de prix_.
*/
double Produit::obtenirPrix() const
{
	return prix_;
}
/**
* accesseur de fournisseur_.
*/
Fournisseur& Produit::obtenirFournisseur() const
{
	return fournisseur_;
}
/**
* accesseur de type_.
*/
TypeProduit Produit::retournerType() {
	return type_;
}

// Methodes de modification
/**
* modification de nom_.
*/
void Produit::modifierNom(const string& nom)
{
	nom_ = nom;
}
/**
* modification de reference_.
*/
void Produit::modifierReference(int reference)
{
	reference_ = reference;
}
/**
* modification de prix_.
*/
void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}

/**
* Vérifie si le prix du produit plus grand que le prix d'un produit passe en parametre
*/
bool Produit::operator>(const Produit & produit) const
{
	return prix_ > produit.prix_;
}
/**
* Vérifie si le prix du produit plus petit que le prix d'un produit passe en parametre
*/
bool Produit::operator<(const Produit & produit) const
{
	return prix_ < produit.prix_;
}
/**
* Permet de comparer les attributs de produit et du produit en parametre
*/
bool Produit::operator==(const Produit & produit) const
{
	return (nom_ == produit.nom_ &&
			prix_ == produit.prix_ &&
			reference_ == produit.reference_);
}
// pour lire un type enumeré
inline istream & operator >> (istream & is, TypeProduit & typeProduit) {
	unsigned int type = 0;
	if (is >> type)
		typeProduit = static_cast<TypeProduit>(type);
	return is;
}
/**
* Permet de écrire l'information du produit en parametre en cascade.
*/
istream & operator>>(istream & is, Produit & produit)
{
	return is >> produit.nom_ >> produit.reference_ >> produit.prix_ >> produit.type_;
}
/**
* affiche les informations du produit
*/
ostream & operator<<(ostream & os, const Produit & produit)
{
	 os << "Produit :"
		 << " nom: " << produit.obtenirNom() << endl
		 << " \t \t ref : " << produit.obtenirReference() << endl
		 << " \t \t prix actuel : " << produit.obtenirPrix() << endl
		 << "\t Fournisseur " << produit.obtenirFournisseur().obtenirNom() << endl;
	 return os;
}


