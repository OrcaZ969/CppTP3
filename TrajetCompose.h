/*************************************************************************
                           TrajetCompose  
						         -
Une liste chaînée contenant l'ensemble de trajets simples dont le trajet est composé
                             -------------------
    début                : 23/11/2018
    copyright            : (C) 2018 par 32_08
    e-mail               : mengxin.zhang@insa-lyon.fr
						   alexandra.lafaille@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajet.h"
#include <fstream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Elle représente un trajet avec étape(s) d'une ville de départ vers une ville d'arrivée.
// Ce trajet est décomposé en plusieurs trajets.
//------------------------------------------------------------------------
class ListeTrajet;

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    char* toString (  );
    // Mode d'emploi :
    // Renvoie la chaîne de caractère qui contient toutes les informations du trajet composé
    // Contrat :
    // Aucun

    char* VilleDepart (  );
    // Mode d'emploi :
    // Renvoie la chaîne de caractères de la ville de départ du trajet composé
    // Contrat :
    // Aucun
    
    char* VilleArrivee(  );
    // Mode d'emploi :
    // Renvoie la chaîne de caractères de la ville d'arrivée du trajet composé
    // Contrat :
    // Aucun

    bool Ajouter( Trajet * unTrajet );
    // Mode d'emploi :
    // Ajouter un trajet à la liste de trajets dont le trajet composé est constitué
    // Renvoie true si ce trajet a été correctement ajouté, sinon renvoie false
    // Contrat :
    // Aucun
    
    void Enregistrer(ofstream & fout) const;
//------------------------------------------------- Surcharge d'opérateurs
// Aucun

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi (constructeur de copie) :
    // Il n'y a pas de passage/retour par valeur de TrajetCompose dans notre programme, on garde la déclaration
	// de ce constructeur de copie mais on omet sa définition, ainsi s'il y a un usage inattendu de contructeur de copie
	// de copie, l'éditeur de lien le dectectera
    // Contrat :
    // Aucun

    TrajetCompose ( );
    // Mode d'emploi :
    // Créer un trajet composé vide
    // Contrat :
    // Aucun
	
    TrajetCompose ( Trajet* unTrajet);
    // Mode d'emploi :
    // Créer un trajet composé à partir d'un premier trajet (simple ou composé)
    // Contrat :
    // Aucun
	
    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    // Libère l'espace mémoire attribué au trajet composé.
    // Contrat :
    // Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	ListeTrajet * pointerListe;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H

