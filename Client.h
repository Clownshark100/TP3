/********************************************
* Titre: Travail pratique #3 - Client.h
* Date: 26 fevrier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
* La classe client est un usager qui a des informations personnelles et qui peut acheter et miser sur des produits.
*******************************************/

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Usager.h"
#include "Panier.h"
#include "ProduitOrdinaire.h"
#include "ProduitAuxEncheres.h"

using namespace std;
class Client : public Usager
{

public:
	Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) ;
	~Client();
	Client(const Client& client);
	
	long obtenirDateNaissance() const;
	Panier* obtenirPanier() const;

	void modifierDateNaissance(long date);

	void acheter( ProduitOrdinaire * prod);
	void livrerPanier();
	void miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise) const;

	Client& operator=(const Client& client);
	friend ostream& operator<<(ostream& os, const Client& client);

private:
	long dateNaissance_;
	Panier *  monPanier_;

};

#endif