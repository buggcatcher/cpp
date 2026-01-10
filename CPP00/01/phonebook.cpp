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

std::string PhoneBook::getInput(const std::string& prompt) {
    std::string input;
    
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
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
        std::getline(std::cin, command);
        
        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContacts();
        } else if (command == "EXIT") {
            break;
        }
    }
    
    return 0;
}