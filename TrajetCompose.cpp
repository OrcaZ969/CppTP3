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

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

char* TrajetCompose::toString (  )
// Algorithme :
// Utilise la méthode toStringCompose de la classe ListeTrajet
{
	
	char* trajetString=pointerListe->toStringCompose();
	return trajetString;
	
} //----- Fin de toString (  )

char* TrajetCompose::VilleDepart (  )
// Algorithme :
// Utilise la méthode GetDebut de la classe ListeTrajet
{
	return pointerListe->GetDebut();
} //----- Fin de VilleDepart (  )

char* TrajetCompose::VilleArrivee ( )
// Algorithme :
// Utilise la méthode GetFin de la classe ListeTrajet
{
	return pointerListe->GetFin();
} //----- Fin de VilleArrivee ( )

bool TrajetCompose::Ajouter ( Trajet* unTrajet )
// Algorithme :
// Utilise la méthode Ajouter de la classe ListeTrajet
{	bool retour;
	if(pointerListe->IsVide()){
		//S'il s'agit d'un trajet composé vide, ajouter ce trajet
		pointerListe->Ajouter(unTrajet);
		retour=true;
	}else if(!strcmp(this->VilleArrivee(),unTrajet->VilleDepart())){
		//Sinon,
		//On vérifie la liaison entre les deux trajets simples successifs
		pointerListe->Ajouter(unTrajet);
		retour=true;
	}else{
		retour=false;
	}
	return retour;
	
} //----- Fin de Ajouter ( Trajet* unTrajet )

void TrajetCompose::Enregistrer ( ofstream & fout ) const
// Algorithme :
{
	pointerListe->EnregistrerCompose(fout);

} //----- Fin de Enregistrer ( ofstream & fout)

//------------------------------------------------- Surcharge d'opérateurs
// Aucun

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( )
// Algorithme :
// Utilise le constructeur ListeTrajet() de ListeTrajet
{
	pointerListe=new ListeTrajet;
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose()>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::TrajetCompose ( Trajet* unTrajet)
// Algorithme :
// Utilise le constructeur ListeTrajet(Trajet*)de ListeTrajet
{
	pointerListe=new ListeTrajet(unTrajet);
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose(Trajet* unTrajet)>" << endl;
#endif
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose ( )
// Algorithme :
// Cette méthode appelle le destructeur ~ListeTrajet ( )
{
	delete pointerListe;
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

