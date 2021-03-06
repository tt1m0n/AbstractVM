#ifndef OPERANDFACTORY_H
#define OPERANDFACTORY_H

#include <map>

#include "IOperand.h"

class OperandFactory
{
public:
    OperandFactory();
    ~OperandFactory();

    //just for canonical form
    OperandFactory(const OperandFactory &factory);
    const OperandFactory& operator=(const OperandFactory& factory);

    void initCreateCommands();
    IOperand const *createOperand(eOperandType type, std::string const &value) const;

    void setLine(int line);

private:
    IOperand const *createInt8(std::string const & value) const;
    IOperand const *createInt16(std::string const & value) const;
    IOperand const *createInt32(std::string const & value) const;
    IOperand const *createFloat(std::string const & value) const;
    IOperand const *createDouble(std::string const & value) const;

private:
    using createProcess = IOperand const*(OperandFactory::*)(std::string const&) const;
    std::map<eOperandType, createProcess> m_createCommands;

    int m_line;
};

#endif
