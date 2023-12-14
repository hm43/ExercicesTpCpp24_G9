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
    void setStatut(string statut){
        this->statut = statut;
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
        }else if(choix == 2){
            cout<<"Donner l'id: ";
            cin.ignore();
            getline(cin, id);
            cout<<"Donner le modele: ";
            getline(cin, modele);
            Camion c2(id, modele);
            flotte.push_back(c2);
        }else if(choix == 3){
            cout<<"Donner l'id: ";
            cin.ignore();
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
    void majStatut(){
        string idc;
        int statut;
        cout<<"DOnner l'id du camion: ";
        cin.ignore();
        getline(cin, idc);

        for(Camion &c: flotte){
            if(c.getId().compare(idc) == 0){
                do{
                cout<<"Liste des status: "<<endl;
                for(int i = 0; i< 3; i++){
                    cout<<i+1<<" "<<s[i]<<endl;
                }
                cin>>statut;
                }while(statut > 3 || statut < 1 );
                
                c.setStatut(s[statut-1]);
                break;
            }
        }
    }
    void afficher(){
        cout<<"Le nom est: "<<nom<<endl;
        for(Camion &c: flotte){
            c.afficher();
        }
    }
    
};
int main() {
    GestionnaireDeFlotte g;
    int choix;
    do{
        cout<<"    Menu"<<endl;
    cout<<"1. Ajouter un camion."<<endl;
    cout<<"2. Modifier le statut d'un camion avec l'id."<<endl;
    cout<<"3. Afficher les camions"<<endl;
    cout<<"4. Quitter"<<endl;
    cin>>choix;
    switch(choix){
        case 1:
            g.ajouterCamion();
            break;
        case 2:
            g.majStatut();
            break;
        case 3:
            g.afficher();
            break;
        case 4:
            cout<<"EXIT."<<endl;
            break;
        default:
            cout<<"Mauvais choix."<<endl;


    }
    }while (choix != 4);
    
    return 0;
}
