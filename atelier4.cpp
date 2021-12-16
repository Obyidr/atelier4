#include <iostream>
#include <string>
#include <math.h>
#include <iterator>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

/////// atelier 4 /////////
//ex1:
class complexe
{
    int re,im;
public:
//creation de constructeur avec des valeures et par defaut
    complexe(int r=0,int i=0);
    void afficher() {
		cout << endl <<"votre resultat est:" << re <<" + i"<< im << endl;
	}
//fonction amie car les variables de classe sont privés
    friend complexe operator + (complexe &c1,complexe &c2 );
    friend complexe operator - (complexe &c1,complexe &c2 );
    friend complexe operator * (complexe &c1,complexe &c2 );
    friend complexe operator / (complexe &c1,complexe &c2 );
};
//inisialisation de constructeur
complexe::complexe(int r,int i)
{
    re=r;
    im=i;
}
//inisialisation des fonction amies
complexe operator + (complexe &c1,complexe &c2)
{
    complexe c=complexe();
    c.re=c1.re+c2.re;
    c.im=c1.im+c2.re;
    return c;
}
complexe operator - (complexe &c1,complexe &c2)
{
    complexe c=complexe();
    c.re=c1.re - c2.re;
    c.im=c1.im - c2.re;
    return c;
}
complexe operator * (complexe &c1,complexe &c2)
{
    complexe c=complexe();
    c.re=(c1.re * c2.re) - (c1.im * c2.im);
    c.im=(c1.re * c2.im) + (c1.im * c2.re);
    return c;
}
complexe operator / (complexe &c1,complexe &c2)
{
    complexe c=complexe();
    c.re=((c1.re * c2.re)+(c1.im * c2.im)) / (pow(c1.re,2)+pow(c2.re,2));
    c.im=((c1.im * c2.re)-(c1.re * c2.im)) / (pow(c1.re,2)+pow(c2.re,2));
    return c;
}
int main()
{
    int x1,y1,x2,y2,z;
    //creation les elements complexes
    cout << "Entrer votre premier nombre complexe:"<<endl;
    cout << "Entrer le real:";
    cin >> x1;
    cout << "Entrer l'imaginer:";
    cin >> y1;
    cout << "Entrer votre deuxième nombre complexe:"<<endl;
    cout << "Entrer le real:";
    cin >> x2;
    cout << "Entrer l'imaginer:";
    cin >> y2;
    cout << "Quel operateur vous pouvez choisir:"<<endl;
    cout << "1- addition" << endl << "2- soustraction" <<endl 
    << "3- multiplication" <<endl;
    cout << "4- division" << endl;
    cout << "Entrer votre choix: ";
    cin >>z;
    //condition de choisir les choix de menu
    while( z<1 || z>4 ){
        cout << "Votre choix n'existe pas"<<endl;
        cout << "Entrer votre choix: ";
        cin >> z;}
        //les operateurs mathématiques
        complexe z1(x1,y1),z2(x2,y2);
    if(z==1)
    {
        complexe z3=z1 + z2;
        z3.afficher();
    }
    if(z==2)
    {
        complexe z3=z1 - z2;
        z3.afficher();
    }
    if(z==3)
    {
        complexe z3=z1 * z2;
        z3.afficher();
    }
    if(z==4)
    {
        complexe z3=z1 / z2;
        z3.afficher();
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////
//ex2
void date( string &s)
{
    if (s.length() != 12)
        cout << "cette Date n'est pas logique";
    else 
    {
        //le jour
        if ( s.substr(0,2) == "01")
            cout << s.substr(1,1) << "er ";
        else
            cout << s.substr(1,1) << " ";
        //le mois
        if(s.substr(2,2) == "01")
            cout << "Janvier" << " ";
        if(s.substr(2,2) == "02")
            cout << "Fevrier" << " ";
        if(s.substr(2,2) == "03")
            cout << "Mars" << " ";
        if(s.substr(2,2) == "04")
        cout << "Avril" << " ";
        if(s.substr(2,2) == "05")
            cout << "Mai" << " ";
        if(s.substr(2,2) == "06")
            cout << "Juin" << " ";
        if(s.substr(2,2) == "07")
            cout << "Juillet" << " ";
        if(s.substr(2,2) == "08")
            cout << "Aout" << " ";
        if(s.substr(2,2) == "09")
            cout << "Septembre" << " ";
        if(s.substr(2,2) == "10")
            cout << "Octobre" << " ";
        if(s.substr(2,2) == "11")
            cout << "Novembre" << " ";
        if(s.substr(2,2) == "12")
            cout << "Decembre" << " ";
        cout << s.substr(4,4) << " ";
        cout << s.substr(8,2) << "H";
        cout << s.substr(10,2) << endl;

    }
}
int main()
{
    string s;
    cout << "Entrer votre Date: ";
    cin>>s;
    date(s);
    return 0;
} 
/////////////////////////////////////////////////////////////////////////////
//ex3
void afficher (list<int>l1)
{
    list <int> :: iterator itr1;
    for(itr1=l1.begin() ; itr1 != l1.end() ; ++itr1)
    {
        cout << *itr1 << " ";
    }
}
int main()
{
    list <int> liste;
    int x,y;
    cout << "Entrer le nombre d'élément:";
    cin >> x;
    for(int i=0;i<x;i++)
    {
        cout << "Entrer votre nombre: ";
        cin>>y;
        //insertion dans la liste
        liste.push_back(y);
    }
    cout << "Votre liste:";
    afficher(liste);
    cout << endl;
    cout << "Votre liste triée:";
    //la liste triée
    liste.reverse();
    afficher(liste);
    cout << endl;
    return 0;
}
////////////////////////////////////////////////////////////////////////
//ex4
void afficher (list<string>l1)
{
    list <string> :: iterator itr1;
    for(itr1=l1.begin() ; itr1 != l1.end() ; ++itr1)
    {
        cout << *itr1 << endl;
    }
}
int main()
{
    list <string> personne;
    
    personne.push_back("oubay el idrissi 20");
    personne.push_back("azzeddine salmoune 19");
    personne.push_back("jaber el mahjoub 20");

    afficher(personne);
    cout<<"la liste triée:"<<endl;
    personne.sort();
    afficher(personne);
    return 0;
} 
/////////////////////////////////////////////////////////////////////
//ex5:
//les deux premières question
//fonction d'affichage
 void afficher(set <int> st0)
{
    set <int> :: iterator itr;
    for(itr=st0.begin() ; itr != st0.end() ; ++itr)
        cout << *itr << " ";
}
//fonction de recherche
bool recherche1 (set <int> st0 ,int x)
{
    set <int> :: iterator itr;
    bool y;
    for(itr = st0.begin() ; itr != st0.end() ; ++itr)
        {
            if(x==*itr)
            {
                y = true;
                break;
            }
            else
            {
                y = false;
            }
        }
        if(y==1)
            cout << "la valeur existe"<<endl;
        else
            cout << "la valeur n'existe pas"<<endl;
        return y;
}
int main()
{
    //1-2;
    set <int> MySet1;
    int n;
    //affiche de 1 jusqu'a 100
    for (int i=1;i<=100;i++)
    {
        MySet1.insert(i);
    }
    afficher(MySet1);
    cout<<endl;
    //la valeur de recherche
    cout<<"entrer votre valeur rechercher:";
    cin>>n;
    recherche1(MySet1,n);
    return 0;
} 
///////////////////////////////////////////////////////////////////////////
//ex6
class Test
{
public:
static int tableau[] ;
public :
static int division(int indice, int diviseur)
    {
        //impossible de diviser sur zèro
        if (diviseur==0)
            throw "impossible de diviser avec 0 !!";
        return tableau[indice]/diviseur;
    }
};
int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5} ;
int main()
    {
        int x, y;
        cout << "Entrez l’indice de l’entier à diviser: " << endl;
        cin >> x ;
        try
        {
            cout << "Entrez le diviseur: " << endl;
            cin >> y ;
        }
        catch(const char* err)
        {
            cerr <<" le diviseur avec la valeur " <<err;
        }
            cout << "Le résultat de la division est: "<< endl;
            cout <<Test::division(x,y) << endl;

        return 0;
    }
///////////////////////////////////////////////////////////////////////////
//ex7
class Chat ;
class Repas ;
class Elements ;

class Chat {

    private:
    string type;
    list<Repas> listRepas;
    
    public :
    Chat(String type){
        this->type = type;
    }
    void setType(String type){
        this->type = type;
    }
    String getType(){
        return this->type;
    }
    void setListRepas(list<Repas> listRp){
        this->listRepas = listRp ;
    }
    list<Repas> getListRepas(){
        return this->listRepas ;
    }
    void sauter(){
        return 0;
    }
};


class Repas {
private:
	string nom ;
    int heure;
	string description;
	Chat chat ;
	list <Elements > *e1 ; 
public : 
	Repas(String nom, int heure, String description){
        this->nom = nom;
        this->heure = heure;
        this->description = description;
	    e1 = new list <Elements> ();
} 
void setNom(string nom)
{
    this->nom = nom ; 
}
string getNom()
{
    return this->nom ; 
}
void setHeure(int heure )
{
    this->heure= heure ; 
}
int  getHeure()
{
    return this->heure; 
}
void setDescription(string description)
{
    this->description = description ; 
}
string getDescription()
{
    return this->description ; 
}
void setListElements(list<Elements> *e1)
{
    this->e1 = e1 ; 
}
list<Elements>* getListElements(){ return this->e1; }

void setChat(Chat c){
        this->chat = c ;
    }
    Chat getChat(){
        return this->chat ;
    }
~Repas ()
{ 
    delete this->liste ; cout << "call dist of Repas" << endl ;
}
};
class Elements {
	 private:
	string nom;
	string type;
	Repas rps ;
public :
 void setNom(string nom){
    this->nom = nom ; }
string getNom(){
    return this->nom ; }
void setType(string type){
    this->type = type; }
string getType(){
    return this->type ; }

void setRepas( Repas rps){
    this->rps = rps; }
Repas getRepas(){
    return this->rps ; }
~Elements(){ cout << "call dist of Elements " << endl ;
} };

class Animal; 
class Chien;
class Race;

class Animal {
protected :
string nom ;
int age;
string genre ;
public:
Animal (){};
Animal (string n,int a,string g){
	nom=n;
	age=a;
	genre =g;
}
void afficher(){
	cout << "nom:"<<nom<<"age:"<<age<<"genre :"<<genre<<endl;
}
void setNom(string nom){

	this->nom=nom;
}
string  getNom(){

	return this->nom;
}
void setAge(int age ){

	this->age=age;
}
int  getAge( ){

	 return this->age;
}
void setGenre(string genre){

	this->genre=genre;
}
string  getGenre(){

	return this->genre;
}

};
class Chat : public Animal {
	private:
	string type ;
	public:
	Chat (string n,int a,string g,string t):Animal (n,a,g){
		type=t;
	}

	void setType(string type){

	this->type=type;
    }
     string  getType(){

	return this->type;
    }
	void sauter(){
		 cout<<"Le type est : "<< type <<endl;

	}
};
class Race{
	protected :
	string specificite ;
	
	public:
		string test1;
    Race (){};
	Race (string s){
		specificite=s;

	}
	void setSpecificite(string specificite){

	this->specificite=specificite;
    }
     string  getSpecificite(){

	return this->specificite;
    }
	 bool isracehybride (){
	if (specificite==test1){
		return true ;}
		else {
	return false;
	}}	

};

class Chien;
class Entraineur;
class Composition;

class Chien :public Animal,public Race{
private:
String taille;
list<Entraineur> listEntraineur;
public :
Chien (string n,int a, string g, string s, string t) : public Animal ( n, a, g),public Race( s){
    this->taille = taille ;
}
void setTaille(String taille){
    this->taille = taille ;
}
String getTaille(){
    return this->taille;
}
void getListEntraineur(list<Entraineur> listEnt){
    this->listEntraineur = listEnt;
}
list<Entraineur> getListEntraineur(){
    return this->listEntraineur;
}
bool ischass3(){
    return true;
}
};

class Entraineur {
private:
String nom;
String description;
list<Chien> listChien;
public :
Entraineur(String nom, String description){
    this->nom = nom;
    this->description = description;
}
void setNom(String nom){
this->nom = nom;
}
String getNom(){
return this->attb ;
}
void setdescription(String description){
this->description = description;
}
String getdescription(){
return this->description ;
}
void setListChien(list<Chien> listChien){
this->listChien = listChien;
}
list<Chien> getListChien(){
return this->listChien ;
}
};

class Composition{
private :
String date;
String nom;
Entraineur e;
Chien c;
public :
int ordre;
Composition(String date, String nom, int ordre){
    this->nom = nom;
    this->date = date;
    this->ordre = ordre;
}
void setNom(String nom){
   this->nom = nom;
}
String getNom(){
    return this->nom ;
}
void setDate(String date){
    this->date = date;
}
String getDate(){
    return this->date ;
}
void setOrdre(String ordre){
    this->ordre = ordre;
}
String getOrdre(){
    return this->ordre ;
}
void setChien(Chien c){
this->c = c ;
}
Chien getChien(){
return this->c ;
}
void setEntraineur(Entraineur e){
this->e = e;
}
Entraineur getEntraineur(){
return this->e ;
}
};
