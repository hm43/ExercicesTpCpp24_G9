#include <iostream>
#include <string>
using namespace std;
class Transaction;

class Cryptomonnaie{
private:
    string nom;
    double valeur;
public:
    Cryptomonnaie(string n, double v):nom(n), valeur(v){}
    string getNom(){
        return nom;
    }
    double getValeur(){
        return valeur;
    }
};

class Portefeuille{
private:
    double solde;
    string proprietaire;
public:
    Portefeuille(double s, string p):solde(s), proprietaire(p){}
    void afficherSolde(){
        cout<<solde;
    }
    friend class Transaction;
};
class Transaction{
public:
    void effectuerTransaction(Portefeuille &de, Portefeuille &a, double montant,  Cryptomonnaie &c){
        if(de.solde > montant){
            a.solde += montant * c.getValeur();
            de.solde -= montant;
            cout<<montant<<" Transferer de: "<<de.proprietaire<<" a "<<a.proprietaire<<" avec le taux de: "<<c.getNom()<<endl;
        }else{
            cout<<"Solde insufisant de: "<<de.proprietaire<<endl;
        }
    }
};
int main(){
    Cryptomonnaie USD_MAD("USD_MAD", 10);
    Portefeuille a1(10000, "A1");
    Portefeuille a2(10200, "A2");
    
    Transaction t;
    t.effectuerTransaction(a1, a2, 1000, USD_MAD);
    return 0;
}
