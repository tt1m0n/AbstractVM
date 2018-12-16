#include "Lexer.h"
#include "MyException.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>

static const int g_kOneArgument = 2;
static const int g_kNoArguments = 1;
static const char g_kSpaceSymbol = ' ';
static const char g_kOpenBracketSymbol = '(';
static const char g_kCloseBracketSymbol = ')';
static const char g_kStartCommentSymbol = ';';

Lexer::Lexer(int argc, char **argv) : m_argc(argc), m_argv(argv)
{
}

Lexer::~Lexer() {};

void Lexer::run()
{
    read();
    tokenize();
}

const TokenLines &Lexer::getTokeLines() const
{
    return m_tokenLines;
}

void Lexer::read()
{
    if (m_argc > g_kOneArgument)
    {
        throw MyException("Usage: ./asm | ./asm filename");
    }

    if (m_argc == g_kOneArgument)
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

    if (m_argc == g_kNoArguments)
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

    for (int i = 0; i < line.length(); ++i)
    {
        if (line[i] == g_kSpaceSymbol && token.empty())
        {
            continue;
        }

        if (line[i] == g_kSpaceSymbol)
        {
            tokenLine.emplace_back(token);
            token.clear();
            continue;
        }

        if (line[i] == g_kOpenBracketSymbol ||
            line[i] == g_kCloseBracketSymbol ||
            line[i] == g_kStartCommentSymbol)
        {
            if (!token.empty())
            {
                tokenLine.emplace_back(token);
                token.clear();
            }

            if (line[i] == g_kStartCommentSymbol)
            {
                token = line.substr(i, line.length() - i);
                break;
            }
            else
            {
                tokenLine.emplace_back(std::string(sizeof(char), line[i]));
            }

            continue;
        }

        token += line[i];
    }

    if (!token.empty())
    {
        tokenLine.emplace_back(token);
    }

    m_tokenLines.emplace_back(tokenLine);
}