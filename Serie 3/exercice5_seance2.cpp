#include <iostream>
#include <string>
using namespace std;
class Livre{
private:
    string titre;
    string auteur;
    int nombrePages;
public:
    Livre(string t, string a, int n): titre(t), auteur(a),nombrePages(n){}
    void afficherInfos(){
        cout<<endl<<titre<<" DE "<<auteur<<": "<<nombrePages<<endl;
    }
    friend void comparerLivres(const Livre &l1, const Livre &l2);
    friend void ajouterPages(Livre&, int);
};
void comparerLivres(const Livre &l1, const Livre &l2){
    if(l1.nombrePages > l2.nombrePages )
        {
            cout<<l1.titre<<endl;
        }
    else{
        cout<<l2.titre<<endl;
    }
}
void ajouterPages(Livre &l, int n){
    l.nombrePages += n;
}
int main(){
    Livre livre1("a", "b", 400);
    Livre livre2("c", "d", 600);   livre1.afficherInfos();
    livre2.afficherInfos();
    comparerLivres(livre1, livre2);
    ajouterPages(livre1, 50);
    livre1.afficherInfos();
    return 0;
}
