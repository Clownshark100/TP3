/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 26 fevrier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*******************************************/

#include "ProduitAuxEncheres.h"
/**
* Constructeur par parametres et par default
*/
ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type):Produit(fournisseur, nom, reference, prix, type), prixBase_(0), identifiantClient_(0)
{
}

/**
* Accesseur de identifiantClient_.
*/
int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
	return identifiantClient_;
}
/**
* Accesseur de prixBase_.
*/
double ProduitAuxEncheres::obtenirPrixBase() const
{
	return prixBase_;
}
/**
* Modificateur de identifiantClient_.
*/
void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
	identifiantClient_ = identifiantClient;
}
/**
* Modificateur de prixBase_.
*/
void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
	prixBase_ = prixBase;
}
/**
* Surcharge d'operateur d'ecriture de produit en cascade 
*/
istream & operator >> (istream & is, ProduitAuxEncheres & produit)
{
	return is >> static_cast<Produit&>(produit);
}
/**
* Surcharge d'perateur de lecture de produit aux encheres en cascade
*/
ostream & operator<<(ostream & os, const ProduitAuxEncheres & produit)
{
	os << "Produit aux Encheres " << static_cast<const Produit&>(produit)
		<< "Prix de base " << produit.obtenirPrixBase() << endl
		<< "Identifiant Client " << produit.obtenirIdentifiantClient() << endl;
	return os;
}
