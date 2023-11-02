#include<iostream>
#include<string>
#include<cmath>

using namespace std;
class Point{
private:
    float x;
    float y;
public:
    Point(){
        x = 0;
        y = 0;
    }
    Point(float x, float y){
        this->x = x;
        this->y = y;
    }
    float getX(){
        return x;
    }
    void setX(float x){
        this->x = x;
    }
    float getY(){
        return y;
    }
    void setY(float y){
        this->y = y;
    }
    string afficher(){
        string s = "("+to_string(x)+", "+to_string(y)+")";
        return s;
    }
    float distance(Point p){
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }

};
int main(){
    Point p;
    Point p2(2.5 , -1.33);
    cout<<"La distance entre "<<p.afficher()<<" et "<<p2.afficher()<<": "
    <<p.distance(p2)<<endl;

    
    

    return 0;
}