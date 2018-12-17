#include <iostream>
#include "Lexer.h"
#include "Parser.h"

int main(int argc, char **argv)
{
    try
    {
        Lexer lexer(argc, argv);
        lexer.run();
        Parser parser(lexer.getTokeLines());
        parser.run();
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}