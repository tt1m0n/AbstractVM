#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
#include <string>

class MyException : public std::exception
{
public:
    explicit MyException(const char* message);
    explicit MyException(const std::string& message);
    const char* what() const throw ();

    static std::string makeErrorString();

    // just for Canonical form
    MyException();
    MyException(const MyException&);
    const MyException& operator=(const MyException &);
    ~MyException() throw ();

private:
    std::string         m_msg;
};

#endif
