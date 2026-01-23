#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    Contact();
    void setFirstName(const std::string& name);
    void setLastName(const std::string& name);
    void setNickname(const std::string& nick);
    void setPhoneNumber(const std::string& phone);
    void setDarkestSecret(const std::string& secret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    bool isEmpty() const;
};

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;
    int nextIndex;
    std::string truncate(const std::string& str);
    void displayContactRow(int index, const Contact& contact);
    std::string getInput(const std::string& prompt);
public:
    PhoneBook();
    void addContact();
    void searchContacts();
    bool safeGetline(std::string& input);
    std::string promptField(const std::string& prompt);
};

/*
usa const nei parametri per non modificare il parametro
usa const dopo il metodo per non modificare l'oggetto (this)
*/

#endif