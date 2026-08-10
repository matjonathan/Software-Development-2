#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

class Pet {
public:
    string name, breed;
    int age;
    bool vaccinated;

    void save(ofstream& out) {
        out << name << "," << breed << "," << age << "," << vaccinated << endl;
    }

    static Pet load(const string& line) {
        Pet p;
        stringstream ss(line);
        string token;
        getline(ss, p.name, ',');
        getline(ss, p.breed, ',');
        getline(ss, token, ','); p.age = stoi(token);
        getline(ss, token, ','); p.vaccinated = stoi(token);
        return p;
    }
};

vector<Pet> pets;

void loadPets() {
    ifstream in("pets.txt");
    string line;
    pets.clear();
    while (getline(in, line)) {
        pets.push_back(Pet::load(line));
    }
    in.close();
}

void savePets() {
    ofstream out("pets.txt");
    for (Pet& p : pets)
        p.save(out);
    out.close();
}

void addPet() {
    Pet p;
    cout << "Enter pet name: "; getline(cin, p.name);
    cout << "Enter pet breed: "; getline(cin, p.breed);
    cout << "Enter pet age: "; cin >> p.age;
    cout << "Is pet vaccinated (1-Yes, 0-No): "; cin >> p.vaccinated;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    pets.push_back(p);
    savePets();
}

void displayPets() {
    for (const Pet& p : pets)
        cout << "Name: " << p.name << ", Breed: " << p.breed << ", Age: " << p.age
        << ", Vaccinated: " << (p.vaccinated ? "Yes" : "No") << endl;
}

void petMenu() {
    int choice;
    do {
        cout << "\nPet Management\n1. Add Pet\n2. Display Pets\n3. Exit\nChoice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1: addPet(); break;
        case 2: displayPets(); break;
        }
    } while (choice != 3);
}

int main() {
    loadPets();
    petMenu();
    return 0;
}
