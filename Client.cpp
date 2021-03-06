/********************************************
* Titre: Travail pratique #3 - Client.cpp
* Date: 26 fevrier 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*******************************************/

#include "Client.h"
#include "Fournisseur.h"

/**
* Constructeur par parametres.
*/

Client::Client(const string & nom, const string & prenom, int identifiant, const string & codePostal, long date) : Usager(nom,prenom, identifiant, codePostal), dateNaissance_(date), monPanier_(nullptr)
{
}
/**
* destructeur de client, desalloue le panier du client.
*/
Client::~Client() 
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}
/**
* Constructeur par copie.
*/
Client::Client(const Client & client) :
	Usager(client.obtenirNom(), client.obtenirPrenom(), client.obtenirIdentifiant(), client.obtenirCodePostal()),	
	dateNaissance_{ client.dateNaissance_ }
{
	if (client.monPanier_ == nullptr)
		monPanier_ = nullptr;
	else {
		monPanier_ = new Panier(client.obtenirIdentifiant());
		for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
			monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
		}
		int idClient = this->obtenirIdentifiant();
		monPanier_->modifierTotalAPayer(client.monPanier_->obtenirTotalApayer());
	}
}


// Methodes d'acces
/**
* accesseur de dateNaissance_
*/
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}
/**
* accesseur de monPanier_
*/
Panier * Client::obtenirPanier() const
{
	return monPanier_;
}


// Methodes de modification
/**
* Modification de dateNaissance_
*/
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}
/**
* Ajoute un produit au panier.
*/
// Autres méthodes
void Client::acheter( ProduitOrdinaire * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(this->obtenirIdentifiant());
	monPanier_->ajouter(prod);
	// obtenir une note aléatoire
	int note = rand() % 5;

	// faire la mise à jour de la satisfaction au fournisseur
	prod->obtenirFournisseur().noter(note);
}
/**
* Vide le panier et le desalloue.
*/
void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}

/**
* Compare le montant miser au montant actuel et modifie le prix du produit et l'identifiant du client qui a mise.
*/
void Client::miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise) const {
	
	if (produitAuxEncheres->obtenirPrix() < montantMise) {
		produitAuxEncheres->modifierPrix(montantMise);
		produitAuxEncheres->modifierIdentifiantClient(obtenirIdentifiant());
	}

}
/**
* Affecte les informations personelles et le panier du client original a la nouvelle copie.
*/
Client & Client::operator=(const Client & client)
{
	if (this != &client) {
		this->modifierNom(client.obtenirNom());
		this->modifierPrenom(client.obtenirPrenom());
		this->modifierIdentifiant(client.obtenirIdentifiant());
		Usager temp(*this);
		temp = static_cast<Usager> (client);
		dateNaissance_ = client.obtenirDateNaissance();
		if (client.monPanier_ != nullptr) {
			delete monPanier_;
			monPanier_ = new Panier(obtenirIdentifiant());
			for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
				monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
			}
		}
		else
			monPanier_ = nullptr;
	}
	return *this;
}

/**
* Operateur d'affichage du client.
*/
ostream & operator<<(ostream & os, const Client & client)
{
	os << "Client: " << static_cast<Usager>(client) << endl;
	os << "Le panier de " << client.obtenirNom() << ":";

	if (client.monPanier_ == nullptr) {
		os << " est vide!" << endl;
	}
	else {
		os << endl << *(client.monPanier_);
	}


	return os;
}
