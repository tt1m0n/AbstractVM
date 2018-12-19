#ifndef LEXER_H
#define LEXER_H

#include <vector>

using TokenLine = std::vector<std::string>;
using TokenLines = std::vector<TokenLine>;

class Lexer
{
public:
    Lexer(int argc, char **argv);
    ~Lexer();

    //just for canonical form
    Lexer();
    Lexer(const Lexer &lexer);
    const Lexer& operator=(const Lexer& lexer);

    void run();
    const TokenLines &getTokeLines() const;
    bool isStandartInput() const;

private:
    void read();
    void tokenize();
    void splitLine(const std::string &line);

private:
    int m_argc;
    char **m_argv;
    bool m_isStandartInput;
    std::vector<std::string> m_lines;
    TokenLines m_tokenLines;
};

#endif
