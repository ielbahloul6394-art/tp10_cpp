
#include <iostream>
#include <string>
using namespace std;

class Personne {
private:
    string nom;
    int age;

public:
    // Constructeur
    Personne(string n, int a) {
        nom = n;
        age = a;
    }

    // Methode d'affichage
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Age : " << age << " ans" << endl;
    }
};

int main() {
    // Allocation dynamique avec new
    Personne* p = new Personne("Imane", 20);

    // Afficher les donnees
    p->afficher();

    // Liberer la memoire
    delete p;

    return 0;
}
