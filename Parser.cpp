#include <iostream>
#include <functional>
#include "Parser.h"
#include "MyException.h"

static const size_t g_kTokenSizeSimpleCommand = 1;
static const size_t g_kTokenSizeValueCommand = 5;
static const int g_kTypeNamePosition = 1;
static const int g_kValuePosition = 3;

static const std::string g_kComaSeparator = ",";
static const std::string g_kSpaceSeparator = " ";
static const std::string g_kDefisSeparator = "-";
static const std::string g_kWrongCommand = "wrong command";
static const std::string g_kWrongNumberOfTokes = "wrong number of tokens";
static const std::string g_kWrongTypeName = "wrong type name";
static const std::string g_kWrongPopCommand = "use pop-command for empty stack";
static const std::string g_kWrongAssertEmpty = "use assert-command for empty stack";
static const std::string g_kWrongAssertType = "use assert-command with different type";
static const std::string g_kWrongAssertValue = "use assert-command with different value";
static const std::string g_kWrongAdd = "use add-command with less then two values";
static const std::string g_kWrongSub = "use sub-command with less then two values";
static const std::string g_kWrongDiv = "use div-command with less then two values";
static const std::string g_kWrongMod = "use mod-command with less then two values";
static const std::string g_kWrongMul = "use mul-command with less then two values";
static const std::string g_kEmptyPrint = "use print-command with empty stack";
static const std::string g_kWrongPrint = "use print-command with error type";


static bool isComment(std::string command)
{
    if (command.empty())
    {
        return false;
    }

    return command[0] == ';';
}

