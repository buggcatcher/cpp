#include <iostream> 
#include <string>

int main()
{
	std::string name;
	std::string phone;

	std::cout << "Enter name: ";
	std::getline(std::cin, name); 
}

/*
getline(): legge una riga completa di input, inclusi gli spazi, fino al carattere di nuova linea.
*/