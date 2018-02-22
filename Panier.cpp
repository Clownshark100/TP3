/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Panier.h"
using namespace std;

Panier::Panier(int idClient) : idClient_(idClient) {

}


Panier::~Panier()
{
	contenuPanier_.clear();
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return (int)contenuPanier_.size();
}


int Panier::obtenirIdClient() const {
	return idClient_;
}

double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}


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



void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}




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

void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

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
