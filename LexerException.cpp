#include "LexerException.h"
#include "MyException.h"

LexerException::LexerException(const char* message)
        : m_msg(message)
{
}

LexerException::LexerException(const std::string& message)
        : m_msg(message)
{
}

LexerException::~LexerException() throw (){};

const char* LexerException::what() const throw()
{
    return m_msg.c_str();
}


// just for Canonical form
LexerException::LexerException()
{
}

const LexerException& LexerException::operator=(const LexerException &exception)
{
    if (this != &exception)
    {
        this->m_msg = exception.m_msg;
    }

    return *this;
}
LexerException::LexerException(const LexerException &exception)
{
    *this = exception;
}

