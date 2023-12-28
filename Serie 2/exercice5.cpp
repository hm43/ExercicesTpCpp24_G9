#include <iostream>
#include <string>

using namespace std;
class Livre{
    string titre;
    string auteur;
    int nombrePages;
public:
    Livre(string t, string a, int p): titre(t), auteur(a),nombrePages(p){}
    void afficherInfos(){
        cout<<endl<<titre<<" DE "<<auteur<<": "<<nombrePages<<endl;
    }
    friend void comparerLivres(const Livre &, const Livre &);
    friend void ajouterPages( Livre &, int);
};
void comparerLivres(const Livre &l1, const Livre &l2){
    if(l1.nombrePages > l2.nombrePages){
        cout<<l1.titre<<" est le plus grand."<<endl;
    }else{
        cout<<l2.titre<<" est le plus grand."<<endl;
    }
}
void ajouterPages( Livre &l, int n){
    l.nombrePages += n;
}
int main(){
    // Créez des objets Livre
    Livre livre1("Harry Potter", "J.K. Rowling", 400);
    Livre livre2("Le Seigneur des Anneaux", "J.R.R. Tolkien", 600);
    // Affichez les informations des livres
    livre1.afficherInfos();
    livre2.afficherInfos();
    // Comparez les livres et affichez le titre du livre avec le plus de pages
    comparerLivres(livre1, livre2);
    // Ajoutez 50 pages au premier livre et affichez les nouvelles informations
    ajouterPages(livre1, 50);
    livre1.afficherInfos();
    
    return 0;
}
