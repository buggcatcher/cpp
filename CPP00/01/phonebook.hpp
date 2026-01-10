#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    
    void setFirstName(const std::string& name) { firstName = name; }
    void setLastName(const std::string& name) { lastName = name; }
    void setNickname(const std::string& nick) { nickname = nick; }
    void setPhoneNumber(const std::string& phone) { phoneNumber = phone; }
    void setDarkestSecret(const std::string& secret) { darkestSecret = secret; }
    
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickname() const { return nickname; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getDarkestSecret() const { return darkestSecret; }
    
    bool isEmpty() const;
};

class PhoneBook 
{
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
};

/*
usa & dopo std::string per passare tramite riferimento
usa const nei parametri per non modificare il parametro
usa const dopo il metodo per non modificare l'oggetto (this)
*/

#endif