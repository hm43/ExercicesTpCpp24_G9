#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Article{
private:
    string id;
    string nom;
    string desc;
    int qte;
    float prix;
public:
    Article(){
        id = "";
        nom = "";
        desc = "";
        qte = 0;
        prix = 0;
    }
    Article(string id2, string nom, string desc, int qte, float prix): id(id2), nom(nom),desc(desc),qte(qte), prix(prix){}
    string getId(){
        return id;
    }
    void setId(string id){
        this->id = id;
    }
    string getNom(){
        return nom;
    }
    void setNom(string nom){
        this->nom = nom;
    }
    string getDesc(){
        return desc;
    }
    void setDesc(string desc){
        this->desc = desc;
    }
    float getPrix(){
        return prix;
    }
    void setPrix(float prix){
        this->prix = prix;
    }
    int getQte(){
        return qte;
    }
    void setQte(int qte){
        this->qte = qte;
    }
    
};

class Minimarche{
private:
    string nom;
    vector<Article> stock;
public:
    Minimarche(): nom(""){}
    Minimarche(string nom): nom(nom){}
    void ajouterArticle(){
        Article a;
        cin.ignore();
        string id;
        int qte;
        string nom;
        cout<<"Donner l'id: ";
        getline(cin, id);
        a.setId(id);
        cout<<"Donner le nom: ";
        getline(cin, nom);
        a.setNom(nom);
        cout<<"Donner la qte: ";
        cin>>qte;
        a.setQte(qte);
        
        stock.push_back(a);
        
    }
    
    void majQte(){
        string id;
        cout<<"Donner l'id de l'article a modifier: ";
        cin.ignore();
        getline(cin, id);
        for(int i = 0; i < stock.size(); i++){
            string str = stock[i].getId();
            if(str.compare(id) == 0){
                int qte;
                cout<<"L'ancienne quantite: "<<stock[i].getQte()<<endl;
                cout<<"Donner la nouvelle qte:";
                cin>>qte;
                stock[i].setQte(qte);
                break;
            }
        }
    }
    
    void afficher(){
        cout<<"Nom du Minimarche: "<<nom<<endl;
        for(int i = 0; i < stock.size(); i++){
            cout<<"Id: "<<stock[i].getId()<<" Nom: "<<stock[i].getNom()<<" qte: "<<stock[i].getQte()<<endl;
        }
    }
};
int main(){
    Minimarche m("X");
    int choix;
menu:
    cout<<endl<<" --------- Menu --------- "<<endl;
    cout<<"1. AJouter un article."<<endl;
    cout<<"2. Afficher un article."<<endl;
    cout<<"3. MAJ un article."<<endl;
    cout<<"4. Quitter."<<endl;
    cin>>choix;
    switch(choix){
        case 1:
            m.ajouterArticle();
            goto menu;
            break;
        case 2:
            m.afficher();
            goto menu;
            break;
        case 3:
            m.majQte();
            goto menu;
            break;
        default:
            cout<<"Au revoir."<<endl;
    }
    
    
    
    return 0;
}
