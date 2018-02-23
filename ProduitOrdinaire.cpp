/********************************************
* Titre: Travail pratique #3 - ProduitOrdinaire.h
* Date: 26 Fevrier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*******************************************/


#include <string>
#include <iostream>
#include "ProduitOrdinaire.h"
#include "Fournisseur.h"
using namespace std;
/**
* Constructeur par parametres et par default
*/
ProduitOrdinaire::ProduitOrdinaire(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type, bool estTaxable): Produit(fournisseur,nom,reference,prix,type), estTaxable_(estTaxable)
{
}
/**
* Accesseur de estTaxable_.
*/
bool ProduitOrdinaire::obtenirEstTaxable() const
{
	return estTaxable_;
}
/**
*Modificateur de estTaxable_.
*/
void ProduitOrdinaire::modifierEstTaxable(bool estTaxable)
{
	estTaxable_ = estTaxable;
}
/**
* Surcharge d'operateur de lecture d'un produitOrdinaire.
*/
ostream & operator<<(ostream & os, const ProduitOrdinaire & produit)
{
	os << "Produit Ordinaire " << static_cast<const Produit&>(produit);
	if (produit.obtenirEstTaxable())
		os << "est Taxable : true" << endl;
	else
		os << "est Taxable : false" << endl;
	return os;
}
/**
* Surcharge d'operateur d'ecriture d'un produitOrdinaire.
*/
istream & operator >> (istream & is, ProduitOrdinaire & produit)
{
	return is >> static_cast<Produit&>(produit) >> produit.estTaxable_;
}
