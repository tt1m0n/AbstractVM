#include <iostream>
#include <functional>
#include "Parser.h"
#include "MyException.h"

static const int g_kTokenSizeSimpleCommand = 1;
static const int g_kTokenSizeValueCommand = 5;
static const int g_kTypeNamePosition = 1;

static bool isComment(std::string command)
{
    if (command.empty())
    {
        return false;
    }

    return command[0] == ';';
}

Parser::Parser(const TokenLines& tokenLines)
    : m_tokenLines(tokenLines),
    m_isErrorPresent(false),
    m_isNeedToCheck(true)
{
    initProcessCommands();
    initOperandsValue();
};

Parser::~Parser() {};

void Parser::run()
{
    parse();
    if (!m_isErrorPresent)
    {
        m_isNeedToCheck = true;
        parse();
    }
}

void Parser::parse()
{
    for (int i = 0; i < m_tokenLines.size(); ++i)
    {
        try
        {
            std::string command = m_tokenLines[i].empty() ? "" : m_tokenLines[i].front();
            int line = i + 1;
            auto handleCommand = m_processCommands.find(command);

            if (isComment(command))
            {
                continue;
            }

            if (handleCommand != m_processCommands.end())
            {
                (this->*m_processCommands.at(command))(line, m_tokenLines[i]);
            }
            else if (!command.empty())
            {
                std::string error = MyException::makeErrorString(ErrorType::errorCommand,
                        line,
                        command);

                throw MyException(error);
            }
        }
        catch (std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }
}

void Parser::initProcessCommands()
{
    m_processCommands["push"] = &Parser::pushCommand;
    m_processCommands["pop"] = &Parser::popCommand;
    m_processCommands["dump"] = &Parser::dumpCommand;
    m_processCommands["assert"] = &Parser::assertCommand;
    m_processCommands["add"] = &Parser::addCommand;
    m_processCommands["sub"] = &Parser::subCommand;
    m_processCommands["mul"] = &Parser::mulCommand;
    m_processCommands["div"] = &Parser::divCommand;
    m_processCommands["mod"] = &Parser::modCommand;
    m_processCommands["print"] = &Parser::printCommand;
    m_processCommands["exit"] = &Parser::exitCommand;
}

void Parser::initOperandsValue()
{
    m_operands["int8"] = eOperandType::Int8;
    m_operands["int16"] = eOperandType::Int16;
    m_operands["int32"] = eOperandType::Int32;
    m_operands["float"] = eOperandType::Float;
    m_operands["double"] = eOperandType::Double;
}

// ------------------ process commands ------------------------ //

void Parser::pushCommand(int line, const TokenLine &tokenLine)
{
    if (m_isNeedToCheck)
    {
        checkNumberOfTokens(line, tokenLine, true);
        checkNameOfType(line, tokenLine[g_kTypeNamePosition]);
    }
    else
    {

    }
}

void Parser::popCommand(int line, const TokenLine &tokenLine)
{
    if (m_isNeedToCheck)
    {
        checkNumberOfTokens(line, tokenLine, false);
    }
    else
    {

    }
}

void Parser::dumpCommand(int line, const TokenLine &tokenLine)
{
    if (m_isNeedToCheck)
    {
        checkNumberOfTokens(line, tokenLine, false);
    }
    else
    {

    }
}

void Parser::assertCommand(int line, const TokenLine &tokenLine)
{
    if (m_isNeedToCheck)
    {
        checkNumberOfTokens(line, tokenLine, true);
        checkNameOfType(line, tokenLine[g_kTypeNamePosition]);
    }
    else
    {

    }
}

void Parser::addCommand(int line, const TokenLine &tokenLine)
{
    if (m_isNeedToCheck)
    {
        checkNumberOfTokens(line, tokenLine, false);
    }
    else
    {

    }
}

void Parser::subCommand(int line, const TokenLine &tokenLine)
{
    if (m_isNeedToCheck)
    {
        checkNumberOfTokens(line, tokenLine, false);
    }
    else
    {

    }
}

void Parser::mulCommand(int line, const TokenLine &tokenLine)
{
    if (m_isNeedToCheck)
    {
        checkNumberOfTokens(line, tokenLine, false);
    }
    else
    {

    }
}

void Parser::divCommand(int line, const TokenLine &tokenLine)
{
    if (m_isNeedToCheck)
    {
        checkNumberOfTokens(line, tokenLine, false);
    }
    else
    {

    }
}

void Parser::modCommand(int line, const TokenLine &tokenLine)
{
    if (m_isNeedToCheck)
    {
        checkNumberOfTokens(line, tokenLine, false);
    }
    else
    {

    }
}

void Parser::printCommand(int line, const TokenLine &tokenLine)
{
    if (m_isNeedToCheck)
    {
        checkNumberOfTokens(line, tokenLine, false);
    }
    else
    {

    }
}

void Parser::exitCommand(int line, const TokenLine &tokenLine)
{
    if (m_isNeedToCheck)
    {
        checkNumberOfTokens(line, tokenLine, false);
    }
    else
    {

    }
}

// ------------------------------------------------------------- //


void Parser::checkNumberOfTokens(int line,
                             const TokenLine &tokenLine,
                             bool isNeedValue)
{
    int expectTokens = isNeedValue ? g_kTokenSizeValueCommand : g_kTokenSizeSimpleCommand;

    if (tokenLine.size() == expectTokens)
    {
        return;
    }

    if (tokenLine.size() > expectTokens && isComment(tokenLine[expectTokens]))
    {
        return;
    }

    m_isErrorPresent = true;

    std::string error = MyException::makeErrorString(ErrorType::errorTokenNumber, line);
    throw MyException(error);

}

void Parser::checkNameOfType(int line, const std::string &typeName)
{
    if (m_operands.find(typeName) != m_operands.end())
    {
        return;
    }

    m_isErrorPresent = true;

    std::string error = MyException::makeErrorString(ErrorType::errorTypeName,
            line,
            typeName);
    throw MyException(error);
}

