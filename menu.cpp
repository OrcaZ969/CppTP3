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
	cout <<"Saisir 6 pour faire une sauvegarde" << endl;
	cout <<"Saisir 7 pour faire un chargement" << endl;
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
		int choixSauv;
		cout << ">>> Saisir 1 pour une sauvegarde sans critère de sélection." << endl;
		cout << ">>> Saisir 2 pour une sauvegarde selon le type de trajet." << endl;
		cout << ">>> Saisir 3 pour une sauvegarde selon la ville de départ et/ou la ville d'arrivée." << endl;
		cout << ">>> Saisir 4 pour une sauvegarde selon une sélection de trajets." << endl;
		cout << ">>> Saisir 5 pour quitter" << endl;
		cin >> choixSauv;
		while (choixSauv != 5)
		{
			if (choixSauv == 1) 
			{
				string nomFic; 
				cout << "Veuillez entrer un nom de fichier !" << endl;
				cin >> nomFic;
				ofstream fic(nomFic+".txt");
				myliste->Enregistrer(fic);
			}
			else if (choixSauv == 2)
			{
				int choixType;
				cout << ">>> Saisir 1 pour une sauvegarde des trajets simples." << endl;
				cout << ">>> Saisir 2 pour une sauvegarde des trajets composés." << endl;
				cin >> choixType;
				if (choixType == 1)
				{
					string nomFic;
					cout << "Veuillez entrer un nom de fichier !" << endl;
					cin >> nomFic;
					ofstream fic(nomFic+".txt");
					myliste->EnregistrerType(fic, 1);
				} 
				else
				{
					string nomFic;
					cout << "Veuillez entrer un nom de fichier !" << endl;
					cin >> nomFic;
					ofstream fic(nomFic+".txt");
					myliste->EnregistrerType(fic, 2);
				}
			}
			else if (choixSauv == 3)
			{
				int choixV;
				cout << ">>> Saisir 1 pour une sauvegarde à partir d'une ville de départ." << endl;
				cout << ">>> Saisir 2 pour une sauvegarde à partir d'une ville d'arrivée." << endl;
				cout << ">>> Saisir 3 pour une sauvegarde à partir d'une ville de départ et une ville d'arrivée." << endl;
				cin >> choixV;
				if (choixV == 1) {
					cout << "Veuillez rentrer la ville de départ ! " << endl;
					string vd;
					cin >> vd;
					cout << "Veuillez entrer un nom de fichier !" << endl;
					string nomFic;
					cin >> nomFic;
					ofstream fic(nomFic + ".txt");
					myliste->EnregistrerVD(fic, vd);
				}
				else if (choixV == 2) {
					cout << "Veuillez rentrer la ville d'arrivée ! " << endl;
					string va;
					cin >> va;
					cout << "Veuillez entrer un nom de fichier !" << endl;
					string nomFic;
					cin >> nomFic;
					ofstream fic(nomFic + ".txt");
					myliste->EnregistrerVA(fic, va);

				}
				else {
					cout << "Veuillez rentrer la ville de départ ! " << endl;
					string vd;
					cin >> vd;
					cout << "Veuillez rentrer la ville d'arrivée ! " << endl;
					string va;
					cin >> va;
					cout << "Veuillez entrer un nom de fichier !" << endl;
					string nomFic;
					cin >> nomFic;
					ofstream fic(nomFic + ".txt");
					myliste->EnregistrerVDetVA(fic, vd,va);
				}
			}
			else
			{

			}
			cout << ">>> Saisir 1 pour une sauvegarde sans critère de sélection." << endl;
			cout << ">>> Saisir 2 pour une sauvegarde selon le type de trajet." << endl;
			cout << ">>> Saisir 3 pour une sauvegarde selon la ville de départ et/ou la ville d'arrivée." << endl;
			cout << ">>> Saisir 4 pour une sauvegarde selon une sélection de trajets." << endl;
			cout << ">>> Saisir 5 pour quitter" << endl;
			cin >> choixSauv;
			cout << "-----------------------------------------------" << endl;
		}
		}
		else if (option == 7) { // options de chargement 
		int choixCh;
		cout << ">>> Saisir 1 pour un chargement sans critère de sélection." << endl;
		cout << ">>> Saisir 2 pour un chargement selon le type de trajet." << endl;
		cout << ">>> Saisir 3 pour un chargement selon la ville de départ et/ou la ville d'arrivée." << endl;
		cout << ">>> Saisir 4 pour un chargement selon une sélection de trajets." << endl;
		cout << ">>> Saisir 5 pour quitter" << endl;
		cin >> choixCh;
		while (choixCh != 5)
		{
			if (choixCh == 1)
			{
		
			}
			else if (choixCh == 2)
			{
				int choixType;
				cout << ">>> Saisir 1 pour un chargement des trajets simples." << endl;
				cout << ">>> Saisir 2 pour un chargement des trajets composés." << endl;
				cin >> choixType;
				if (choixType == 1)
				{
				
				}
				else
				{
				
				}
			}
			else if (choixCh == 3)
			{

			}
			else
			{

			}
			cout << ">>> Saisir 1 pour un chargement sans critère de sélection." << endl;
			cout << ">>> Saisir 2 pour un chargement selon le type de trajet." << endl;
			cout << ">>> Saisir 3 pour un chargement selon la ville de départ et/ou la ville d'arrivée." << endl;
			cout << ">>> Saisir 4 pour un chargement selon une sélection de trajets." << endl;
			cout << ">>> Saisir 5 pour quitter" << endl;
			cin >> choixCh;
			cout << "-----------------------------------------------" << endl;
		}
		
			
		
		cout << "--------fin de la recherche--------" << endl << endl;
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
