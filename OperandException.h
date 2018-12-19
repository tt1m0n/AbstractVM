#ifndef OPERANDEXCEPTION_H
#define OPERANDEXCEPTION_H

#include <exception>
#include <string>

class OperandException : public std::exception
{
public:
    explicit OperandException(const char* message);
    explicit OperandException(const std::string& message);
    ~OperandException() throw ();

    const char* what() const throw ();

    // just for Canonical form
    OperandException();
    OperandException(const OperandException &exception);
    const OperandException& operator=(const OperandException &exception);

private:
    std::string         m_msg;
};

#endif


