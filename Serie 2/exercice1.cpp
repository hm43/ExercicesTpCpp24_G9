#include <iostream>
#include <string>
using namespace std;
class Livre{
    private:
        string titre;
        string auteur;
        static int nombreExemplaires;
    public:
        Livre(){
            titre = "";
            auteur = "";
            nombreExemplaires++;
        }
        Livre(string titre, string auteur){
            this->titre = titre;
            this->auteur = auteur;
            nombreExemplaires++;
        }
        Livre& operator+(const Livre &l){
            
        }

};
int main(){
    return 0;
}