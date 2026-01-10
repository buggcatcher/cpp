#include "phonebook.hpp"

Contact::Contact() {
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	darkestSecret = "";
}

bool Contact::isEmpty() const {
    return firstName.empty();
}

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {}

std::string PhoneBook::truncate(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displayContactRow(int index, const Contact& contact) {
    std::cout << "|" << std::setw(10) << index + 1
              << "|" << std::setw(10) << truncate(contact.getFirstName())
              << "|" << std::setw(10) << truncate(contact.getLastName())
              << "|" << std::setw(10) << truncate(contact.getNickname())
              << "|" << std::endl;
}

bool PhoneBook::safeGetline(std::string& input) {
    return static_cast<bool>(std::getline(std::cin, input));
}

std::string PhoneBook::getInput(const std::string& prompt) {
    std::string input;
    
    while (true) {
        std::cout << prompt;
        if (!safeGetline(input)) {
            std::cout << std::endl << "quit" << std::endl;
            exit(0);
        }
        if (!input.empty())
            return input;
        std::cout << "Error: Field cannot be empty" << std::endl;
    }
}

void PhoneBook::addContact() {
    Contact newContact;
    
    newContact.setFirstName(getInput("Enter First Name: "));
    newContact.setLastName(getInput("Enter Last Name: "));
    newContact.setNickname(getInput("Enter Nickname: "));
    newContact.setPhoneNumber(getInput("Enter Phone Number: "));
    newContact.setDarkestSecret(getInput("Enter Darkest Secret: "));
    
    contacts[nextIndex] = newContact;
    if (contactCount < 8)
        contactCount++;
    nextIndex = (nextIndex + 1) % 8;
    
    std::cout << "Contact added" << std::endl;
}

void PhoneBook::searchContacts() {
    if (contactCount == 0) {
        std::cout << "Phonebook is empty" << std::endl;
        return;
    }
    
    std::cout << " ___________________________________________" << std::endl;
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "Name"
              << "|" << std::setw(10) << "Surname"
              << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;
    
    for (int i = 0; i < contactCount; i++) {
        displayContactRow(i, contacts[i]);
    }
}

int main() {
    PhoneBook phonebook;
    std::string command;
    
    while (true) {
        std::cout << "> ";
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cout << std::endl << "quit" << std::endl;
            break;
        }
        command = line;
        
        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContacts();
			// TO-DO AGGIUNGI CHE DEVE PRENDERE UN ARGOMENTO DOPO IL DISPLAY DEI CONTATTI PER
			// LA VISUALIZZAZIONE DEL CONTATTO SPECIFICATO, FAI ANCHE CONTROLLO DELL INPUT
        } else if (command == "EXIT") {
            break;
        }
    }
    
    return 0;
}