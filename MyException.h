#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
#include <string>

enum ErrorType
{
    errorCommand = 0,
    errorTokenNumber,
    errorTypeName
};

class MyException : public std::exception
{
public:
    explicit MyException(const char* message);
    explicit MyException(const std::string& message);
    ~MyException() throw ();

    const char* what() const throw ();

    static std::string makeErrorString(ErrorType type, int line, const std::string &argument = "");

    // just for Canonical form
    MyException();
    MyException(const MyException &exception);
    const MyException& operator=(const MyException &exception);

private:
    std::string         m_msg;
};

#endif
