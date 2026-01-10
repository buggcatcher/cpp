#include <iostream> // per std::cout e std::endl, include internamente <ctype.h> per toupper()
#include <string> // per std::string

int main (int argc, char **argv)
{
	std::string input;
	int i;

	for (i = 1; i < argc; i++)
	{
		input = input + argv[i];
		if (i < argc -1)
			input = input + " ";
	}

	for (i = 0; i < (int)input.length(); i++)
		input[i] = toupper(input[i]); 
		
	std::cout << input << std::endl;

	return 0;
}

/* 
length():  restituisce il numero (size_t) di caratteri nella stringa. 
toupper(): se il carattere è già maiuscolo o non è una lettera, lo restituisce invariato.
*/