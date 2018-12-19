#include "OperandException.h"
#include "MyException.h"

OperandException::OperandException(const char* message)
        : m_msg(message)
{
}

OperandException::OperandException(const std::string& message)
        : m_msg(message)
{
}

OperandException::~OperandException() throw (){};

const char* OperandException::what() const throw()
{
    return m_msg.c_str();
}


// just for Canonical form
OperandException::OperandException()
{
}

const OperandException& OperandException::operator=(const OperandException &exception)
{
    if (this != &exception)
    {
        this->m_msg = exception.m_msg;
    }

    return *this;
}
OperandException::OperandException(const OperandException &exception)
{
    *this = exception;
}

