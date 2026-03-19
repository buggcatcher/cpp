#include "sed.hpp"

int sed(const std::string &filename, const std::string &s1, const std::string &s2)
{ 
    if (s1.empty())
    {
        std::cout << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cout << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::ofstream outputFile(filename + ".replace");
    if (!outputFile.is_open())
    {
        std::cout << "Error: Could not create output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string replaced;
        size_t start = 0;
        size_t pos = line.find(s1, start);
        while (pos != std::string::npos)
        {
            replaced += line.substr(start, pos - start);
            replaced += s2;
            start = pos + s1.length();
            pos = line.find(s1, start);
        }
        replaced += line.substr(start);
        outputFile << replaced;
        if (!inputFile.eof())
        {
            outputFile << '\n';
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}