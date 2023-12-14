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
        // Complexe c1, c2
        // c1 + c2
        // c1.operator+(c2)
        //
        double resultat_reel = reel + c.reel;
        double resultat_imaginaire = imaginaire + c.imaginaire;
        Complexe resultat(resultat_reel, resultat_imaginaire);
        return resultat;
    }
    Complexe operator-(const Complexe &c)
    {
        double resultat_reel = reel - c.reel;
        double resultat_imaginaire = imaginaire - c.imaginaire;
        Complexe resultat(resultat_reel, resultat_imaginaire);
        return resultat;
    }
    Complexe operator*(const Complexe &c)
    {
        double resultat_reel = reel * c.reel - imaginaire * c.imaginaire;
        double resultat_imaginaire = imaginaire * c.reel + c.imaginaire * reel;
        Complexe resultat(resultat_reel, resultat_imaginaire);
        return resultat;
    }
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
        os << c.reel << "+" << c.imaginaire << "i" << endl;
        return os;
    }
    friend istream &operator>>(istream &is, Complexe &c)
    {
        cout << "reel= ";
        is >> c.reel;
        cout << "imaginaire= ";
        is >> c.imaginaire;
        return is;
    }
};
int main()
{
    Complexe c1(1, 2);
    cout << c1;
    Complexe c2;
    cin >> c2;
    cout << c2;

    return 0;
}