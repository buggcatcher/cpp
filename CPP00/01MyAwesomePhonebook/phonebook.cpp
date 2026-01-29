#include "phonebook.hpp"
#include <sstream>

//quando un costruttore non ha parametri, si chiama costruttore di default
//costruttore di default Contact
Contact::Contact() {
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	darkestSecret = "";
}

//metodo isEmpty
bool Contact::isEmpty() const {
    return firstName.empty();
}

//metodi setters
void Contact::setFirstName(const std::string& name) {
    firstName = name;
}
void Contact::setLastName(const std::string& name) {
    lastName = name;
}
void Contact::setNickname(const std::string& nick) {
    nickname = nick;
}
void Contact::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
}
void Contact::setDarkestSecret(const std::string& secret) {
    darkestSecret = secret;
}

//metodi getters
std::string Contact::getFirstName() const {
    return firstName;
}
std::string Contact::getLastName() const {
    return lastName;
}
std::string Contact::getNickname() const {
    return nickname;
}
std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}
std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}


//costruttore default PhoneBook (member initializer list)
PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {}

//metodo truncate() della classe PhoneBook prende str e ritorna tipo std::string
std::string PhoneBook::truncate(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

//metodo
void PhoneBook::displayContactRow(int index, const Contact& contact) {
    std::cout << "|" << std::setw(10) << index + 1
              << "|" << std::setw(10) << truncate(contact.getFirstName())
              << "|" << std::setw(10) << truncate(contact.getLastName())
              << "|" << std::setw(10) << truncate(contact.getNickname())
              << "|" << std::endl;
}

//metodo
bool PhoneBook::safeGetline(std::string& input) {
    return bool(std::getline(std::cin, input));
}

//metodo
std::string PhoneBook::getInput(const std::string& prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;
        if (!safeGetline(input)) {
            std::cout << "\nquit\n";
            exit(0);
        }
        if (!input.empty())
            return input;
        std::cout << "Error: Field cannot be empty" << std::endl;
    }
}

//metodo
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

//metodo
void PhoneBook::displayContactDetails(int index) {
    if (index < 0 || index >= contactCount || contacts[index].isEmpty()) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    const Contact& c = contacts[index];
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickname() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}

//metodo
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
    // Richiesta dell'indice all'utente
    std::string input;
    std::cout << "\nEnter the index of a contact to view its details: ";
    std::getline(std::cin, input);
    if (input.empty() || input.find_first_not_of("12345678") != std::string::npos) {
        std::cout << "Invalid input." << std::endl;
        return;
    }
    std::istringstream iss(input);  // per convertire la stringa in un intero creo l'oggetto stringstream per leggere l'input come se fosse uno stream 
    int idx = -1;
    iss >> idx;
    idx -= 1;
    if (iss.fail() || idx < 0 || idx >= contactCount) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    displayContactDetails(idx);
}

int main() {
    PhoneBook phonebook;
    std::string command;
    
    while (true) {
        std::cout << "> ";
        std::string line;
        if (!phonebook.safeGetline(line)) {
            std::cout << std::endl << "quit" << std::endl;
            break;
        }
        command = line;
        
        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContacts();
        } else if (command == "EXIT" || command == "QUIT") {
            break;
        }
    }
    
    return 0;
}

/*empty()
È un metodo della classe string che verifica se la stringa è vuota.
Equivalente a (str.length() == 0) ma più leggibile.
Richiede l'header <string>.
*/

/*getline()
È una funzione che legge una riga intera da uno stream di input (come std::cin) e la memorizza in una stringa.
Sintassi tipica: std::getline(std::istream& is, std::string& str);
Legge caratteri fino a trovare un carattere di newline ('\n'), che viene scartato, e inserisce il resto nella stringa.
Permette di leggere anche stringhe con spazi (a differenza di std::cin >>), quindi è utile per input multi-parola.
Può essere usata anche con file (std::ifstream).
Restituisce lo stream, che può essere valutato in un contesto booleano per verificare se la lettura è andata a buon fine (ad esempio, EOF o errore).
Non include il carattere di newline nella stringa risultante.
Se la stringa contiene già dati, questi vengono sovrascritti.
Può essere usata con un delimitatore personalizzato (es: std::getline(is, str, ';')).
Richiede l'header <string> e <iostream>.
*/

/*setw()
È un manipolatore di stream che imposta la larghezza minima del prossimo campo di output su uno stream (come std::cout).
Usato per formattare l’output, ad esempio per allineare colonne in una tabella.
Funziona solo per la prossima operazione di output sullo stream, poi la larghezza torna al valore precedente.
Se il dato da stampare è più corto della larghezza specificata, viene aggiunto padding a sinistra (default: spazi).
Se il dato è più lungo, viene stampato tutto il dato (non viene troncato).
Può essere combinato con altri manipolatori come std::setfill per cambiare il carattere di riempimento.
Richiede l’header <iomanip>.
*/

/*string#
è una classe che gestisce automaticamente la memoria, la lunghezza, e le operazioni sulle stringhe di caratteri.
Offre metodi per concatenazione, ricerca, sostituzione, confronto, sottostringhe, conversione, ecc.
Può crescere o ridursi dinamicamente senza rischi di buffer overflow.
Puoi usare l’operatore + per concatenare, [] per accedere ai caratteri, e molti altri metodi (append, find, substr, ecc.).
std::string si integra perfettamente con gli stream (std::cin, std::cout).
Richiede l'header <string>.
*/

/*exit()
Chiama i distruttori degli oggetti statici/globali (non quelli locali).
Richiede l'header <cstdlib>.
*/