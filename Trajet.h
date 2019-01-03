/*************************************************************************
                           Trajet  
						     -
Un déplacement d'une ville de départ vers une ville d'arrivée.
                             -------------------
	début                : 31/12/2018
	copyright            : (C) 2018 par 32_08
	e-mail               : mengxin.zhang@insa-lyon.fr
						   manal.el-karchouni@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H
using namespace std;
#include <fstream>
#include <iostream>


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Servir de base pour les différents types de trajets: simples ou composés.
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual char* toString (  )const =0;
    // Mode d'emploi :
    // Renvoie la chaîne de caractère qui contient toutes les informations du trajet
    // Contrat :
    // Aucun

    virtual char* VilleDepart (  ) const =0;
    // Mode d'emploi :
    // Renvoie la chaîne de caractères de la ville de départ du trajet
    // Contrat :
    // Aucun

    
    virtual char* VilleArrivee (  ) const =0;
    // Mode d'emploi :
    // Renvoie la chaîne de caractères de la ville d'arrivée du trajet composé
    // Contrat :
    // Aucun

    virtual void Enregistrer(ofstream & fout) const = 0;
	// Mode d'emploi :
   // Enregistre un nouveau trajet simple ou trajet composé dans le fichier de sortie fout.
   // Contrat :
   // Aucun


//------------------------------------------------- Surcharge d'opérateurs
// Aucun

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    // Il n'y a pas de passage/retour par valeur de Trajet dans notre programme, on garde la déclaration
	// de ce constructeur de copie mais on omet sa définition, ainsi s'il y a un usage inattendu de contructeur de copie
	// de copie, l'éditeur de lien le dectectera
    // Contrat :
    // Aucun

	Trajet ( )
    {
    }
    // Mode d'emploi :
    // Méthode inline, crée un Trajet vide
    // Contrat :
    // Aucun
	
    virtual ~Trajet ( )
    {
    }
    // Mode d'emploi :
    // Méthode inline, detruire un Trajet
    // Contrat :
    // Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // TRAJET_H

