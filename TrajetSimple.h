/*************************************************************************
                           TrajetSimple  
						         -  
Un ensemble d'une ville de départ, une ville d'arrivée et un moyen de transport
                             -------------------
    début                : 23/11/2018
    copyright            : (C) 2018 par 32_08
    e-mail               : mengxin.zhang@insa-lyon.fr
						   alexandra.lafaille@insa-lyon.fr
*************************************************************************/
//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"


using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Elle représente un trajet direct d'une ville de départ vers une ville d'arrivée
// avec un moyen de transport.
//------------------------------------------------------------------------


class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    char* toString ( ) const;
    // Mode d'emploi :
    // Renvoie la chaîne de caractère qui contient toutes les informations du trajet simple
    // Contrat : 
    // Aucun
    
    char* VilleDepart ( ) const;
    // Mode d'emploi :
    // Renvoie la chaîne de caractères de la ville de départ du trajet simple
    // Contrat :
    // Aucun

    char* VilleArrivee ( ) const;
    // Mode d'emploi :
    // Renvoie la chaîne de caractères de la ville d'arrivée du trajet simple
    // Contrat :
    // Aucun

    void Enregistrer(ofstream & fout)const ;
   // Mode d'emploi :
   // Enregistre un nouveau trajet simple  dans le fichier de sortie fout.
   // Contrat :
   // Aucun




//------------------------------------------------- Surcharge d'opérateurs
// Aucun

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    // Il n'y a pas de passage/retour par valeur de TrajetSimple dans notre programme, on garde la déclaration
	// de ce constructeur de copie mais on omet sa définition, ainsi s'il y a un usage inattendu de contructeur de copie
	// de copie, l'éditeur de lien le dectectera
    // Contrat : 
    // Aucun

    TrajetSimple (const char*,const char*,const char* );
    // Mode d'emploi :
    // Créer une instance de trajet simple à partir de ville de départ, ville d'arrivée et le moyen de transport
    // Contrat :
    // Aucun

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    // Libère l'espace mémoire attribué au trajet simple.
    // Contrat :
    // Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	char* villeDepart;
	char* villeArrivee;
	char* moyenTransport;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // TRAJETSIMPLE_H

