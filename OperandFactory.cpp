#include "OperandFactory.h"
#include "Operand.h"

OperandFactory::OperandFactory()
    : m_line(0)
{
    initCreateCommands();
}

OperandFactory::~OperandFactory() {}

void OperandFactory::initCreateCommands()
{
    m_createCommands[Int8] = &OperandFactory::createInt8;
    m_createCommands[Int16] = &OperandFactory::createInt16;
    m_createCommands[Int32] = &OperandFactory::createInt32;
    m_createCommands[Float] = &OperandFactory::createFloat;
    m_createCommands[Double] = &OperandFactory::createDouble;
}

IOperand const *OperandFactory::createOperand(eOperandType type,
        std::string const &value) const
{
    return (this->*m_createCommands.at(type))(value);
}

void OperandFactory::setLine(int line)
{
    m_line = line;
}

IOperand const* OperandFactory::createInt8(std::string const &value) const
{
    return (new Operand<char>(value, Int8, 0, *this, m_line));
}

IOperand const* OperandFactory::createInt16(std::string const &value) const
{
    return (new Operand<short int>(value, Int16, 0, *this, m_line));
}

IOperand const* OperandFactory::createInt32(std::string const &value) const
{
    return (new Operand<int>(value, Int32, 0, *this, m_line));
}

IOperand const* OperandFactory::createFloat(std::string const &value) const
{
    return (new Operand<float>(value, Float, 7, *this, m_line));
}

IOperand const* OperandFactory::createDouble( std::string const & value ) const
{
    return (new Operand<double>(value, Double, 14, *this, m_line));
}

//just for canonical form
const OperandFactory& OperandFactory::operator=(const OperandFactory& factory)
{
    if (this != &factory)
    {
        this->m_line = factory.m_line;
    }
}

OperandFactory::OperandFactory(const OperandFactory &factory)
{
    *this = factory;
}
