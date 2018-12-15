#include "Lexer.h"
#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        Lexer lexer(argc, argv);
        lexer.run();
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }

}