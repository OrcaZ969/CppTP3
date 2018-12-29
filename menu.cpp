// Rôle de <menu.cpp>
// point d’entrée de notre programme. Il crée une instance de la classe
// ListeTrajet et la détruit à la fin du programme. Il utilise les méthodes publiques de la
// classe ListeTrajet et est responsable d’interactions avec l’utilisateur

#include "ListeTrajet.h"
#include "Trajet.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include <iostream>
#include <cstring>

int main(){
	ListeTrajet *myliste =new ListeTrajet;
	int option;//variable qui représente le choix d'utilisateur
	cout<<"		BIENVENUE"<<endl;
	cout<<"Saisir 1 pour ajouter un trajet simple"<<endl;
	cout<<"Saisir 2 pour ajouter un trajet compose"<<endl;
	cout<<"Saisir 3 pour afficher la catalogue"<<endl;
	cout<<"Saisir 4 pour faire une recherche simple de parcours"<<endl;
	cout<<"Saisir 5 pour faire une recherche avancée de parcours"<<endl;
	cout<<"Saisir 6 pour faire une sauvegarde" << endl;
	cout<<"Saisir 7 pour faire un chargement" << endl;
	cout<<"Saisir 8 pour quitter la catalogue"<<endl;
	cout<<"===> Veuillez entrer votre choix:";
	cin>>option;
	cout<<"-----------------------------------------------"<<endl;
	while(option!=8){
		if(option==1){
			//ajouter un trajet simple
			char villeDepart[50];
			char villeArrivee[50];
			char moyenTransport[50];
			cout<<"¤ Entrer la ville de départ:"<<endl;
			cin.getline(villeDepart,50);
			cin.getline(villeDepart,50);
			cout<<"¤ Entrer la ville d'arrivée:"<<endl;
			cin.getline(villeArrivee,50);
			cout<<"¤ Entrer le moyen de transport:"<<endl;
			cin.getline(moyenTransport,50);
			TrajetSimple* ts=new TrajetSimple(villeDepart,villeArrivee,moyenTransport);
			if(myliste->DejaExistant(ts)){
				//le cas où ce trajet existe déjà ==> message d'erreur
				cout<<">>> message: ce trajet existe déjà!"<<endl;
				cout<<"----------trajet non ajouté---------"<<endl<<endl;
				delete ts;
			}else{
				myliste->Ajouter(ts);
				cout<<"--------trajet simple ajouté--------"<<endl<<endl;
			}
		}
		else if(option==2){
			//ajouter un trajet composé
			TrajetCompose *tc=new TrajetCompose;
			int goOn;//variable qui représenter si l'utilisateur veux continuer ou pas
			do{
				char villeDepart[50];
				char villeArrivee[50];
				char moyenTransport[50];
				cout<<"¤ Entrer la ville de départ:"<<endl;
				cin.getline(villeDepart,50);
				cin.getline(villeDepart,50);
				cout<<"¤ Entrer la ville d'arrivée:"<<endl;
				cin.getline(villeArrivee,50);
				cout<<"¤ Entrer le moyen de transport:"<<endl;
				cin.getline(moyenTransport,50);
				TrajetSimple* ts=new TrajetSimple(villeDepart,villeArrivee,moyenTransport);
				if(!tc->Ajouter(ts)){
					//le cas où la ville de départ ne correspond pas à la dernière ville d'arrivée ==> message d'erreur
					cout<<">>> message: votre saisie n'est pas valable!"<<endl;
					delete ts;
				}
				cout<<"---\n"<<"¤ Saisir 0 pour continuer ou un autre chiffre pour retourner au menu principal: ";
				cin>>goOn;
			}while(!goOn);	
			if(myliste->DejaExistant(tc)){
				//le cas où ce trajet existe déjà ==> message d'erreur
				cout<<">>> message: ce trajet existe déjà!"<<endl;
				cout<<"----------trajet non ajouté---------"<<endl<<endl;
				delete tc;
			}else{
				myliste->Ajouter(tc);
				cout<<"--------trajet composé ajouté--------"<<endl<<endl;
			}
		}
		else if(option==3){
			//afficher la catalogue
			if(myliste->IsVide()){
				cout<<">>> message: catalogue vide!"<<endl<<endl;
			}
			myliste->Display();
			cout<<"--------fin de l'affichage--------"<<endl<<endl;
		}
		else if(option==4){
			//faire une recherche simple
			if(myliste->IsVide()){
				cout<<">>> message: catalogue vide!"<<endl<<endl;
			}else{
				char villeDepart[50];
				char villeArrivee[50];
				cout<<"¤ Entrer la ville de départ:"<<endl;
				cin.getline(villeDepart,50);
				cin.getline(villeDepart,50);
				cout<<"¤ Entrer la ville d'arrivée:"<<endl;
				cin.getline(villeArrivee,50);
				if(!strcmp(villeDepart,villeArrivee)){
					//quand l'utilisateur a saisi la ville d'arrivée qui est la même que la ville de départ
					cout<<">>> message: la ville d'arrivée doit être différente de la ville de départ!"<<endl<<endl;
				}else{
					if(!myliste->Recherche(villeDepart,villeArrivee)){
						//quand il n'y a aucun trajet trouvé
						cout<<">>> message: aucun trajet trouvé!"<<endl<<endl;
					}
				}
			}
			cout<<"--------fin de la recherche--------"<<endl<<endl;
		}
		else if(option==5){
			//faire une recherche avancée
			if(myliste->IsVide()){
				cout<<">>> message: catalogue vide!"<<endl<<endl;
			}else{
				char villeDepart[50];
				char villeArrivee[50];
				cout<<"¤ Entrer la ville de départ:"<<endl;
				cin.getline(villeDepart,50);
				cin.getline(villeDepart,50);
				cout<<"¤ Entrer la ville d'arrivée:"<<endl;
				cin.getline(villeArrivee,50);
				if(!strcmp(villeDepart,villeArrivee)){
					//quand l'utilisateur a saisi la ville d'arrivée qui est la même que la ville de départ
					cout<<">>> message: la ville d'arrivée doit être différente de la ville de départ!"<<endl<<endl;
				}else{
					if(!myliste->RechercheBK(villeDepart,villeArrivee)){
						//quand il n'y a aucun trajet trouvé
						cout<<">>> message: aucun trajet trouvé!"<<endl<<endl;
					}
				}
			}
			cout<<"--------fin de la recherche--------"<<endl<<endl;
		}
		else if (option == 6) // options de sauvegarde
	   	{
			if(myliste->IsVide()){
				cout<<">>> message: catalogue vide!"<<endl<<endl;
				
				cout<<"-----------------------------------------------"<<endl;
			}else{
				int choixSauv;
				cout<<">>> Vous avez 4 options:"<<endl;
				cout << "    Saisir 1 pour une sauvegarde sans critère de sélection." << endl;
				cout << "    Saisir 2 pour une sauvegarde selon le type de trajet." << endl;
				cout << "    Saisir 3 pour une sauvegarde selon la ville de départ et/ou la ville d'arrivée." << endl;
				cout << "    Saisir 4 pour une sauvegarde selon une sélection de trajets." << endl;
				cout << "    Saisir 5 pour revenir au menu principal" << endl;
				cout << "    ===> Veuillez entrer votre choix:";
				cin >> choixSauv;
				while(choixSauv<1||choixSauv>5){	
					cout<<"    Veuillez entrer un chiffre entre 1 et 5"<<endl;
					cout<<"    ===> Veuillez entrer votre choix:";
					cin>>choixSauv;
				}
				cout<<"-----------------------------------------------"<<endl;
				if (choixSauv == 1) {		
					string nomFic; 
					cout << "¤ Veuillez entrer un nom de fichier !" << endl;
					cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
					cin >> nomFic;
					ofstream fic(nomFic+".txt");
					int nb=myliste->Enregistrer(fic);
					cout<<nb<<" trajet(s) enregistré"<<endl;		
				}
				else if (choixSauv == 2){
					int choixType;
					cout << ">>> Vous avez 2 sous-options:"<<endl;
					cout << "    Saisir 1 pour une sauvegarde des trajets simples." << endl;
					cout << "    Saisir 2 pour une sauvegarde des trajets composés." << endl;
					cout << "    ===> Veuillez entrer votre choix:";
					cin >> choixType;
					while(!(choixType==1||choixType==2)){
						cout<<"    Veuillez entrer soit 1 soit 2"<<endl;
						cout<<"    ===> Veuillez entrer votre choix:";
						cin>>choixType;
					}
					if (choixType == 1){
						string nomFic;
						cout << "¤ Veuillez entrer un nom de fichier !" << endl;
						cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
						cin >> nomFic;
						ofstream fic(nomFic+".txt");
						int nb=myliste->Enregistrer(fic,true);
						if(nb==0){
							cout<<"-----------------------------------------------"<<endl;
							cout<<">>> message: aucun trajet simple dans ce catalogue !"<<endl;
							cout<<">>> le fichier est créé mais rien n'est enregistré"<<endl;
						}else{
							cout<<"-----------------------------------------------"<<endl;
							cout<<nb<<" trajet(s) simple(s) enregistré(s)."<<endl;
						}
					}else{
						string nomFic;
						cout << "¤ Veuillez entrer un nom de fichier !" << endl;
						cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
						cin >> nomFic;
						ofstream fic(nomFic+".txt");
						int nb=myliste->Enregistrer(fic,false);
						if(nb==0){
							cout<<"-----------------------------------------------"<<endl;
							cout<<">>> message: aucun trajet composé dans ce catalogue !"<<endl;
							cout<<">>> le fichier est créé mais rien n'est enregistré"<<endl;
						}else{
							cout<<"-----------------------------------------------"<<endl;
							cout<<nb<<" trajet(s) compos(é) enregistré(s)."<<endl;
						}
					}
				}
				else if (choixSauv == 3)
				{
					int choixV;
					cout << ">>> Vous avez 3 sous-options:"<<endl;
					cout << "    Saisir 1 pour une sauvegarde à partir d'une ville de départ." << endl;
					cout << "    Saisir 2 pour une sauvegarde à partir d'une ville d'arrivée." << endl;
					cout << "    Saisir 3 pour une sauvegarde à partir d'une ville de départ et une ville d'arrivée." << endl;
					cout<<  "    ===> Veuillez entrer votre choix:";
					cin >> choixV;
					while(choixV<1||choixV>3){
						cout<<"    Veuillez entrer un chiffre entre 1 et 3"<<endl;
						cout<<"    ===> Veuillez entrer votre choix:";
						cin>>choixV;
					}
					if (choixV == 1) {
						cout << "¤ Veuillez entrer la ville de départ ! " << endl;
						string vd;
						cin >> vd;
						cout << "¤ Veuillez entrer un nom de fichier !" << endl;
						cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
						string nomFic;
						cin >> nomFic;
						ofstream fic(nomFic + ".txt");
						int nb=myliste->Enregistrer(fic,true,vd);
						if(nb==0){
							cout<<"-----------------------------------------------"<<endl;
							cout<<">>> message: aucun trajet dont la ville de départ est "<<vd<<" trouvé !"<<endl;
							cout<<">>> le fichier est crée mais rien n'est enregistré"<<endl;
						}else{
							cout<<"-----------------------------------------------"<<endl;
							cout<<nb<<" trajet(s) dont la ville de départ est "<<vd<<" enregistré(s) !"<<endl;
						}
					}
					else if (choixV == 2) {
						cout << "¤ Veuillez entrer la ville d'arrivée ! " << endl;
						string va;
						cin >> va;
						cout << "¤ Veuillez entrer un nom de fichier !" << endl;
						cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
						string nomFic;
						cin >> nomFic;
						ofstream fic(nomFic + ".txt");
						int nb=myliste->Enregistrer(fic,false, va);	
						if(nb==0){
							cout<<"-----------------------------------------------"<<endl;
							cout<<">>> message: aucun trajet dont la ville d'arrivée est "<<va<<" trouvé !"<<endl;
							cout<<">>> le fichier est crée mais rien n'est enregistré"<<endl;
						}else{
							cout<<"-----------------------------------------------"<<endl;
							cout<<nb<<" trajet(s) dont la ville d'arrivée est "<<va<<" enregistré(s) !"<<endl;
						}
					}
					else{
						cout << "¤ Veuillez entrer la ville de départ ! " << endl;
						string vd;
						cin >> vd;
						cout << "¤ Veuillez entrer la ville d'arrivée ! " << endl;
						string va;
						cin >> va;
						cout << "¤ Veuillez entrer un nom de fichier !" << endl;
						cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
						string nomFic;
						cin >> nomFic;
						ofstream fic(nomFic + ".txt");
						int nb=myliste->Enregistrer(vd,va,fic);
						if(nb==0){
							cout<<"-----------------------------------------------"<<endl;
							cout<<">>> message: aucun trajet dont la ville de départ est "<<vd<<" et la ville d'arrivée est "<<va<<" trouvé !"<<endl;
							cout<<">>> le fichier est crée mais rien n'est enregistré"<<endl;
						}else{
							cout<<"-----------------------------------------------"<<endl;
							cout<<nb<<" trajet(s) dont la ville de départ est "<<vd<<"et la ville d'arrivée est "<<va<<" enregistré(s) !"<<endl;	
						}
					}
				}
				else if(choixSauv==4)
				{

				}
				else if(choixSauv==5)
				{
				//ne rien faire	
				}
				if(choixSauv!=5){
					cout<<endl<<"--------fin de l'enregistrement--------"<<endl<<endl;
				}
			}
		}
		else if (option == 7)
	       	{ // options de chargement 
			int choixCh;
			cout << ">>> Vous avez 4 options:"<<endl;
			cout << "    Saisir 1 pour un chargement sans critère de sélection." << endl;
			cout << "    Saisir 2 pour un chargement selon le type de trajet." << endl;
			cout << "    Saisir 3 pour un chargement selon la ville de départ et/ou la ville d'arrivée." << endl;
			cout << "    Saisir 4 pour un chargement selon une sélection de trajets." << endl;
			cout << "    Saisir 5 pour revenir au menu principal" << endl;
			cout << "    ===> Veuillez entrer votre choix:";
			cin >> choixCh;
			while(choixCh<1||choixCh>5){	
				cout<<"    Veuillez entrer un chiffre entre 1 et 5"<<endl;
				cout<<"    ===> Veuillez entrer votre choix:";
				cin>>choixCh;
			}
			cout<<"-----------------------------------------------"<<endl;
			if (choixCh == 1)
			{	
				string nomFic; 
				ifstream fic;
				cout << "¤ Veuillez entrer un nom de fichier !" << endl;
				cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
				cin >> nomFic;
				fic.open(nomFic+".txt");
				while(!fic){
					cerr<<">>> message: ce fichier n'existe pas!"<<endl;
					cout<<"    saisir 0 pour réessayer, autre chiffre pour revenir au menu principal:";
					int retry;
					cin>>retry;
					if(!retry){
						//réessayer
						cout << "¤ Veuillez entrer un nom de fichier !" << endl;
						cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
						cin >> nomFic;
						fic.open(nomFic+".txt");
					}else{
						break;
					}
				}
				if(fic){
					cout<<"-----------------------------------------------"<<endl;
					int nb=myliste->Chargement(fic);
					cout<<nb<<" trajet(s) chargé(s)"<<endl;		
				}
			}
			else if (choixCh == 2)
			{
				int choixType;
				cout << ">>> Vous avez 2 sous-options:"<<endl;
				cout << "    Saisir 1 pour un chargement des trajets simples." << endl;
				cout << "    Saisir 2 pour un chargement des trajets composés." << endl;
				cout << "    ===> Veuillez entrer votre choix:";
				cin >> choixType;
				while(!(choixType==1||choixType==2)){	
					cout<<"    Veuillez entrer un chiffre entre 1 et 5"<<endl;
					cout<<"    ===> Veuillez entrer votre choix:";
					cin>>choixType;
				}
				string nomFic; 
				ifstream fic;
				cout << "¤ Veuillez entrer un nom de fichier !" << endl;
				cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
				cin >> nomFic;
				fic.open(nomFic+".txt");
				while(!fic){
					cerr<<">>> message: ce fichier n'existe pas!"<<endl;
					cout<<"    saisir 0 pour réessayer, autre chiffre pour revenir au menu principal:";
					int retry;
					cin>>retry;
					if(!retry){
						//réessayer
						cout << "¤ Veuillez entrer un nom de fichier !" << endl;
						cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
						cin >> nomFic;
						fic.open(nomFic+".txt");
					}else{
						break;
					}
				}
				if (choixType == 1)
				{
					if(fic){
						cout<<"-----------------------------------------------"<<endl;
						int nb=myliste->Chargement(fic,true);
						if(nb==0){
							cout<<">>> message: aucun trajet simple dans ce fichier !"<<endl;
						}else{
							cout<<nb<<" trajet(s) simple(é) chargé(s)."<<endl;
						}
					}
				}
				else{
					if(fic){
						cout<<"-----------------------------------------------"<<endl;
						int nb=myliste->Chargement(fic,false);
						if(nb==0){
							cout<<">>> message: aucun trajet composé dans ce fichier !"<<endl;
						}else{
							cout<<nb<<" trajet(s) compos(é) chargé(s)."<<endl;
						}
					}
				}
			}
			else if (choixCh == 3)
			{
				int choixV;
				cout << ">>> Vous avez 3 sous-options:"<<endl;
				cout << "    Saisir 1 pour un chargement à partir d'une ville de départ." << endl;
				cout << "    Saisir 2 pour un chargement à partir d'une ville d'arrivée." << endl;
				cout << "    Saisir 3 pour un chargement à partir d'une ville de départ et une ville d'arrivée." << endl;
				cout<<  "    ===> Veuillez entrer votre choix:";
				cin >> choixV;
				while(choixV<1||choixV>3){
					cout<<"    Veuillez entrer un chiffre entre 1 et 3"<<endl;
					cout<<"    ===> Veuillez entrer votre choix:";
					cin>>choixV;
				}
				string nomFic; 
				ifstream fic;
				cout << "¤ Veuillez entrer un nom de fichier !" << endl;
				cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
				cin >> nomFic;
				fic.open(nomFic+".txt");
				while(!fic){
					cerr<<">>> message: ce fichier n'existe pas!"<<endl;
					cout<<"    saisir 0 pour réessayer, autre chiffre pour revenir au menu principal:";
					int retry;
					cin>>retry;
					if(!retry){
						//réessayer
						cout << "¤ Veuillez entrer un nom de fichier !" << endl;
						cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
						cin >> nomFic;
						fic.open(nomFic+".txt");
					}else{
						break;
					}
				}
				if (choixV == 1)
				{
					if(fic){
						cout << "¤ Veuillez entrer la ville de départ ! " << endl;
						string vd;
						cin >> vd;
						cout<<"-----------------------------------------------"<<endl;
						int nb=myliste->Chargement(fic,true,vd);
						if(nb==0){
							cout<<">>> message: aucun trajet dont la ville de départ est "<<vd<<" dans ce fichier !"<<endl;
						}else{
							cout<<nb<<" trajet(s) dont la ville de départ est "<<vd<<" chargé(s)"<<endl;
						}
					}
				}
				else if (choixV == 2)
				{
					if(fic){
						cout << "¤ Veuillez entrer la ville d'arrivée ! " << endl;
						string va;
						cin >> va;
						cout<<"-----------------------------------------------"<<endl;
						int nb=myliste->Chargement(fic,true,va);
						if(nb==0){
							cout<<">>> message: aucun trajet dont la ville d'arrivée est "<<va<<" dans ce fichier !"<<endl;
						}else{
							cout<<nb<<" trajet(s) dont la ville d'arrivée est "<<va<<" chargé(s)"<<endl;
						}
					}
				}
				else
				{
					if(fic){
						cout << "¤ Veuillez entrer la ville de départ ! " << endl;
						string vd;
						cin >> vd;
						cout << "¤ Veuillez entrer la ville d'arrivée ! " << endl;
						string va;
						cin >> va;
						cout<<"-----------------------------------------------"<<endl;
						int nb=myliste->Chargement(vd,va,fic);
						if(nb==0){
							cout<<">>> message: aucun trajet dont la ville de départ est "<<vd<<" et la ville d'arrivée est "<<va<<" dans ce fichier !"<<endl;
						}else{
							cout<<nb<<" trajet(s) dont la ville de départ est "<<vd<<" et la ville d'arrivée est "<<va<<" chargé(s)"<<endl;
						}
					}
				}
			}
			else if (choixCh==4)
			{

			}
			if(choixCh!=5){
				cout<<endl<<"--------fin du chargement--------"<<endl<<endl;
			}
		}
		else{
			//si l'utilisateur a saisi un chiffre non compris entre 1 et 6
			cout<<"Veuillez entrer un chiffre entre 1 et 6"<<endl;
			cout<<"-----------------------------------------------"<<endl;
		}
		cout<<"Saisir 1 pour ajouter un trajet simple"<<endl;
		cout<<"Saisir 2 pour ajouter un trajet compose"<<endl;
		cout<<"Saisir 3 pour afficher la catalogue"<<endl;
		cout<<"Saisir 4 pour faire une recherche simple de parcours"<<endl;
		cout<<"Saisir 5 pour faire une recherche avancée de parcours"<<endl;
		cout << "Saisir 6 pour faire une sauvegarde" << endl;
		cout << "Saisir 7 pour faire un chargement" << endl;
		cout<<"Saisir 8 pour quitter la catalogue"<<endl;
		cout<<"===> Veuillez entrer votre choix:";
		cin>>option;
		cout<<"-----------------------------------------------"<<endl;
	}
	cout<<"		A BIENTOT!"<<endl;
	delete myliste;
	return 0;
}
