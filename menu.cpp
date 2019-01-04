/*************************************************************************
									menu
							 -------------------
	début                : 31/12/2018
	copyright            : (C) 2018 par 32_08
	e-mail               : mengxin.zhang@insa-lyon.fr
						   manal.el-karchouni@insa-lyon.fr
*************************************************************************/

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
#include <cstdlib>

bool isNumber(string& line){
	char *p=nullptr;
	strtol(line.c_str(),&p,10);
	return strlen(p)==0;
}

int enterNumber(){
	string s;
	cin>>s;
	while(!isNumber(s)){
		cout<<">>> message: Veuillez saisir un chiffre!"<<endl;
		cin>>s;
	}
	return (int)strtol(s.c_str(),nullptr,10);
}
void tryOpenFile(ifstream &fic){
	string nomFic;
	cout << "¤ Veuillez entrer un nom de fichier !" << endl;
	cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
	cin>>nomFic;
	fic.open(nomFic+".txt");
	while(!fic){
		cerr<<">>> message: ce fichier n'existe pas!"<<endl;
		cout<<"    saisir 0 pour réessayer, autre chiffre pour revenir au menu principal:";
		int retry;
		retry=enterNumber();
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
}
void tryOpenReadingFile(ofstream &fic){
	string nomFic;
       	cout << "¤ Veuillez entrer un nom de fichier !" << endl;
        cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
        cin >> nomFic;
       	ifstream fin(nomFic+".txt");
       	if(fin){
       		int i=1;
          	bool ok=false;
           		while(!ok){
                       		fin.close();
                            	cout<<">>> message: ce fichier existe déjà,saisir 0 pour réssayer,autre chiffre pour continuer(le contenu sera écrasé):";
                               	i=enterNumber();
                             	if(i){
                                 	break;
                               	}
                             	cout << "¤ Veuillez entrer un nom de fichier !" << endl;
                             	cin >> nomFic;
                             	ifstream fin(nomFic+".txt");
                             	if(!fin){
                                    	ok=true;
                              	}
                    	}
     	}
     	fin.close();
       	fic.open(nomFic+".txt");
}
void enterNM(int length,int* n,int* m){
	cout<<">>> Merci de saisir un intervalle (0<n<=m<="<<length<<")"<<endl;
	cout << "¤ Saisir l'indice du premier trajet(n):";
	*n=enterNumber();
	while(!(*n>0&&*n<=length)){
		if(*n<=0){
			cout<<">>> message: n doit être supérieur au 0"<<endl;
			cout << "¤ Saisir l'indice du premier trajet(n):";
			*n=enterNumber();
		}
		if(*n>length){
			cout<<">>> message: n dépasse la taille du catalogue"<<endl;
			cout << "¤ Saisir l'indice du dernier trajet(n):";
			*n=enterNumber();
		}
	}
	cout << "¤ Saisir l'indice du dernier trajet(m):";
	*m=enterNumber();
	while(!(*m>0&&*m<=length)){
		if(*m<=0){
			cout<<">>> message: m doit être supérieur au 0"<<endl;
			cout << "¤ Saisir l'indice du premier trajet(m):";
			*m=enterNumber();
		}
		if(*m>length){
			cout<<">>> message: m dépasse la taille du catalogue"<<endl;
			cout << "¤ Saisir l'indice du dernier trajet(m):";
			*m=enterNumber();
		}
	}
	while(*n>*m){
		cout<<">>> message: n ne doit pas être plus grand que m, réessayez"<<endl;
		cout << "¤ Saisir l'indice du premier trajet(n):";
		*n=enterNumber();
		while(!(*n>0&&*n<=length)){
			if(*n<=0){
				cout<<">>> message: n doit être supérieur au 0"<<endl;
				cout << "¤ Saisir l'indice du premier trajet(n):";
				*n=enterNumber();
			}
			if(*n>length){
				cout<<">>> message: n dépasse la taille du catalogue"<<endl;
				cout << "¤ Saisir l'indice du dernier trajet(n):";
				*n=enterNumber();
			}
		}
		cout << "¤ Saisir l'indice du dernier trajet(m):";
		*m=enterNumber();
		while(!(*m>0&&*m<=length)){
			if(*m<=0){
				cout<<">>> message: m doit être supérieur au 0"<<endl;
				cout << "¤ Saisir l'indice du premier trajet(m):";
				*m=enterNumber();
			}
			if(*m>length){
				cout<<">>> message: m dépasse la taille du catalogue"<<endl;
				cout << "¤ Saisir l'indice du dernier trajet(m):";
				*m=enterNumber();
			}
		}
	}
}
int main(){
	ListeTrajet *myliste =new ListeTrajet;
	int option;//variable qui représente le choix d'utilisateur
	cout<<"-------------------BIENVENUE--------------------"<<endl;
	cout<<"- Saisir 1 pour ajouter un trajet simple."<<endl;
	cout<<"- Saisir 2 pour ajouter un trajet compose."<<endl;
	cout<<"- Saisir 3 pour afficher la catalogue."<<endl;
	cout<<"- Saisir 4 pour faire une recherche simple de parcours."<<endl;
	cout<<"- Saisir 5 pour faire une recherche avancée de parcours."<<endl;
	cout<<"- Saisir 6 pour faire une sauvegarde." << endl;
	cout<<"- Saisir 7 pour faire un chargement." << endl;
	cout<<"- Saisir 8 pour quitter la catalogue."<<endl;
	cout<<"===> Veuillez entrer votre choix:";
	option=enterNumber();
	while(option>8||option<1){
		cout<<">>> message: Veuillez entrer un chiffre entre 1 et 8"<<endl;
		option=enterNumber();
	}
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
			if(!myliste->Ajouter(ts)){
				//le cas où ce trajet existe déjà ==> message d'erreur
				cout<<">>> message: ce trajet existe déjà!"<<endl;
				cout<<"----------trajet non ajouté---------"<<endl<<endl;
				delete ts;
			}else{
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
				goOn=enterNumber();
			}while(!goOn);	
			if(!myliste->Ajouter(tc)){
				//le cas où ce trajet existe déjà ==> message d'erreur
				cout<<">>> message: ce trajet existe déjà!"<<endl;
				cout<<"----------trajet non ajouté---------"<<endl<<endl;
				delete tc;
			}else{
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
				choixSauv=enterNumber();
				while(choixSauv<1||choixSauv>5){	
					cout<<"    Veuillez entrer un chiffre entre 1 et 5"<<endl;
					cout<<"    ===> Veuillez entrer votre choix:";
					choixSauv=enterNumber();
				}
				cout<<"-----------------------------------------------"<<endl;
				if (choixSauv == 1) {
					ofstream fic;		
					tryOpenReadingFile(fic);
					int nb=myliste->Enregistrer(fic);
					cout<<"-----------------------------------------------"<<endl;
					cout<<nb<<" trajet(s) enregistré"<<endl;
					fic.close();		
				}
				else if (choixSauv == 2){
					int choixType;
					cout << ">>> Vous avez 2 sous-options:"<<endl;
					cout << "    Saisir 1 pour une sauvegarde des trajets simples." << endl;
					cout << "    Saisir 2 pour une sauvegarde des trajets composés." << endl;
					cout << "    ===> Veuillez entrer votre choix:";
					choixType=enterNumber();
					while(!(choixType==1||choixType==2)){
						cout<<"    Veuillez entrer soit 1 soit 2"<<endl;
						cout<<"    ===> Veuillez entrer votre choix:";
						choixType=enterNumber();
					}
					if (choixType == 1){
						ofstream fic;
						tryOpenReadingFile(fic);
						int nb=myliste->Enregistrer(fic,true);
						fic.close();
						if(nb==0){
							cout<<"-----------------------------------------------"<<endl;
							cout<<">>> message: aucun trajet simple dans ce catalogue !"<<endl;
							cout<<">>> le fichier est créé mais rien n'est enregistré"<<endl;
						}else{
							cout<<"-----------------------------------------------"<<endl;
							cout<<nb<<" trajet(s) simple(s) enregistré(s)."<<endl;
						}
					}else{
						ofstream fic;
						tryOpenReadingFile(fic);
						int nb=myliste->Enregistrer(fic,false);
						fic.close();
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
					choixV=enterNumber();
					while(choixV<1||choixV>3){
						cout<<"    Veuillez entrer un chiffre entre 1 et 3"<<endl;
						cout<<"    ===> Veuillez entrer votre choix:";
						choixV=enterNumber();
					}
					if (choixV == 1) {
						ofstream fic;
						tryOpenReadingFile(fic);
						cout << "¤ Veuillez entrer la ville de départ ! " << endl;
						string vd;
						cin >> vd;
						int nb=myliste->Enregistrer(fic,true,vd);
						fic.close();
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
						ofstream fic;
						tryOpenReadingFile(fic);
						cout << "¤ Veuillez entrer la ville d'arrivée ! " << endl;
						string va;
						cin >> va;
						cout << "¤ Veuillez entrer un nom de fichier !" << endl;
						cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
						int nb=myliste->Enregistrer(fic,false, va);	
						fic.close();
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
						ofstream fic;
						tryOpenReadingFile(fic);
						cout << "¤ Veuillez entrer la ville de départ ! " << endl;
						string vd;
						cin >> vd;
						cout << "¤ Veuillez entrer la ville d'arrivée ! " << endl;
						string va;
						cin >> va;
						cout << "¤ Veuillez entrer un nom de fichier !" << endl;
						cout << "  (Vous n'avez pas à entrer l'extension de nom de fichier \".txt\",elle sera ajoutée automatiquement)"<<endl;
						int nb=myliste->Enregistrer(vd,va,fic);
						fic.close();
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
					ofstream fic;
					tryOpenReadingFile(fic);
					int length=myliste->GetLength();
					int n,m;
					enterNM(length,&n,&m);
					int nbEnreg=myliste->Enregistrer(n, m, fic);
					fic.close();
					cout<<"-----------------------------------------------"<<endl;
					cout << nbEnreg << " trajet(s) enregistré(s)." << endl;
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
				ifstream fic;
				tryOpenFile(fic);
				if(fic){
					cout<<"-----------------------------------------------"<<endl;
					int nb=myliste->Chargement(fic);
					cout<<nb<<" trajet(s) chargé(s)"<<endl;
					fic.close();		
				}
			}
			else if (choixCh == 2)
			{
				int choixType;
				cout << ">>> Vous avez 2 sous-options:"<<endl;
				cout << "    Saisir 1 pour un chargement des trajets simples." << endl;
				cout << "    Saisir 2 pour un chargement des trajets composés." << endl;
				cout << "    ===> Veuillez entrer votre choix:";
				choixType=enterNumber();
				while(!(choixType==1||choixType==2)){	
					cout<<"    Veuillez entrer un chiffre entre 1 et 5"<<endl;
					cout<<"    ===> Veuillez entrer votre choix:";
					choixType=enterNumber();
				}
				ifstream fic;
				tryOpenFile(fic);
				if (choixType == 1)
				{
					if(fic){
						cout<<"-----------------------------------------------"<<endl;
						string s;
						getline(fic,s);
						int all=(int)strtol(s.c_str(),nullptr,10);
						int nb=myliste->Chargement(fic,true);
						if(nb==0){
							cout<<">>> message: aucun NOUVEAU trajet simple dans ce fichier !"<<endl;
						}else{
							cout<<nb<<" trajet(s) simple(s) chargé(s) parmi "<<all<<" trajet(s) dans le fichier"<<endl;
						}
						fic.close();
					}
				}
				else{
					if(fic){
						cout<<"-----------------------------------------------"<<endl;
						string s;
						getline(fic,s);
						int all=(int)strtol(s.c_str(),nullptr,10);
						int nb=myliste->Chargement(fic,false);
						if(nb==0){
							cout<<">>> message: aucun NOUVEAU trajet composé dans ce fichier !"<<endl;
						}else{
							cout<<nb<<" trajet(s) composé(s) chargé(s) "<<all<<" trajet(s) dans le fichier"<<endl;
						}
						fic.close();
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
				ifstream fic;
				tryOpenFile(fic);
				if (choixV == 1)
				{
					if(fic){
						string s;
						getline(fic,s);
						int all=(int)strtol(s.c_str(),nullptr,10);
						cout << "¤ Veuillez entrer la ville de départ ! " << endl;
						string vd;
						cin >> vd;
						cout<<"-----------------------------------------------"<<endl;
						int nb=myliste->Chargement(fic,true,vd);
						if(nb==0){
							cout<<">>> message: aucun NOUVEAU trajet dont la ville de départ est "<<vd<<" dans ce fichier !"<<endl;
						}else{
							cout<<nb<<" trajet(s) dont la ville de départ est "<<vd<<" chargé(s) parmi "<<all<<" trajet(s) de ce fichier"<<endl;
						}
						fic.close();
					}
				}
				else if (choixV == 2)
				{
					if(fic){
						string s;
						getline(fic,s);
						int all=(int)strtol(s.c_str(),nullptr,10);
						cout << "¤ Veuillez entrer la ville d'arrivée ! " << endl;
						string va;
						cin >> va;
						cout<<"-----------------------------------------------"<<endl;
						int nb=myliste->Chargement(fic,true,va);
						if(nb==0){
							cout<<">>> message: aucun NOUVEAU trajet dont la ville d'arrivée est "<<va<<" dans ce fichier !"<<endl;
						}else{
							cout<<nb<<" trajet(s) dont la ville d'arrivée est "<<va<<" chargé(s) parmi "<<all<<" trajet(s) de ce fichier"<<endl;
						}
					}
					fic.close();
				}
				else
				{
					if(fic){
						string s;
						getline(fic,s);
						int all=(int)strtol(s.c_str(),nullptr,10);
						cout << "¤ Veuillez entrer la ville de départ ! " << endl;
						string vd;
						cin >> vd;
						cout << "¤ Veuillez entrer la ville d'arrivée ! " << endl;
						string va;
						cin >> va;
						cout<<"-----------------------------------------------"<<endl;
						int nb=myliste->Chargement(vd,va,fic);
						if(nb==0){
							cout<<">>> message: aucun NOUVEAU trajet dont la ville de départ est "<<vd<<" et la ville d'arrivée est "<<va<<" dans ce fichier !"<<endl;
						}else{
							cout<<nb<<" trajet(s) dont la ville de départ est "<<vd<<" et la ville d'arrivée est "<<va<<" chargé(s) parmi "<<all<<" trajet(s) de ce fichier"<<endl;
						}
					}
					fic.close();
				}
			}
			else if (choixCh==4)
			{
				ifstream fic;
				tryOpenFile(fic);
				string s;
				if(fic){
					getline(fic,s);
					int all=(int)strtol(s.c_str(),nullptr,10);
					int n,m;
					enterNM(all,&n,&m);
					int nb=myliste->Chargement(n,m,fic);
					cout<<"-----------------------------------------------"<<endl;
					cout<<nb<<" trajet(s) chargé(s)"<<endl;
				}
			}
			if(choixCh!=5){
				cout<<endl<<"--------fin du chargement--------"<<endl<<endl;
			}
		}
		cout<<"- Saisir 1 pour ajouter un trajet simple"<<endl;
		cout<<"- Saisir 2 pour ajouter un trajet compose"<<endl;
		cout<<"- Saisir 3 pour afficher la catalogue"<<endl;
		cout<<"- Saisir 4 pour faire une recherche simple de parcours"<<endl;
		cout<<"- Saisir 5 pour faire une recherche avancée de parcours"<<endl;
		cout << "- Saisir 6 pour faire une sauvegarde" << endl;
		cout << "- Saisir 7 pour faire un chargement" << endl;
		cout<<"- Saisir 8 pour quitter la catalogue"<<endl;
		cout<<"===> Veuillez entrer votre choix:";
		option=enterNumber();
		while(option>8||option<1){
			cout<<">>> message: Veuillez entrer un chiffre entre 1 et 8"<<endl;
			option=enterNumber();
		}
		cout<<"-----------------------------------------------"<<endl;
	}
	cout<<"		A BIENTOT!"<<endl;
	delete myliste;
	return 0;
}
