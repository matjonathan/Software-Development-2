#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>

// Base User class
class User {
protected:
    std::string username;
    std::string role;
public:
    User(std::string u, std::string r) : username(u), role(r) {}
    virtual void displayMenu() = 0;
    virtual ~User() {}
};

class Pet {
public:
    std::string name, breed;
    int age;
    std::string medicalHistory;
    bool vaccinated;

    void inputPetDetails() {
        std::cout << "Enter pet name: "; std::getline(std::cin, name);
        std::cout << "Enter breed: "; std::getline(std::cin, breed);
        std::cout << "Enter age: "; std::cin >> age; std::cin.ignore();
        std::cout << "Enter medical history: "; std::getline(std::cin, medicalHistory);
        std::cout << "Is vaccinated (1 for yes, 0 for no): "; std::cin >> vaccinated; std::cin.ignore();
    }

    void saveToFile(std::ofstream& ofs) {
        ofs << name << "," << breed << "," << age << "," << medicalHistory << "," << vaccinated << "\n";
    }
};

class Owner {
public:
    std::string name, address, phone, email;
    std::vector<std::shared_ptr<Pet>> pets;

    void inputOwnerDetails() {
        std::cout << "Enter owner name: "; std::getline(std::cin, name);
        std::cout << "Enter address: "; std::getline(std::cin, address);
        std::cout << "Enter phone: "; std::getline(std::cin, phone);
        std::cout << "Enter email: "; std::getline(std::cin, email);
    }

    void addPet(std::shared_ptr<Pet> pet) {
        pets.push_back(pet);
    }

    void saveToFile(std::ofstream& ofs) {
        ofs << name << "," << address << "," << phone << "," << email << "\n";
    }
};

class Appointment {
public:
    std::string date, time, status;
    std::shared_ptr<Pet> pet;
    std::shared_ptr<Owner> owner;

    void inputAppointmentDetails() {
        std::cout << "Enter appointment date (YYYY-MM-DD): "; std::getline(std::cin, date);
        std::cout << "Enter appointment time (HH:MM): "; std::getline(std::cin, time);
        status = "Scheduled";
    }

    void saveToFile(std::ofstream& ofs) {
        ofs << date << "," << time << "," << pet->name << "," << owner->name << "," << status << "\n";
    }
};

int main() {
    std::vector<std::shared_ptr<Pet>> pets;
    std::vector<std::shared_ptr<Owner>> owners;
    std::vector<std::shared_ptr<Appointment>> appointments;

    auto pet = std::make_shared<Pet>();
    pet->inputPetDetails();

    auto owner = std::make_shared<Owner>();
    owner->inputOwnerDetails();
    owner->addPet(pet);

    auto appointment = std::make_shared<Appointment>();
    appointment->pet = pet;
    appointment->owner = owner;
    appointment->inputAppointmentDetails();

    pets.push_back(pet);
    owners.push_back(owner);
    appointments.push_back(appointment);

    std::ofstream petFile("pets.txt");
    for (auto& p : pets)
        p->saveToFile(petFile);
    petFile.close();

    std::ofstream ownerFile("owners.txt");
    for (auto& o : owners)
        o->saveToFile(ownerFile);
    ownerFile.close();

    std::ofstream appointmentFile("appointments.txt");
    for (auto& a : appointments)
        a->saveToFile(appointmentFile);
    appointmentFile.close();

    return 0;
}
