/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date: 26 fevrier 2018
* Auteur: Loic leBlanc et Daniel Nahum
*******************************************/

#include "Panier.h"
using namespace std;
/**
* Constructeur par parametres
*/
Panier::Panier(int idClient) : idClient_(idClient) {

}
/**
* destucteur de panier, vide le contenu du panier
*/
Panier::~Panier()
{
	contenuPanier_.clear();
}

// methodes d'accès
/**
* accesseur de contenuPanier_.
*/
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}
/**
* accesseur du nombre de produits contenu dans panier
*/
int Panier::obtenirNombreContenu() const
{
	return (int)contenuPanier_.size();
}

/**
* accesseur de idClient_.
*/
int Panier::obtenirIdClient() const {
	return idClient_;
}
/**
* accesseur de totalAPayer.
*/
double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}

/**
* additionne le prix de tout les produits dans le panier et retourne le total.
*/
double Panier::calculerTotalApayer()  const
{

	double aPayer = totalAPayer_;

	 for (int i = 0; i < contenuPanier_.size(); i++) {
		 if (contenuPanier_[i]->retournerType() == TypeProduitAuxEncheres) {
			 if (idClient_ == static_cast<ProduitAuxEncheres*>(contenuPanier_[i])->obtenirIdentifiantClient()) {
				 aPayer += (contenuPanier_[i]->obtenirPrix());
			 }
		 }
	 }

	 return aPayer;
}


/**
* modification de totalAPayer_.
*/
void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}

/**
* modification de idClient 
*/
void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}



/**
* ajoute un produit au panier et additionne le prix du produit au total a payer.
*/
void Panier::ajouter(Produit * prod)
{
	if (prod->retournerType() == TypeProduitOrdinaire) {
		totalAPayer_ += prod->obtenirPrix();
		if (static_cast<ProduitOrdinaire*>(prod)->obtenirEstTaxable()) {
			totalAPayer_ += (prod->obtenirPrix() * TAUX_TAXE);
		}

	}

	contenuPanier_.push_back(prod);
}
/**
* vide le panier et remet le total a payer a 0.
*/
void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}
/**
* compare le prix des produits pour trouver le prix le plus cher
*/
Produit* Panier::trouverProduitPlusCher()
{
	if (contenuPanier_.empty())
		return nullptr;

	Produit* prodPlusChere = contenuPanier_[0];
	for (unsigned int i = 1; i < contenuPanier_.size(); i++)
		if (*contenuPanier_[i] > *prodPlusChere)
			prodPlusChere = contenuPanier_[i];

	return prodPlusChere;
}
/**
* permet d'afficher le contenu du panier.
*/
ostream & operator<<(ostream & os,  const Panier & panier)
{
	for (int i = 0; i < panier.contenuPanier_.size();i++) {
		if (panier.contenuPanier_[i]->retournerType() == 0)
			os << static_cast<const ProduitOrdinaire&>(*(panier.contenuPanier_[i]));
		else
			os << static_cast<const ProduitAuxEncheres&>(*(panier.contenuPanier_[i]));
	}
	return os;
}
