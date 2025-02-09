#include <iostream>
#include <filesystem>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        std::filesystem::path fileToCompile = argv[1];
        if (std::filesystem::exists(fileToCompile))
        {
        }
        else
        {
            std::cerr << "Error: File does not exist!" << std::endl;
        }
    }
    else
    {
        std::cerr << "Error: Please specify a file to compile!" << std::endl;
    }
}