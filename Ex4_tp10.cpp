
#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
    // Constructeur
    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    // Afficher les informations
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email : " << email << endl;
    }

    // Retourner le nom
    string getNom() {
        return nom;
    }
};

// Afficher tous les contacts
void afficherContacts(Contact** carnet, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nContact " << i + 1 << endl;
        carnet[i]->afficher();
    }
}

// Supprimer un contact par son nom
void supprimerContact(Contact** carnet, int& n, string nom) {
    int position = -1;

    for (int i = 0; i < n; i++) {
        if (carnet[i]->getNom() == nom) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        cout << "Contact introuvable !" << endl;
    }
    else {
        delete carnet[position];

        for (int i = position; i < n - 1; i++) {
            carnet[i] = carnet[i + 1];
        }

        n--;

        carnet[n] = nullptr;

        cout << "Contact supprime avec succes !" << endl;
    }
}

int main() {
    int n;

    cout << "Combien de contacts voulez-vous ajouter ? ";
    cin >> n;

    // Allocation dynamique du carnet
    Contact** carnet = new Contact*[n];

    // Ajouter les contacts
    for (int i = 0; i < n; i++) {
        string nom, telephone, email;

        cout << "\nContact " << i + 1 << endl;

        cout << "Nom : ";
        cin >> nom;

        cout << "Telephone : ";
        cin >> telephone;

        cout << "Email : ";
        cin >> email;

        carnet[i] = new Contact(nom, telephone, email);
    }

    // Afficher les contacts
    cout << "\n--- Liste des contacts ---" << endl;
    afficherContacts(carnet, n);

    // Supprimer un contact
    string nomASupprimer;

    cout << "\nDonner le nom du contact a supprimer : ";
    cin >> nomASupprimer;

    supprimerContact(carnet, n, nomASupprimer);

    // Afficher la liste apres suppression
    cout << "\n--- Liste apres suppression ---" << endl;

    if (n > 0) {
        afficherContacts(carnet, n);
    }
    else {
        cout << "Le carnet est vide." << endl;
    }

    // Liberer toute la memoire restante
    for (int i = 0; i < n; i++) {
        delete carnet[i];
    }

    delete[] carnet;

    return 0;
}

