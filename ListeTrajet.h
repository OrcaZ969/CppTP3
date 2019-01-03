/*************************************************************************
                           ListeTrajet  
						       -
Une liste chaînée pouvant représenter un trajet composé ou un catalogue de trajets (simples et/ou composés)
                             -------------------
	début                : 31/12/2018
	copyright            : (C) 2018 par 32_08
	e-mail               : mengxin.zhang@insa-lyon.fr
						   manal.el-karchouni@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ListeTrajet> (fichier ListeTrajet.h) ----------------
#if ! defined ( LISTETRAJET_H )
#define LISTETRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
// la structure définie pour représenter chaque cellule de la liste chaînée
struct Cellule {
	Trajet * unTrajet;
	Cellule* suivant;
public:
	Cellule(Trajet* t)
	{
		unTrajet=t;
		suivant=nullptr;
	}
	~Cellule()
	{
		delete unTrajet;
	}
};

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajet>
// Elle représente une liste de trajets que l'on peut interpréter comme un catalogue 
// de trajets (simples et/ou composés) ou un trajet composé.
//
//------------------------------------------------------------------------
class TrajetSimple;

class TrajetCompose;

class ListeTrajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  	
    bool IsVide (  ) const;
    // Mode d'emploi :
    // Renvoie true si cette liste de trajets est vide, sinon renvoie false
    // Contrat :
    // Aucun
	
    bool DejaExistant ( Trajet * unTrajet ) const;
    // Mode d'emploi :
    // Renvoie true si le trajet donné en paramètre existe déja, sinon renvoie false
    // Contrat :
    // Aucun
	
    int  GetLength ( ) const;
    // Mode d'emploi :
    // Renvoie la chaîne de caractères de ville de départ de la liste trajet
    // Contrat :
    // Aucun

    char*  GetDebut ( ) const;
    // Mode d'emploi :
    // Renvoie la chaîne de caractères de ville de départ de la liste trajet
    // Contrat :
    // Aucun
    char* GetFin ( ) const;
    // Mode d'emploi :
    // Renvoie la chaîne de caractères de ville d'arrivée de la liste trajet
    // Contrat :
    // Aucun
    
    bool Ajouter ( Trajet * unTrajet );
    // Mode d'emploi :
    // Ajoute un trajet donné en paramètre à cette liste de trajets
    // Contrat :
    // Aucun

    void Display( ) const;
    // Mode d'emploi :
    // Affiche dans la console tous les trajets de cette liste 
	// (c'est à dire sous forme d'une catalogue)
	// Utilisé dans le programme principal "menu"
    // Contrat :
    // Aucun
	
    char* toStringCompose () const;
    // Mode d'emploi :
    // Renvoie la chaîne de caractères qui contient toutes les informations du trajet composé
	// Utilisé dans la méthode char* toString() de la classe "TrajetCompose"
    // Contrat :
    // Aucun
	
    bool Recherche (const char*,const char*) const;
    // On entre la ville de départ et la ville d'arrivée du trajet recherché
	// et la méthode affiche tous les trajets correspondant à cette recherche.
	// Il effectue une recherche simple des trajets correspondant aux villes données
	// c'est-à-dire qu'il ne combine pas de trajets simples et de trajets composés
	// pour ajouter des solutions. 
	// renvoie true s'il existe au moins une solution, sinon renvoie false
    // Contrat : Aucun
  
    bool RechercheBK (const char*,const char*);
    // Mode d'emploi :
	// effectue une recherche avancée des trajets correspondant aux ville de départ et ville d'arrivée données
	// c'est-à-dire qu'il est possible de combiner trajet(s)) simple(s) et trajet(s) composé(s) pour consitutuer des solutions
	// (la recherche simple est toujours possible avec cette méthode)
	// renvoie true s'il existe au moins une solution, sinon renvoie false
    // Contrat :
    // Aucun

    void EnregistrerCompose(ofstream & fout);
	// Mode d'emploi :
	//
	// Contrat :
	// Aucun

	int Enregistrer(ofstream & fout);
	// Mode d'emploi :
	//
	// Contrat :
	// Aucun

	int Enregistrer(ofstream & fout, bool choix);
	// Mode d'emploi :
	//
	// Contrat :
	// Aucun

	int Enregistrer(ofstream & fout, bool choix,string ville);
	// Mode d'emploi :
	//
	// Contrat :
	// Aucun

	int Enregistrer(string vd, string va,ofstream &fout);
	// Mode d'emploi :
	//
	// Contrat :
	// Aucun

	int Enregistrer(int n, int m, ofstream &fout);
	// Mode d'emploi :
	//
	// Contrat :
	// Aucun

	int Chargement(ifstream & fin);
	// Mode d'emploi :
	//
	// Contrat :
	// Aucun

	int Chargement(ifstream &fin,bool choix);
	// Mode d'emploi :
	//
	// Contrat :
	// Aucun

 	int Chargement(ifstream &fin,bool choix,string ville);
	// Mode d'emploi :
	//
	// Contrat :
	// Aucun

	int Chargement(string villeDepart,string villeArrivee,ifstream &fin);
	// Mode d'emploi :
	//
	// Contrat :
	// Aucun
	int Chargement(int n,int m,ifstream &fin );
	// Mode d'emploi :
	//
	// Contrat :
	// Aucun

//------------------------------------------------- Surcharge d'opérateurs
// Aucun

//-------------------------------------------- Constructeurs - destructeur
    ListeTrajet ( const ListeTrajet & unListeTrajet );
    // Mode d'emploi (constructeur de copie) :
    // Il n'y a pas de passage/retour par valeur de ListeTrajet dans notre programme, on garde la déclaration
	// de ce constructeur de copie mais on omet sa définition, ainsi s'il y a un usage inattendu de contructeur de copie
	// de copie, l'éditeur de lien le dectectera
    // Contrat :
    // Aucun

    ListeTrajet ( );
    // Mode d'emploi :
    // Créer une liste de trajets vide.
    // Contrat :
    // Aucun

    ListeTrajet ( Trajet * pointerTrajet );
    // Mode d'emploi :
    // Créer une liste de trajet à partir du trajet(simple ou composé) donné en paramètre
    // Contrat :
    // Aucun
    virtual ~ListeTrajet ( );
    // Mode d'emploi :
    // Libère l'espace mémoire alloué à ListeTrajet
    // Contrat :
    // Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    void backtracking(const char* villeDepart,const char* villeArrivee,ListeTrajet* result,int* nbSolution);
    // Mode d'emploi :
    // la recherche avancée utilisant l'algorithme backtracking avec un compteur qui compte le nombre de solutions
	// utilisé dans la méthode public void RechercheBK(char*,char*) de cette classe
    // Contrat :
    // Aucun
	
    void remettreAZero ();
    // Mode d'emploi :
    // Il sert à remettre à zéro la liste de trajet qui stocke temporairement le résultat de recherche
	// utilisé dans la méthode protégé void backtracking(const char*,const char*,ListeTrajet*,int*) de cette classe
    // (quand une tentative de recherche est terminée(avec échec ou avec réussite))
	// et dans la méthode public void RechercheBK(char*,char*) de cette classe
	// (quand la recheche est complètement terminée)
	// Contrat :
    // Aucun


	TrajetSimple* ChargementS(ifstream & fin);
	// Mode d'emploi :
	// 
	// Contrat :
	// Aucun
   	TrajetCompose* ChargementC(ifstream & fin,ListeTrajet* liste,TrajetCompose* firstLevelTC,int* level);
	// Mode d'emploi :
	// 
	// Contrat :
	// Aucun



//----------------------------------------------------- Attributs protégés
	Cellule* pointerTete;
	Cellule* pointerFin;
	int length;
};

//-------------------------------- Autres définitions dépendantes de <ListeTrajet>

#endif // LISTETRAJET_H

