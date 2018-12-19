#ifndef PARSEREXCEPTION_H
#define PARSEREXCEPTION_H

#include <exception>
#include <string>

class ParserException : public std::exception
{
public:
    explicit ParserException(const char* message);
    explicit ParserException(const std::string& message);
    ~ParserException() throw ();

    const char* what() const throw ();

    // just for Canonical form
    ParserException();
    ParserException(const ParserException &exception);
    const ParserException& operator=(const ParserException &exception);

private:
    std::string         m_msg;
};

#endif


