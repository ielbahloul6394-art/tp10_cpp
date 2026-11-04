
#include <iostream>
using namespace std;

int main() {
    int n;

    // Saisir la taille du tableau
    cout << "Donner la taille du tableau : ";
    cin >> n;

    // Allocation dynamique
    int* tab = new int[n];

    // Saisir les valeurs
    for (int i = 0; i < n; i++) {
        cout << "Donner la valeur " << i + 1 << " : ";
        cin >> tab[i];
    }

    // Afficher les valeurs
    cout << "Les valeurs du tableau sont : ";
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }

    cout << endl;

    // Liberer la memoire
    delete[] tab;

    return 0;
}
