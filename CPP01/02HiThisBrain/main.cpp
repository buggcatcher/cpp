#include <iostream>
#include <string>

int main() {
    std::string variable = "HI THIS IS BRAIN";
    std::string *stringPTR = &variable;
    std::string &stringREF = variable;

    std::cout << "Indirizzo di memoria della variabile:\t\t" << &variable << std::endl;
    std::cout << "Indirizzo di memoria puntato da stringPTR:\t" << stringPTR << std::endl;
    std::cout << "Indirizzo di memoria puntato da stringREF:\t" << &stringREF << std::endl;

    std::cout << "Valore della variable:\t\t\t\t" << variable << std::endl;
    std::cout << "Valore puntato da stringPTR:\t\t\t" << *stringPTR << std::endl;
    std::cout << "Valore puntato da stringREF:\t\t\t" << stringREF << std::endl;
    return 0;
}
