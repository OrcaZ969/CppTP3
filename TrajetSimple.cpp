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

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
char*  TrajetSimple::toString (  ) const
// Algorithme :
// Calculer a priori l'espace nécessaire de chaîne de caractère pour representer l'information d'un trajet simple
// Alouer l'espace puis le remplir avec la fonction strcpy et strcat 
{
	int lengthDepart=strlen(villeDepart);
	int lengthArrivee=strlen(villeArrivee);
	int lengthMoyen=strlen(moyenTransport);
	char infoSimple[]={"Trajet Simple"};
	char infoDepart[]={"\n  Ville de départ: "};
	char infoArrivee[]={"\n  Ville d'arrivée: "};
	char infoTransport[]={"\n  Moyen de transport: "};
	char fin[]={"\n"};
	int length=lengthDepart+lengthArrivee+lengthMoyen+strlen(infoSimple)+strlen(infoDepart)+strlen(infoArrivee)+strlen(infoTransport)+strlen(fin);
	char* trajetString=new char[length+1];
	strcpy(trajetString,infoSimple);
	strcat(trajetString,infoDepart);
	strcat(trajetString,villeDepart);
	strcat(trajetString,infoArrivee);
	strcat(trajetString,villeArrivee);
	strcat(trajetString,infoTransport);
	strcat(trajetString,moyenTransport);
	strcat(trajetString,fin);
	return trajetString;
} //----- Fin de toString (  )


char* TrajetSimple::VilleDepart ( ) const
{
	return villeDepart;
} //----- Fin de VilleDepart ( )

char* TrajetSimple::VilleArrivee ( ) const
{
	return villeArrivee;
} //----- Fin de VilleArrivee ( )

void TrajetSimple::Enregistrer(ofstream & fout) const {
	fout << "TS:"<<endl;
	fout << villeDepart;
	fout << ".";
	fout << villeArrivee;
	fout << ".";
	fout << moyenTransport <<"."<< endl;
}// fin de Enregistrer.


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple ( const char* villeDepart, const char* villeArrivee, const char* moyen)
// Algorithme :
//
{
#ifdef MAP	
    cout << "Appel au constructeur de <TrajetSimple(const char* villeDepart,const char* villeArrivee,const char* moyen)>" << endl;
#endif
	this->villeDepart=new char[strlen(villeDepart)+1];
	strcpy(this->villeDepart,villeDepart);
	this->villeArrivee=new char[strlen(villeArrivee)+1];
	strcpy(this->villeArrivee,villeArrivee);
	this->moyenTransport=new char[strlen(moyen)+1];
	strcpy(this->moyenTransport,moyen);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
	delete []  villeDepart;
	delete []  villeArrivee;
	delete [] moyenTransport;
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

