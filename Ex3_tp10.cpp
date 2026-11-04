
#include <iostream>
#include <string>
using namespace std;

class Livre {
private:
    string titre;
    double prix;

public:
    // Constructeur
    Livre() {
        titre = "";
        prix = 0;
    }

    // Saisir les informations
    void saisir() {
        cout << "Donner le titre du livre : ";
        cin >> titre;

        cout << "Donner le prix du livre : ";
        cin >> prix;
    }

    // Afficher les informations
    void afficher() {
        cout << "Titre : " << titre << endl;
        cout << "Prix : " << prix << " DH" << endl;
    }
};

int main() {
    int n;

    // Saisir le nombre de livres
    cout << "Combien de livres voulez-vous creer ? ";
    cin >> n;

    // Allocation dynamique du tableau
    Livre* livres = new Livre[n];

    // Saisir les livres
    for (int i = 0; i < n; i++) {
        cout << "\nLivre " << i + 1 << endl;
        livres[i].saisir();
    }

    // Afficher tous les livres
    cout << "\n--- Liste des livres ---" << endl;

    for (int i = 0; i < n; i++) {
        livres[i].afficher();
    }

    // Liberer la memoire
    delete[] livres;

    return 0;
}
