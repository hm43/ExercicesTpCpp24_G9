#include<iostream>
#include <string>
using namespace std;
class Cryptomonnaie{
    string nom;
    double valeur;
public:
    Cryptomonnaie(string nom, double valeur){
        this->nom = nom;
        this->valeur = valeur;
    }
    string getNom(){
        return nom;
    }
    double getValeur(){
        return valeur;
    }
};
class Portefeuille{
    double solde;
    string proprietaire;
public:
    Portefeuille(double solde, string p):solde(solde), proprietaire(p){}
    void afficherSolde(){
        cout<<solde<<endl;
    }
    friend class Transaction;
};
class Transaction{
public:
    void effectuerTransaction(Portefeuille &p1, Portefeuille &p2, double montant, Cryptomonnaie &c){
        if(p1.solde >= montant){
            cout<<"Les soldes avant transaction: "<<endl<<"de: "<<p1.proprietaire<<": ";
            p1.afficherSolde();
            cout<<endl<<" et de: "<<p2.proprietaire<<": ";
            p2.afficherSolde();
            cout<<endl;
            p1.solde -= montant;
            p2.solde = p2.solde + montant * c.getValeur();
            cout<<"Les soldes apres transaction: "<<endl<<"de: "<<p1.proprietaire<<": ";
            p1.afficherSolde();
            cout<<endl<<" et de: "<<p2.proprietaire<<": ";
            p2.afficherSolde();
            cout<<endl;
        }
    }
};

int main(){
    Portefeuille p1(100000, "premier");
    Portefeuille p2(2000, "deuxieme");
    Cryptomonnaie USD_MAD("USD_MAD", 10);
    
    Transaction t;
    t.effectuerTransaction(p1, p2, 100, USD_MAD);
    return 0;
}
