#include <iostream>
#include <string>
#include <cstring>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "ListeTrajet.h"
using namespace std;

void TestTC(){
	TrajetSimple* ts1=new TrajetSimple("A","B","MT");
	TrajetSimple* ts2=new TrajetSimple("B","C","MT");
	TrajetCompose tc1;
	tc1.Ajouter(ts1);
	tc1.Ajouter(ts2);
	ofstream fic("TestEn.txt");
	tc1.Enregistrer(fic);

}

ListeTrajet& GenererListTest(ListeTrajet& mylist)
{
	TrajetSimple* t1 =new TrajetSimple("Lyon", "Bordeaux", "Train");
	TrajetSimple* t2 =new TrajetSimple("Lyon", "Paris", "Train");
	mylist.Ajouter(t1);
	mylist.Ajouter(t2);
	TrajetCompose* tc=new TrajetCompose;
	TrajetCompose* soustc=new TrajetCompose;
	TrajetSimple* ts1=new TrajetSimple("A","B","MT");
	TrajetSimple* ts2=new TrajetSimple("B","C","MT");
	soustc->Ajouter(ts1);
	soustc->Ajouter(ts2);
	TrajetSimple* ts3=new TrajetSimple("C","D","MT");
	tc->Ajouter(soustc);
	tc->Ajouter(ts3);
	mylist.Ajouter(tc);
	return mylist;
}

void TestEnregistrement() {
	ListeTrajet mylist;
	mylist=GenererListTest(mylist);
	mylist.Display();
	ofstream fic;
	fic.open("TestEn.txt");
	if(fic){
		mylist.Enregistrer(fic);
	}else{
		cerr<<"!"<<endl;
	}
}

void TestEnregistrementType() {	
	ListeTrajet mylist;
	mylist=GenererListTest(mylist);
	mylist.Display();
	ofstream fic;
	fic.open("TestEn.txt");
	if(fic){
		mylist.Enregistrer(fic,false);
	}else{
		cerr<<"!"<<endl;
	}
	fic.close();
}

void TestEnregistrementVD() {	
	ListeTrajet mylist;
	mylist=GenererListTest(mylist);
	mylist.Display();
	ofstream fic;
	fic.open("TestEn.txt");
	if(fic){
		mylist.Enregistrer(fic,true,"A");
	}else{
		cerr<<"!"<<endl;
	}
	fic.close();
}

void TestEnregistrementVA() {	
	ListeTrajet mylist;
	mylist=GenererListTest(mylist);
	mylist.Display();
	ofstream fic;
	fic.open("TestEn.txt");
	if(fic){
		mylist.Enregistrer(fic,false,"Paris");
	}else{
		cerr<<"!"<<endl;
	}
	fic.close();
}

void TestEnregistrementVDetVA() {	
	ListeTrajet mylist;
	mylist=GenererListTest(mylist);
	mylist.Display();
	ofstream fic;
	fic.open("TestEn.txt");
	if(fic){
		mylist.Enregistrer("Lyon","Bordeaux",fic);
	}else{
		cerr<<"!"<<endl;
	}
}

void TestChargementS() {
	ListeTrajet mylist;
	ifstream fic("TestCh.txt");
	string ligne;
	while(getline(fic,ligne)){
		if(ligne.compare("TS:")){
			//mylist.ChargementS(fic);
		}
	}
	mylist.Display();
	

}

void TestChargement(){
	ListeTrajet mylist;
	ifstream fic("Test.txt");
	mylist.Chargement(fic);
	mylist.Display();
}

void TestChargementTS(){
	ListeTrajet mylist;
	ifstream fic;
	fic.open("TestChType.txt");
	if(fic){
		mylist.Chargement(fic,true);
	}else{
		cerr<<"un probleme"<<endl;
	}
	fic.close();
	mylist.Display();
}

void TestChargementTC(){
	ListeTrajet mylist;
	ifstream fic("TestChType.txt");
	mylist.Chargement(fic,false);
	mylist.Display();
}

void TestChargementVD(){
	ListeTrajet mylist;
	ifstream fic("TestChType.txt");
	mylist.Chargement(fic,true,"Paris");
	mylist.Display();
}

void TestChargementVA(){
	ListeTrajet mylist;
	ifstream fic("TestChType.txt");
	mylist.Chargement(fic,false,"Lyon");
	mylist.Display();
}

void TestChargementVAetVD(){
	ListeTrajet mylist;
	ifstream fic("TestChType.txt");
	mylist.Chargement("Nice","Lyon",fic);
	mylist.Display();
}
void TestChargementIntervalle(){
	ListeTrajet mylist;
	ifstream fic("TestChType.txt");
	mylist.Chargement(2,6,fic);
	mylist.Display();
}
/*
void TestEnregistrementType() {
	ListeTrajet mylist;
	TrajetSimple* ts1 = new TrajetSimple("A", "B", "MT");
	TrajetSimple* ts2 = new TrajetSimple("B", "C", "MT");
	TrajetCompose* tc1=new TrajetCompose;
	tc1->Ajouter(ts1);
	tc1->Ajouter(ts2);
	TrajetSimple* ts3 =new TrajetSimple("Lyon", "Bordeaux", "Train");
	mylist.Ajouter(tc1);
	mylist.Ajouter(ts3);
	ofstream fic("TestType1.txt");
	mylist.Enregistrer(fic,false);

}*/

int main(){
	TestChargementIntervalle();
}
