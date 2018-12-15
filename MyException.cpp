#include "MyException.h"

MyException::MyException(const char* message)
    : m_msg(message)
{
}

MyException::MyException(const std::string& message)
    : m_msg(message)
{
}

const char* MyException::what() const throw()
{
    return m_msg.c_str();
}

std::string makeErrorString()
{
    return std::string();
}

// just for Canonical form
MyException::MyException() {};
MyException::MyException(const MyException&) {};
MyException::~MyException() throw (){};

