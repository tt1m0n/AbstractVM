#ifndef LEXEREXCEPTION_H
#define LEXEREXCEPTION_H

#include <exception>
#include <string>

class LexerException : public std::exception
{
public:
    explicit LexerException(const char* message);
    explicit LexerException(const std::string& message);
    ~LexerException() throw ();

    const char* what() const throw ();

    // just for Canonical form
    LexerException();
    LexerException(const LexerException &exception);
    const LexerException& operator=(const LexerException &exception);

private:
    std::string         m_msg;
};

#endif

