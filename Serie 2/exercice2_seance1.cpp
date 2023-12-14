
#include <iostream>
using namespace std;
class Complexe
{
private:
    double reel;
    double imaginaire;

public:
    Complexe()
    {
        reel = 0;
        imaginaire = 0;
    }
    Complexe(double reel, double imaginaire)
    {
        this->reel = reel;
        this->imaginaire = imaginaire;
    }
    Complexe operator+(const Complexe &c)
    {
        // 1+2
        // c1 + c2
        double resultat_reel = reel + c.reel;
        double resultat_imaginaire = imaginaire + c.imaginaire;
        // Complexe c(1, 2)
        Complexe resultat(resultat_reel, resultat_imaginaire);
        return resultat;
    }
    Complexe operator-(const Complexe &c)
    {
        return Complexe(reel - c.reel, imaginaire - c.imaginaire);
    }
    Complexe operator*(const Complexe &c)
    {
        double resultat_reel = reel * c.reel - imaginaire * c.imaginaire;
        double resultat_imaginaire = imaginaire * c.reel + reel * c.imaginaire;
        return Complexe(resultat_reel, resultat_imaginaire);
    }
    // if(1 == 1)
    // cout<<"ok";
    bool operator==(const Complexe &c)
    {
        if (reel == c.reel && imaginaire == c.imaginaire)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend ostream &operator<<(ostream &os, const Complexe &c)
    {
        if (c.reel != 0)
        {
            os << c.reel;
        }
        if (c.imaginaire > 0)
        {
            if (c.reel != 0)
                os << "+";
            os << c.imaginaire << "i";
        }
        else if (c.imaginaire < 0)
            os
                << c.imaginaire << "i";

        os << endl;
        return os;
    }
    friend istream &operator>>(istream &is, Complexe &c)
    {
        cout << "reel= ";
        is >> c.reel;
        cout << "Imaginaire= ";
        is >> c.imaginaire;
        return is;
    }
};
int main()
{
    Complexe c1(1, 0);
    Complexe c2;
    cin>>c2;
    Complexe c3 = c1 + c2;
    cout << c3;
    Complexe c4 = c1 - c2;
    cout<<c4;
    Complexe c5 = c1 * c2;
    cout<<c5;
    if(c1 == c2){
        cout<<"c1 == c2"<<endl;
    }else{
        cout<<"c1 != c2"<<endl;
    }
    
    return 0;
}
