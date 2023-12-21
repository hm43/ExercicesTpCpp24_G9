#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee{
    string id;
    string nom;
    double salaire;
    static int employeeCount;
    static double bonusPourcentage;
public:
    Employee(){
        employeeCount++;
        id = to_string(employeeCount);
        nom = "";
        salaire = 0;
    }
    Employee(string nom, double salaire){
        employeeCount++;
        id = to_string(employeeCount);
        this->nom = nom;
        this->salaire = salaire;
    }
    Employee(const Employee &e){
        employeeCount++;
        id = to_string(employeeCount);
        this->nom = e.nom;
        this->salaire = e.salaire;
    }
    ~Employee(){
        employeeCount--;
    }
    double operator+(const Employee &e){
        return salaire + e.salaire;
    }
    friend ostream& operator<<(ostream&o, const Employee &e){
        o<<endl<<"id: "<<e.id<<endl;
        o<<"nom: "<<e.nom<<endl;
        o<<"salaire: "<<e.salaire<<endl;
        return o;
    }
    void promoter(double montant){
        this->salaire = salaire + montant;
    }
    static double averageSalary(vector<Employee> &es){
        if(employeeCount == 0) return 0;
        double total = 0;
        double moyenne;
        for(Employee &e: es){
            total += e.salaire;
        }
        moyenne = total / es.size();
        return moyenne;
    }
    static void setBonusPercentage(double per){
        bonusPourcentage = per;
    }
    void awardBonus(){
        salaire += salaire * (bonusPourcentage/100);
    }
};
int Employee::employeeCount = 0;
double Employee::bonusPourcentage = 0;
int main(){
    vector<Employee> employees;
    Employee::setBonusPercentage(10.0); // 10% bonus
    Employee emp1("Alice", 50000.0);
    Employee emp2("Bob", 60000.0);
    Employee emp3("Charlie", 70000.0);
    employees.push_back(emp1);
    employees.push_back(emp2);
    employees.push_back(emp3);
    cout << "Somme des employees 1 et 2: " << emp1 + emp2 << endl;
    emp3.promoter(5000.0);
    cout << "Employee apres promotion: " << emp3 << endl;
    cout << "Salaire moyenne: " << Employee::averageSalary(employees) << endl;
    for (auto& emp : employees) {
        emp.awardBonus();
    }
    cout << "Employees apres bonus:"<<endl;
    for (const auto& emp : employees) {
        cout << emp << endl;
    }


    return 0;
}
