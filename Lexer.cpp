#include "Lexer.h"
#include "MyException.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>

#define ONE_ARGUMENT 2
#define NO_ARGUMENTS 1
#define SPACE_SYMBOL ' '
#define OPEN_BRACKET '('
#define CLOSE_BRACKET ')'
#define START_COMMENT ';'

Lexer::Lexer(int argc, char **argv) : m_argc(argc), m_argv(argv)
{
}

Lexer::~Lexer() {};

void Lexer::run()
{
    read();
    tokenize();
}

void Lexer::read()
{
    if (m_argc > ONE_ARGUMENT)
    {
        throw MyException("Usage: ./asm | ./asm filename");
    }

    if (m_argc == ONE_ARGUMENT)
    {
        struct stat	st;
        lstat(m_argv[1], &st);

        if (S_ISDIR(st.st_mode))
        {
            throw MyException("error: it is a directory");
        }

        std::ifstream file(m_argv[1]);
        std::string line;

        if (!file.is_open())
        {
            throw MyException("error: can not open file");
        }

        while(std::getline(file, line))
        {
            m_lines.push_back(line);
        }
    }

    if (m_argc == NO_ARGUMENTS)
    {
        std::string line;
        while (std::getline(std::cin, line))
        {
            m_lines.push_back(line);
        }
    }
}

void Lexer::tokenize()
{
    for (const std::string &line : m_lines)
    {
        splitLine(line);
    }

    for (auto vec : m_tokenLines)
    {
        for (auto str : vec)
        {
            std::cout << str << " | ";
        }
        std::cout << std::endl;
    }
}

void Lexer::splitLine(const std::string &line)
{
    std::vector<std::string> tokenLine;
    std::string token;

    for (const char& symbol : line)
    {
        if (symbol == SPACE_SYMBOL && token.empty())
        {
            continue;
        }

        if (symbol == SPACE_SYMBOL)
        {
            tokenLine.emplace_back(token);
            token.clear();
            continue;
        }

        if (symbol == OPEN_BRACKET ||
            symbol == CLOSE_BRACKET ||
            symbol == START_COMMENT)
        {
            if (!token.empty())
            {
                tokenLine.emplace_back(token);
                token.clear();
            }

            if (symbol == START_COMMENT)
            {
                token += symbol;
            }
            else
            {
                tokenLine.emplace_back(std::string(sizeof(char), symbol));
            }

            continue;
        }

        token += symbol;
    }

    if (!token.empty())
    {
        tokenLine.emplace_back(token);
    }

    m_tokenLines.emplace_back(tokenLine);
}