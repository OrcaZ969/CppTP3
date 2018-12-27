/*************************************************************************
                           ListeTrajet  
						       -
Une liste chaînée pouvant représenter un trajet composé ou un catalogue de trajets (simples et/ou composés)
                             -------------------
	début                : 23/11/2018
	copyright            : (C) 2018 par 32_08
	e-mail               : mengxin.zhang@insa-lyon.fr
						   alexandra.lafaille@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajet> (fichier ListeTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeTrajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
   
bool ListeTrajet::IsVide ( ) const
// Algorithme :
// La liste de trajet est vide quand le pointerTete ou le pointerFin est nullptr
{
	return pointerFin==nullptr;
} //----- Fin de IsVide ( )

bool ListeTrajet::DejaExistant (Trajet* pointerTrajet ) const
// Algorithme :
// faire un parcours de cette liste chaînée et comparer le résultat de toString() de chaque 
// trajet dans cette liste avec celui du trajet à ajouter
// si jamais un trajet dans cette liste a le même le resultat de toString() que celui à ajouter,
// ça veut dire le trajet à ajouter(simple ou composé) existe déjà dans cette liste
{
	bool exists=false;
	char* trajetString= pointerTrajet->toString();
	Cellule* courrent=pointerTete;
	if(courrent!=nullptr){
		//parcours de la liste chaînée
	  	do{
			char* oldString=courrent->unTrajet->toString();
			if(!strcmp(trajetString,oldString)){
				//comparer le trajet à ajouter et ce trajet dans la liste chaînée
				exists=true;
			}
			delete[] oldString;
			if(exists){
				break;
			}
			courrent=courrent->suivant;
		}while(courrent!=nullptr);
	}
	delete[] trajetString;
	return exists;
} //----- Fin de DejaExistant (Trajet* pointerTrajet )
  
char* ListeTrajet::GetDebut ( ) const
{
	return pointerTete->unTrajet->VilleDepart();
} //----- Fin de GetDebut ( )
  
char* ListeTrajet::GetFin ( ) const
{
	return pointerFin->unTrajet->VilleArrivee();

} //----- Fin de GetFin ( )

void ListeTrajet::Ajouter (Trajet * pointerTrajet ) 
// Algorithme :
// Il permet d'ajouter une nouvelle cellule à la liste chaînée
// que forme ListeTrajet.
// Il traite le cas où la liste chaînée est initialement vide et
// celui où elle ne l'est pas.
{
	if(pointerFin==nullptr){
		Cellule* c=new Cellule(pointerTrajet);
		pointerTete=c;
		pointerFin=c;
	}
	else{
		Cellule* c=new Cellule(pointerTrajet);
		pointerFin->suivant=c;
		pointerFin=c;
	}
} //----- Fin de Ajouter (Trajet * pointerTrajet )

void ListeTrajet::Display( ) const
// Algorithme :
// faire un parcours de cette liste chaînée, afficher dans le console le résultat de toString()
// de chaque trajet et leur indice
{
	int index=1;
	Cellule* courrent = pointerTete;
	if(courrent!=nullptr){
		do{
			cout<<"Trajet n° "<<index<<" :";
			char* trajetString=courrent->unTrajet->toString();
			cout<<trajetString<<endl;
			delete[] trajetString;
			courrent=courrent->suivant;
			index++;
		}while(courrent!=nullptr);
	}
} //----- Fin de Display( )  
  
char* ListeTrajet::toStringCompose( ) const
// Algorithme :
// allouer d'abord l'espace de 200 char, puis faire un parcours de cette liste chaînée,
// pré-calculer l'espace nécessaire pour ajouter l'information de chaque trajet,
// si l'espace déjà alloué ne suffit pas, allouer l'espace de 200 char de plus, et ainsi de suite
{
	char infoCompose[]={"Trajet Compose\n"};
	char sousTrajetInfo[]={"¤ Sous "};
	//allouer initialement l'espace de 200 char
	int length=200;
	char* string=new char[length];
	strcpy(string,infoCompose);
	int occupe=strlen(infoCompose)+1;
	Cellule* courrent=pointerTete;
	if(courrent!=nullptr){
		do{
			//stocker temporairement l'info d'un trajet dans "sousTrajetString"
			char* sousTrajetString=courrent->unTrajet->toString();
			//pré-calcule l'espace nécessaire pour ajouter l'info de ce trajet
			int lengthExpected=occupe+strlen(sousTrajetString)+strlen(sousTrajetInfo);
			if(lengthExpected>length){
				//allouer l'espace de 200 char de plus si l'espace ne suffit pas
				length=lengthExpected+200;
				char* newstring=new char[length];
				strcpy(newstring,string);
				delete[] string;
				string=newstring;
			}
			//recopier les caractères avec la fonction strcat
			strcat(string,sousTrajetInfo);
			strcat(string,sousTrajetString);
			occupe+=strlen(sousTrajetString)+strlen(sousTrajetInfo);
			//détruire "sousTrajetString"
			delete[] sousTrajetString;
			courrent=courrent->suivant;
		}while(courrent!=nullptr);
	}else{
		strcat(string,"Trajet Vide!\n");
	}
	return string;		  
} //----- Fin de toStringCompose( )

bool ListeTrajet::Recherche (const char* villeDepart,const char* villeArrivee ) const
// Il parcoure tout le catalogue et affiche chaque trajet dont les villes de départ
// et d'arrivée correspondent aux villes données.
// Il effectue une recherche simple des trajets correspondant aux villes données
// c'est-à-dire qu'il ne combine pas de trajets simples et de trajets composés
// pour ajouter des solutions. 
  {
	  int index=1;
	  bool found=false;
	  if(pointerFin==nullptr){
		  cout<<"La liste est vide!"<<endl;
	  }else{
		  Cellule* courant=pointerTete;
		  while(courant!=nullptr){
			  if(!strcmp(courant->unTrajet->VilleDepart(),villeDepart)&&
			!strcmp(courant->unTrajet->VilleArrivee(),villeArrivee)){
				  cout<<"---------solution n° "<<index<<"---------"<<endl;
				  cout<<courant->unTrajet->toString();
				  index++;
				  found=true;
				  cout<<endl;
			  }
			  courant=courant->suivant;
		  }
	  }
	  return found;
  } //----- Fin de Recherche

bool ListeTrajet::RechercheBK(const char* villeDepart,const char* villeArrivee) 
// Algorithme :
// définir dynamiquement une instance de ListeTrajet pour stocker temporairement le résultat de recherche
// initialiser le compteur de solution à zéro
// passe le pointer de ce ListeTrajet, l'adresse du compteur ,la ville de départ et la ville d'arrivée
// en paramètres de la méthode protégée backtracking(char*,char*,ListeTrajet*,int*) 
// détruire le ListeTrajet à la fin de recherche
// si le nombre de solution est égale à 0, renvoie false(aucun trajet trouvé), sinon renvoie true
{
	ListeTrajet* result=new ListeTrajet;
	int nbSolution=0;
	this->backtracking(villeDepart,villeArrivee,result,&nbSolution);
	result->remettreAZero();
	delete result;
	bool found=true;
	if(nbSolution==0){
		found=false;
	}
	return found;
}//----- Fin de RechercheBK(const char* villeDepart,const char* villeArrivee)

void ListeTrajet::Enregistrer(ofstream & fout) 
// Algorithme :
{
	Cellule* courrent = pointerTete;
	if (courrent != nullptr) {
		do {
			courrent->unTrajet->Enregistrer(fout);
			courrent = courrent->suivant;
		} while (courrent != nullptr);
	}
}
void ListeTrajet::EnregistrerVD(ofstream & fout,string vd) {

	bool param = false;
	Cellule* courrent = pointerTete;
	if (courrent != nullptr) {
		do {
			if (courrent->unTrajet->VilleDepart() == vd) {
			courrent->unTrajet->Enregistrer(fout);
			param = true;
			}
			courrent = courrent->suivant;
		} while (courrent != nullptr);
	}
	if (!param) {
		cout << "Cette ville de départ n'existe pas!" << endl;
	}


}
void ListeTrajet::EnregistrerVA(ofstream & fout,string va) {

	bool param = false;
	Cellule* courrent = pointerTete;
	if (courrent != nullptr) {
		do {
			if (courrent->unTrajet->VilleArrivee() == va) {
				courrent->unTrajet->Enregistrer(fout);
				param = true;
			}
			courrent = courrent->suivant;
		} while (courrent != nullptr);
	}
	if (!param) {
		cout << "Cette ville d'arrivée n'existe pas !" << endl;
	}


}
void ListeTrajet::EnregistrerVDetVA(ofstream & fout,string vd,string va) {

	bool param = false;
	Cellule* courrent = pointerTete;
	if (courrent != nullptr) {
		do {
			if (courrent->unTrajet->VilleDepart() == vd && courrent->unTrajet->VilleArrivee() == va) {
				courrent->unTrajet->Enregistrer(fout);
				param = true;
			}
			courrent = courrent->suivant;
		} while (courrent != nullptr);
	}
	if (!param) {
			cout << "Ce trajet n'existe pas!" << endl;
	}


}


void ListeTrajet::EnregistrerCompose(ofstream & fout)
// Algorithme :
{
	fout << "C" << endl;
	Cellule* courrent = pointerTete;
	if(courrent!=nullptr){
		do{
			courrent->unTrajet->Enregistrer(fout);
			courrent=courrent->suivant;
		}while(courrent!=nullptr);
	}
	fout << "fin" << endl;
}//----- Fin de EnregistrerCompose(fstream & fout)

void ListeTrajet::EnregistrerType(ofstream & fout, int choix) { // choix = 1 --> TS / choix ==2 --> TC
	Cellule* courrent = pointerTete;
	TrajetSimple* ptS = nullptr;
	TrajetCompose * ptC = nullptr;
	if (choix == 1) {
		do {
			ptS = dynamic_cast<TrajetSimple*>(courrent->unTrajet);
			ptC = dynamic_cast<TrajetCompose*>(courrent->unTrajet);
			if (ptC == nullptr) {
				//c'est un ts
				courrent->unTrajet->Enregistrer(fout);
			}
			courrent = courrent->suivant;
		} while (courrent != nullptr);
	}
	else if (choix == 2) {
		do {
			ptS = dynamic_cast<TrajetSimple*>(courrent->unTrajet);
			ptC = dynamic_cast<TrajetCompose*>(courrent->unTrajet);
			if (ptS == nullptr) {
				courrent->unTrajet->Enregistrer(fout);
			}
			courrent = courrent->suivant;
		} while (courrent != nullptr);
	}
	else {
		cout << "Merci de rentrer soit 1 soit 2 ! " << endl;
	}
}

void ListeTrajet::Chargement(ifstream & fin)
{
	cout<<"first here"<<endl;
	string ligne;
	while(getline(fin,ligne))
	{
		cout<<"in the while"<<endl;
		if(ligne=="TS:")
		{
			cout<<"in TS"<<endl;
			TrajetSimple* t=ChargementS(fin);
			this->Ajouter(t);
			
		}
		if(ligne=="TC:")
		{
			cout<<"in TC"<<endl;
			TrajetCompose* nouveauTC=new TrajetCompose;
			int niveau=1;
			this->Ajouter(ChargementC(fin,this,nouveauTC,&niveau));
		}
	}
}




//------------------------------------------------- Surcharge d'opérateurs
// Aucun

//-------------------------------------------- Constructeurs - destructeur

ListeTrajet::ListeTrajet ( )
// Algorithme :
//
{
	pointerTete=nullptr;
	pointerFin=nullptr;
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajet()>" << endl;
#endif
} //----- Fin de ListeTrajet()

ListeTrajet::ListeTrajet (Trajet* pointerTrajet )
// Algorithme :
//
{
	Cellule* c=new Cellule(pointerTrajet);
	pointerTete=c;
	pointerFin=c;
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajet(Trajet* pointerTrajet)>" << endl;
#endif
} //----- Fin de ListeTrajet (Trajet* pointerTrajet )


ListeTrajet::~ListeTrajet ( )
// Algorithme :
// faire un parcours de cette liste pour delete chaque cellule de cette liste
{
	Cellule * courrent=pointerTete;
	if(courrent!=nullptr){
		Cellule * next=pointerTete->suivant;
		while(courrent!=nullptr){
			delete courrent;
			courrent=next;
			if(next!=nullptr)
			{
			next=next->suivant;
			}
		}
	};
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajet>" << endl;
#endif
} //----- Fin de ~ListeTrajet ( )


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
 
void ListeTrajet::backtracking(const char* villeDepart,const char* villeArrivee,ListeTrajet* result,int* nbSolution)
//Algorithme :
//un algorithme récursif qui se base sur le principe de backtracking
//pour des ville départ et ville d'arrivée donnée en paramètres,
//faire un parcours de cette liste chaînée, s'il existe un trajet dont sa ville de départ est la même que celle passé en paramètre,
//passer à l'étape suivante: la ville d'arrivée de ce trajet devient la ville de départ de notre recherche, et ainsi de suite
//si la ville de départ de la recherche est la même que sa ville d'arrivée: une solution a été trouvée!
//====> afficher cette solution, incrémenter le compteur de solution, et remettre la liste chaînée "result" à zéro
//si après tout le parcours de la liste chaîne, aucun trajet dont la ville de départ est la même que celle de notre recherche a été trouvé: impasse!
//====> remettre la liste chaînée "result" à zéro
{
  	if(!strcmp(villeDepart,villeArrivee)){
		//une solution a été trouvée
		cout<<"---------solution n° "<<++(*nbSolution)<<"---------"<<endl;
		result->Display();
		result->remettreAZero();
	}else{
		bool found=false;
		Cellule* courant=pointerTete;
		while(courant!=nullptr){
			if(!strcmp(villeDepart,courant->unTrajet->VilleDepart())){
					//on avance et on passe à l'étape suivante
					found=true;
					result->Ajouter(courant->unTrajet);
					this->backtracking(courant->unTrajet->VilleArrivee(),villeArrivee,result,nbSolution);
			}
			courant=courant->suivant;		
		}
		if(!found){
			//c'est une impasse
			result->remettreAZero();
		}
	}
} //----- Fin de Méthode

void ListeTrajet::remettreAZero ( )
// Algorithme :
// déstruire chaque cellule de cette liste sans déstruire le trajet correspondant
{
	Cellule* courant=pointerTete;
	Cellule* supprimer=nullptr;
	//la cellule à supprimer
	while(courant!=nullptr){
		supprimer=courant;
		courant=courant->suivant;
		supprimer->unTrajet=nullptr;
		delete supprimer;
	}
	pointerTete=nullptr;
	pointerFin=nullptr;
} //----- Fin de Méthode

TrajetSimple* ListeTrajet::ChargementS(ifstream & fin)
// Algorithme :
//
{
	cout<<"here"<<endl;
	string ligne;
	getline(fin,ligne);
	cout<<ligne<<endl;
	/*while (getline(fin, ligne)) {*/
	string vd;
	string va;
	string mt;
	vector<string> lignes;
	stringstream ss(ligne);
	string a;
	while (getline(ss, a, '.'))
	{
		lignes.push_back(a);
	}
	vd = lignes.at(0);
	va = lignes.at(1);
	mt = lignes.at(2);
	TrajetSimple *t = new TrajetSimple(vd.c_str(), va.c_str(), mt.c_str());
        return t;
	//}

}//----- Fin de ChargementS


TrajetCompose* ListeTrajet::ChargementC(ifstream & fin,ListeTrajet* liste,TrajetCompose* firstLevel,int* level)
// Algorithme :
//
{	
		string ligne;
		while(getline(fin,ligne)){
			if(ligne=="TS:"){
				cout<<"I read a TS"<<endl;
				firstLevel->Ajouter(ChargementS(fin));
			}
			if(ligne=="TC:"){
				cout<<"I read a TC"<<endl;
				TrajetCompose* nextLevel=new TrajetCompose;
				(*level)++;
				ChargementC(fin,firstLevel->pointerListe,nextLevel,level);
			}
			if(ligne=="fin"){
				cout<<"I read fin"<<endl;
				if(*level!=1){
					cout<<"level is not 1: "<<*level<<endl;
					liste->Ajouter(firstLevel);	
				}
				(*level)--;
		 		return firstLevel;	
			}
		}
		return firstLevel;
	
}//----- Fin de ChargementC
