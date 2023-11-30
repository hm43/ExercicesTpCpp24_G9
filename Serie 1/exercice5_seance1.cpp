#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s[3] = {"En transit", "En chargement", "En maintenance"};
class Camion{
private:
    string idc;
    string modele;
    double capac;
    double km;
    string statut;
public:
    Camion():idc(""), modele(""), capac(0), km(0), statut(s[0]){}
    Camion(string idc, string modele): 
    idc(idc), modele(modele), capac(0), km(0), statut(s[0]){}
    Camion(string idc, string modele, double capac, double km, string statut):
    idc(idc), modele(modele), capac(capac), km(km), statut(statut){}
    string getId(){
        return idc;
    }
    void setId(string idc){
        this->idc = idc;
    }
    void afficher(){
        cout<<"L'id: "<<idc<<endl;
        cout<<"Le modele: "<<modele<<endl;
        cout<<"La capacite: "<<capac<<endl;
        cout<<"Le kilometrage: "<<km<<endl;
        cout<<"Le status: "<<statut<<endl;
        
    }
    
    
};
class GestionnaireDeFlotte{
private:
    string nom;
    vector <Camion> flotte;
public:
    void ajouterCamion(){
        int choix;
        cout<<"1. aucune information."<<endl;
        cout<<"2. Pour l'id et modele."<<endl;
        cout<<"3. Pour toutes les informations."<<endl;
        cin>>choix;
        string id, modele;
        int statut;
        double capac, km;
        if(choix == 1){
            Camion c1;
            flotte.push_back(c1);
        }else if(choix == 2)
                {
                    cout<<"Donner l'id: ";
                    getline(cin, id);
                    cout<<"Donner le modele: ";
                    getline(cin, modele);
                    Camion c2(id, modele);
                    flotte.push_back(c2);
                
    }else if(choix == 3)
                {
                    cout<<"Donner l'id: ";
                    getline(cin, id);
                    cout<<"Donner le modele: ";
                    getline(cin, modele);
                    cout<<"Donner capacite en tonne: ";
                    cin>>capac;
                    cout<<"Donner kilometrage: ";
                    cin>>km;
                    cout<<"Liste des status"<<endl;
                    for(int i = 0; i< 3; i++){
                        cout<<i+1<<" "<<s[i]<<endl;
                    }
                    cin>>statut;
                    Camion c3(id, modele, capac, km, s[statut - 1]);
                    flotte.push_back(c3);
                }
        
    }
    
};
int main() {
    return 0;
}
