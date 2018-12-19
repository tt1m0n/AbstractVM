#include "MyException.h"

static const std::string g_kLine = "Line:";
static const std::string g_kError = "Error:";
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

std::string MyException::makeErrorString(int line, const std::string &argument)
{
    std::string error = g_kLine + g_kSpaceSeparator + std::to_string(line) +
            g_kComaSeparator + g_kSpaceSeparator + g_kError + g_kSpaceSeparator;

    error += argument;
    return error;
}

// just for Canonical form
MyException::MyException()
{
}

const MyException& MyException::operator=(const MyException &exception)
{
    if (this != &exception)
    {
        this->m_msg = exception.m_msg;
    }

    return *this;
}
MyException::MyException(const MyException &exception)
{
    *this = exception;
}
