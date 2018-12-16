#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <map>

using TokenLine = std::vector<std::string>;
using TokenLines = std::vector<TokenLine>;

enum eOperandType
{
    Int8 = 0,
    Int16,
    Int32,
    Float,
    Double
};

class Parser
{
public:
    Parser(const TokenLines& tokenLines);
    ~Parser();

    //just for canonical form
    Parser();
    Parser(const Parser &lexer);
    const Parser& operator=(const Parser& lexer);

    void run();
private:
    void initProcessCommands();
    void initOperandsValue();
    void parse();

    void pushCommand(int line, const TokenLine &tokenLine);
    void popCommand(int line, const TokenLine &tokenLine);
    void dumpCommand(int line, const TokenLine &tokenLine);
    void assertCommand(int line, const TokenLine &tokenLine);
    void addCommand(int line, const TokenLine &tokenLine);
    void subCommand(int line, const TokenLine &tokenLine);
    void mulCommand(int line, const TokenLine &tokenLine);
    void divCommand(int line, const TokenLine &tokenLine);
    void modCommand(int line, const TokenLine &tokenLine);
    void printCommand(int line, const TokenLine &tokenLine);
    void exitCommand(int line, const TokenLine &tokenLine);

    void checkNumberOfTokens(int line,
            const TokenLine &tokenLine,
            bool isNeedValue);
    void checkNameOfType(int line, const std::string &typeName);

private:
    TokenLines m_tokenLines;

    using ProcessCommand = void(Parser::*)(int, const TokenLine&);
    std::map<std::string, ProcessCommand> m_processCommands;

    std::map<std::string, eOperandType> m_operands;

    bool m_isErrorPresent;
    bool m_isNeedToCheck;
};

#endif
