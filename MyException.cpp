#include "MyException.h"

static const std::string g_kLine = "Line:";
static const std::string g_kError = "Error:";
static const std::string g_kWrongCommand = "wrong command";
static const std::string g_kWrongNumberOfTokes = "wrong number of tokens";
static const std::string g_kWrongTypeName = "wrong type name";
static const std::string g_kComaSeparator = ",";
static const std::string g_kSpaceSeparator = " ";
static const std::string g_kDefisSeparator = "-";

MyException::MyException(const char* message)
    : m_msg(message)
{
}

MyException::MyException(const std::string& message)
    : m_msg(message)
{
}

MyException::~MyException() throw (){};

const char* MyException::what() const throw()
{
    return m_msg.c_str();
}

std::string MyException::makeErrorString(ErrorType type, int line, const std::string &argument)
{
    std::string error = g_kLine + g_kSpaceSeparator + std::to_string(line) +
            g_kComaSeparator + g_kSpaceSeparator + g_kError + g_kSpaceSeparator;

    switch(type)
    {
        case ErrorType::errorCommand :
        {
            error += g_kWrongCommand + g_kSpaceSeparator + g_kDefisSeparator +
                    g_kSpaceSeparator + argument;

            return error;
        }
        case ErrorType::errorTokenNumber :
        {
            error += g_kWrongNumberOfTokes;

            return error;
        }
        case ErrorType::errorTypeName :
        {
            error += g_kWrongTypeName + g_kSpaceSeparator + g_kDefisSeparator +
                     g_kSpaceSeparator + argument;
        }
    }
}

