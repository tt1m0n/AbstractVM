#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <map>
#include <list>

#include "IOperand.h"
#include "OperandFactory.h"

using TokenLine = std::vector<std::string>;
using TokenLines = std::vector<TokenLine>;

class Parser
{
public:
    Parser(const TokenLines& tokenLines, bool isStandartInput);
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

    // bonus commands
    void swapCommand(int line, const TokenLine &tokenLine);
    void reverseCommand(int line, const TokenLine &tokenLine);
    void clearCommand(int line, const TokenLine &tokenLine);
    void moreCommand(int line, const TokenLine &tokenLine);
    void lessCommand(int line, const TokenLine &tokenLine);

    void checkNumberOfTokens(int line,
            const TokenLine &tokenLine,
            bool isNeedValue);
    void checkNameOfType(int line, const std::string &typeName);

private:
    TokenLines m_tokenLines;

    using ProcessCommand = void(Parser::*)(int, const TokenLine&);
    std::map<std::string, ProcessCommand> m_processCommands;

    std::map<std::string, eOperandType> m_operands;
    OperandFactory m_factory;

    // use list because need to iterate through on dum command
    std::list<std::unique_ptr<const IOperand>> m_stack;

    bool m_isErrorPresent;
    bool m_isNeedToCheck;
    bool m_isStandartInput;
};

#endif
