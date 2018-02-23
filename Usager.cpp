/********************************************
* Titre: Travail pratique #3 - Client.h
* Date: 26 Fevrier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*******************************************/

#include "Usager.h"
using namespace std;
/**
* Constructeur par parametres.
*/
Usager::Usager(const string&  nom, const string& prenom, int identifiant, const string& codePostal):
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal }	
{
}

/**
* Accesseur de nom_.
*/
string Usager::obtenirNom() const
{
	return nom_;
}

/**
* Accesseur de prenom_.
*/
string Usager::obtenirPrenom() const
{
	return prenom_;
}

/**
* Accesseur de identifiant_.
*/
int Usager::obtenirIdentifiant() const
{
	return identifiant_;
}

/**
* Accesseur de codePostal_.
*/
string Usager::obtenirCodePostal() const
{
	return codePostal_;
}

/**
* Modificateur de nom_.
*/
void  Usager::modifierNom(const string& nom)
{
	nom_ = nom;
}
/**
* Modificateur de prenom_.
*/
void Usager::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}
/**
* Modificateur de identifiant_.
*/
void Usager::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}
/**
* Modificateur de codePostal_.
*/
void Usager::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}

/**
* Affectation des attribtuts d'un usager passe en parametre a l'usager
*/
Usager &Usager::operator=(const Usager & usager)
{
	if (this != &usager) {
		nom_ = usager.nom_;
		prenom_ = usager.prenom_;
		identifiant_ = usager.identifiant_;
		codePostal_ = usager.codePostal_;		
	}
	return *this;
}
/**
* Surcharge d'operateur qui compare l'identifiant a un indentifiant passe en parametre
*/
bool Usager::operator==(int indentifiant) const {
	return identifiant_ == indentifiant;
};
/**
* Surcharge d'operateur qui compare l'identifiant de l'usager a l'identifiant d'un usager passe en parametre
*/
bool Usager::operator == (const Usager & usager)const
{
	return  *this == usager.obtenirIdentifiant();
}
/**
* Surcharge d'operateur qui compare un usager a son identifiant
*/
bool operator==(int indentifiant, const Usager& usager) {
	return usager == indentifiant;
}
/**
* Surcharge d'operateur de lecture d'un usager
*/
ostream & operator<<(ostream & os, const Usager & usager)
{
	os << " Usager :";
	os << "\t nom : " << usager.obtenirNom() << endl
		<< "\t prenom : " << usager.obtenirPrenom() << endl
		<< "\t identifiant: " << usager.obtenirIdentifiant() << endl
	   << "\t codePostal: " << usager.obtenirCodePostal() << endl;
	return os;
}

