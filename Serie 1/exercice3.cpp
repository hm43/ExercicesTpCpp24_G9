#include <iostream>
using namespace std;

class Pilechar{
private:
    int max;
    int sommet;
    char *pile;
public:
    Pilechar(){
        max = 50;
        sommet = 0;
        pile = new char[max];
    }
    Pilechar(int max){
        this->max = max;
        sommet = 0;
        pile = new char[max];
    }
    void empiler(char c){
        if(sommet < max)
        {
            pile[sommet] = c;
            sommet++;
        }else{
            cout<<"pile pleine."<<endl;
        }
    }
    void depiler(){
        if(sommet > 0)
            sommet--;
        else
            cout<<"pile vide"<<endl;
    }
    int taille(){
        return max;
    }
    int compter(){
        return sommet;
    }
    void afficher(){
        cout<<"[";
        for(int i = 0; i< sommet ; i++){
            cout<<pile[i];
            if(i < sommet-1){
                cout<<",";
            }
            
        }
        cout<<"]";
    }
};

int main()
{
    Pilechar p(3);
    p.empiler('a');
    p.empiler('b');
    p.empiler('c');
    p.depiler();
    p.empiler('d');
    p.afficher();
    
    return 0;
}