Parser::Parser(const TokenLines& tokenLines, bool isStandartInput)
    : m_tokenLines(tokenLines),
    m_isErrorPresent(false),
    m_isNeedToCheck(true),
    m_isStandartInput(isStandartInput)
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
        m_isNeedToCheck = false;
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
                if (command == "exit")
                {
                    return;
                }

                (this->*m_processCommands.at(command))(line, m_tokenLines[i]);
            }
            else if (!command.empty())
            {
                m_isErrorPresent = true;

                std::string errorArgument = g_kWrongCommand + g_kSpaceSeparator + g_kDefisSeparator +
                        g_kSpaceSeparator + command;
                std::string error = MyException::makeErrorString(line, errorArgument);

                throw MyException(error);
            }
        }
        catch (std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }

    throw MyException("No exit command");
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
        eOperandType type = m_operands.at(tokenLine[g_kTypeNamePosition]);
        std::string value = tokenLine[g_kValuePosition];

        m_factory.setLine(line);

        std::unique_ptr<const IOperand> newOperand(m_factory.createOperand(type, value));
        m_stack.push_front(std::move(newOperand));
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
        if (m_stack.empty())
        {
            std::string error = MyException::makeErrorString(line, g_kWrongPopCommand);
            throw MyException(error);
        }

        m_stack.pop_front();
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
        for(const auto& value : m_stack)
        {
            std::cout << value->toString() << std::endl;
        }
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
        if (m_stack.empty())
        {
            std::string error = MyException::makeErrorString(line, g_kWrongAssertEmpty);
            throw MyException(error);
        }

        eOperandType assertType = m_operands.at(tokenLine[g_kTypeNamePosition]);
        if (assertType != m_stack.front()->getType())
        {
            std::string error = MyException::makeErrorString(line, g_kWrongAssertType);
            throw MyException(error);
        }

        if (tokenLine[g_kValuePosition] != m_stack.front()->toString())
        {
            std::string error = MyException::makeErrorString(line, g_kWrongAssertValue);
            throw MyException(error);
        }
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
        if (m_stack.size() < 2)
        {
            std::string error = MyException::makeErrorString(line, g_kWrongAdd);
            throw MyException(error);
        }

        // extract first value
        std::unique_ptr<const IOperand> firstValue(m_stack.front().release());
        m_stack.pop_front();

        // extract second value
        std::unique_ptr<const IOperand> secondValue(m_stack.front().release());
        m_stack.pop_front();

        // need for error output
        m_factory.setLine(line);

        std::unique_ptr<const IOperand> result(*secondValue + *firstValue);

        m_stack.push_front(std::move(result));
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
        if (m_stack.size() < 2)
        {
            std::string error = MyException::makeErrorString(line, g_kWrongSub);
            throw MyException(error);
        }

        // extract first value
        std::unique_ptr<const IOperand> firstValue(m_stack.front().release());
        m_stack.pop_front();

        // extract second value
        std::unique_ptr<const IOperand> secondValue(m_stack.front().release());
        m_stack.pop_front();

        // need for error output
        m_factory.setLine(line);

        std::unique_ptr<const IOperand> result(*secondValue - *firstValue);

        m_stack.push_front(std::move(result));
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
        if (m_stack.size() < 2)
        {
            std::string error = MyException::makeErrorString(line, g_kWrongMul);
            throw MyException(error);
        }

        // extract first value
        std::unique_ptr<const IOperand> firstValue(m_stack.front().release());
        m_stack.pop_front();

        // extract second value
        std::unique_ptr<const IOperand> secondValue(m_stack.front().release());
        m_stack.pop_front();

        // need for error output
        m_factory.setLine(line);

        std::unique_ptr<const IOperand> result(*secondValue * *firstValue);

        m_stack.push_front(std::move(result));
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
        if (m_stack.size() < 2)
        {
            std::string error = MyException::makeErrorString(line, g_kWrongDiv);
            throw MyException(error);
        }

        // extract first value
        std::unique_ptr<const IOperand> firstValue(m_stack.front().release());
        m_stack.pop_front();

        // extract second value
        std::unique_ptr<const IOperand> secondValue(m_stack.front().release());
        m_stack.pop_front();

        // need for error output
        m_factory.setLine(line);

        std::unique_ptr<const IOperand> result(*secondValue / *firstValue);
        m_stack.push_front(std::move(result));
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
        if (m_stack.size() < 2)
        {
            std::string error = MyException::makeErrorString(line, g_kWrongMod);
            throw MyException(error);
        }

        // extract first value
        std::unique_ptr<const IOperand> firstValue(m_stack.front().release());
        m_stack.pop_front();

        // extract second value
        std::unique_ptr<const IOperand> secondValue(m_stack.front().release());
        m_stack.pop_front();

        // need for error output
        m_factory.setLine(line);

        std::unique_ptr<const IOperand> result(*secondValue % *firstValue);

        m_stack.push_front(std::move(result));
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
        if (m_stack.empty())
        {
            std::string error = MyException::makeErrorString(line, g_kEmptyPrint);
            throw MyException(error);
        }

        if (m_stack.front()->getType() != eOperandType::Int8)
        {
            std::string error = MyException::makeErrorString(line, g_kWrongPrint);
            throw MyException(error);
        }

        std::cout << static_cast<char>(std::stoi(m_stack.front()->toString())) << std::endl;
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
    size_t expectTokens = isNeedValue ? g_kTokenSizeValueCommand : g_kTokenSizeSimpleCommand;

    if (tokenLine.size() == expectTokens)
    {
        return;
    }

    if (tokenLine.size() > expectTokens && isComment(tokenLine[expectTokens]))
    {
        return;
    }

    m_isErrorPresent = true;

    std::string error = MyException::makeErrorString(line, g_kWrongNumberOfTokes);
    throw MyException(error);

}

void Parser::checkNameOfType(int line, const std::string &typeName)
{
    if (m_operands.find(typeName) != m_operands.end())
    {
        return;
    }

    m_isErrorPresent = true;

    std::string errorArgument = g_kWrongTypeName + g_kSpaceSeparator + g_kDefisSeparator +
            g_kSpaceSeparator + typeName;
    std::string error = MyException::makeErrorString(line, errorArgument);

    throw MyException(error);
}

