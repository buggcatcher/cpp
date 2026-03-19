#include "sed.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (sed(filename, s1, s2) == 0)
    {
        std::cout << "File processed successfully. Output written to " << filename << ".replace" << std::endl;
    }

    return 0;
}
