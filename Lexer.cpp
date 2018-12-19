#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>

#include "MyException.h"
#include "LexerException.h"

static const int g_kOneArgument = 2;
static const int g_kNoArguments = 1;
static const char g_kSpaceSymbol = ' ';
static const char g_kOpenBracketSymbol = '(';
static const char g_kCloseBracketSymbol = ')';
static const char g_kStartCommentSymbol = ';';
static const std::string g_kEndInput = "exit";
static const std::string g_kEndStandartInput = ";;";
static const std::string g_kNoExitInput = "Error: no exit command from standart input";

Lexer::Lexer(int argc, char **argv)
    : m_argc(argc),
    m_argv(argv),
    m_isStandartInput(false)
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

bool Lexer::isStandartInput() const
{
    return m_isStandartInput;
}

void Lexer::read()
{
    if (m_argc > g_kOneArgument)
    {
        throw LexerException("Usage: ./asm | ./asm filename");
    }

    if (m_argc == g_kOneArgument)
    {
        m_isStandartInput = true;

        struct stat	st;
        lstat(m_argv[1], &st);

        if (S_ISDIR(st.st_mode))
        {
            throw LexerException("error: it is a directory");
        }

        std::ifstream file(m_argv[1]);
        std::string line;

        if (!file.is_open())
        {
            throw LexerException("error: can not open file");
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
            if (line == g_kEndStandartInput)
            {
                break;
            }
        }
    }
}

void Lexer::tokenize()
{
    for (const std::string &line : m_lines)
    {
        splitLine(line);
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

//Just for canonical form
Lexer::Lexer()
    : m_argc(0),
    m_argv(nullptr),
    m_isStandartInput(false)
{
};

const Lexer& Lexer::operator=(const Lexer& lexer)
{
    this->m_argc = lexer.m_argc;
    this->m_argv = lexer.m_argv;
    this->m_isStandartInput = lexer.m_isStandartInput;
    this->m_lines = lexer.m_lines;
    this->m_tokenLines = lexer.m_tokenLines;

    return *this;
}

Lexer::Lexer(const Lexer &lexer)
{
    *this = lexer;
}
