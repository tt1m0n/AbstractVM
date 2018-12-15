#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <map>

class Lexer
{
public:

    //TODO canonical form
    Lexer(int argc, char **argv);
    ~Lexer();

    void run();

private:
    void read();
    void tokenize();
    void splitLine(const std::string &line);

private:
    int m_argc;
    char **m_argv;
    std::vector<std::string> m_lines;
    std::vector<std::vector<std::string>> m_tokenLines;
};

#endif
