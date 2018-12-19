#include "ParserException.h"
#include "MyException.h"

ParserException::ParserException(const char* message)
        : m_msg(message)
{
}

ParserException::ParserException(const std::string& message)
        : m_msg(message)
{
}

ParserException::~ParserException() throw (){};

const char* ParserException::what() const throw()
{
    return m_msg.c_str();
}


// just for Canonical form
ParserException::ParserException()
{
}

const ParserException& ParserException::operator=(const ParserException &exception)
{
    if (this != &exception)
    {
        this->m_msg = exception.m_msg;
    }

    return *this;
}
ParserException::ParserException(const ParserException &exception)
{
    *this = exception;
}

