#ifndef OPERAND_H
#define OPERAND_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <float.h>
#include <limits.h>
#include <math.h>

#include "MyException.h"
#include "OperandException.h"
#include "IOperand.h"
#include "OperandFactory.h"

static const std::string g_kErrorLimit = "Overflow or underflow value for this type";
static const std::string g_kDivisionByZero = "Division by zero";
static const std::string g_kModuloByZero = "Modulo by zero";

template <typename T>
class Operand : public IOperand
{
public:
    Operand(const std::string &value,
            eOperandType type,
            int precision,
            const OperandFactory &factory,
            int line)
            : m_type(type),
            m_precision(precision),
            m_factory(factory),
            m_line(line)
    {
        try
        {
            if (type < eOperandType::Float)
            {
                long long workValue = std::stoll(value);
                if (isErrorLimits<long long>(workValue, type))
                {
                    std::string error = MyException::makeErrorString(m_line, g_kErrorLimit);
                    throw OperandException(error);
                }
                m_value = static_cast<T>(workValue);
                std::stringstream ss(std::stringstream::out);
                ss << std::setprecision(precision) << workValue;
                m_str = ss.str();
            }
            else
            {
                long double	workValue = std::stold(value);
                if (isErrorLimits<long double>(workValue, type))
                {
                    std::string error = MyException::makeErrorString(m_line, g_kErrorLimit);
                    throw OperandException(error);
                }
                m_value = static_cast<T>(workValue);
                std::stringstream ss(std::stringstream::out);
                ss << std::setprecision(precision) << workValue;
                m_str = ss.str();
            }
        }
        catch(const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    ~Operand() override {}

    int getPrecision() const override
    {
        return m_precision;
    }

    eOperandType getType() const override
    {
        return m_type;
    }

    template <typename U>
    bool isErrorLimits(U r, eOperandType type) const
    {
        switch (type)
        {
            case Int8 :
            {
                return (r > SCHAR_MAX || r < SCHAR_MIN);
            }
            case Int16 :
            {
                return (r > SHRT_MAX || r < SHRT_MIN);
            }
            case Int32 :
            {
                return (r > INT_MAX || r < INT_MIN);
            }
            case Float :
            {
                return (r > FLT_MAX || r < -FLT_MAX);
            }
            case Double :
            {
                return (r > DBL_MAX || r < -DBL_MAX);
            }
            default :
            {
                return true;
            }
        }
    }

    const std::string &toString() const override
    {
        return m_str;
    }

    // Overload operations
    const IOperand * operator+(const IOperand &rhs) const override
    {
        int precision = (m_precision >= rhs.getPrecision()) ? m_precision : rhs.getPrecision();
        eOperandType type = (m_type >= rhs.getType()) ? m_type : rhs.getType();

        try
        {
            std::stringstream stream(std::stringstream::out);
            if (type < eOperandType::Float)
            {
                long long result = std::stoll(m_str) + std::stoll(rhs.toString());
                if (isErrorLimits<long long>(result, type))
                {
                    std::string error = MyException::makeErrorString(m_line, g_kErrorLimit);
                    throw OperandException(error);
                }

                stream << result;
            }
            else
            {
                long double result = std::stold(m_str) + std::stold(rhs.toString());
                if (isErrorLimits<long double>(result, type))
                {
                    std::string error = MyException::makeErrorString(m_line, g_kErrorLimit);
                    throw OperandException(error);
                }

                stream << std::setprecision(precision) << result;
            }

            return (m_factory.createOperand(type, stream.str()));
        }
        catch(const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
            exit(EXIT_FAILURE);
        }

        return 0;
    }

    const IOperand * operator-(const IOperand &rhs) const override
    {
        int precision = ( m_precision >= rhs.getPrecision() ) ? m_precision: rhs.getPrecision();
        eOperandType type = (m_type >= rhs.getType()) ? m_type : rhs.getType();

        try
        {
            std::stringstream stream(std::stringstream::out);
            if (type < Float)
            {
                long long result = std::stoll(m_str) - std::stoll(rhs.toString());
                if (isErrorLimits<long long>(result, type))
                {
                    std::string error = MyException::makeErrorString(m_line, g_kErrorLimit);
                    throw OperandException(error);
                }

                stream << result;
            }
            else
            {
                long double result = std::stold(m_str) - std::stold(rhs.toString());
                if (isErrorLimits<long double>(result, type))
                {
                    std::string error = MyException::makeErrorString(m_line, g_kErrorLimit);
                    throw MyException(error);
                }

                stream << std::setprecision(precision) << result;
            }

            return (m_factory.createOperand(type, stream.str()));
        }
        catch(const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
            exit(EXIT_FAILURE);
        }

        return 0;
    }

    const IOperand * operator*(const IOperand &rhs) const override
    {
        int precision = ( m_precision >= rhs.getPrecision() ) ? m_precision: rhs.getPrecision();
        eOperandType type = (m_type >= rhs.getType()) ? m_type : rhs.getType();

        try
        {
            std::stringstream stream(std::stringstream::out);
            if (type < Float)
            {
                long long result = std::stoll(m_str) * std::stoll(rhs.toString());
                if (isErrorLimits<long long>(result, type))
                {
                    std::string error = MyException::makeErrorString(m_line, g_kErrorLimit);
                    throw OperandException(error);
                }

                stream << result;
            }
            else
            {
                long double result = std::stold(m_str) * std::stold(rhs.toString());
                if (isErrorLimits<long double>(result, type))
                {
                    std::string error = MyException::makeErrorString(m_line, g_kErrorLimit);
                    throw OperandException(error);
                }

                stream << std::setprecision(precision) << result;
            }

            return (m_factory.createOperand(type, stream.str()));
        }
        catch(const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
            exit(EXIT_FAILURE);
        }

        return 0;
    }

    const IOperand * operator/(const IOperand &rhs) const override
    {
        int precision = ( m_precision >= rhs.getPrecision() ) ? m_precision: rhs.getPrecision();
        eOperandType type = (m_type >= rhs.getType()) ? m_type : rhs.getType();

        try
        {
            if (std::stold(rhs.toString()) == 0)
            {
                std::string error = MyException::makeErrorString(m_line, g_kDivisionByZero);
                throw OperandException(error);
            }

            std::stringstream stream(std::stringstream::out);
            if (type < eOperandType::Float)
            {
                long long result = std::stoll(m_str) / std::stoll(rhs.toString());
                if (isErrorLimits<long long>(result, type))
                {
                    std::string error = MyException::makeErrorString(m_line, g_kErrorLimit);
                    throw OperandException(error);
                }

                stream << result;
            }
            else
            {
                long double result = std::stold(m_str) / std::stold(rhs.toString());
                if (isErrorLimits<long double>(result, type))
                {
                    std::string error = MyException::makeErrorString(m_line, g_kErrorLimit);
                    throw OperandException(error);
                }

                stream << std::setprecision(precision) << result;
            }

            return m_factory.createOperand(type, stream.str());
        }
        catch(const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
            exit(EXIT_FAILURE);
        }

        return 0;
    }

    const IOperand * operator%(const IOperand &rhs) const override
    {
        int precision = ( m_precision >= rhs.getPrecision() ) ? m_precision: rhs.getPrecision();
        eOperandType type = (m_type >= rhs.getType()) ? m_type : rhs.getType();

        try
        {
            if (std::stold(rhs.toString()) == 0)
            {
                std::string error = MyException::makeErrorString(m_line, g_kModuloByZero);
                throw OperandException(error);
            }

            std::stringstream stream(std::stringstream::out);
            if (type < eOperandType::Float)
            {
                long long result = std::stoll(m_str) % std::stoll(rhs.toString());
                if (isErrorLimits<long long>(result, type))
                {
                    std::string error = MyException::makeErrorString(m_line, g_kErrorLimit);
                    throw OperandException(error);
                }
                stream << result;
            }
            else
            {
                long double result = fmod(std::stold(m_str), std::stold(rhs.toString()));
                if (isErrorLimits<long double>(result, type))
                {
                    std::string error = MyException::makeErrorString(m_line, g_kErrorLimit);
                    throw OperandException(error);
                }
                stream << std::setprecision(precision) << result;
            }

            return (m_factory.createOperand(type, stream.str()));
        }
        catch(const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
            exit(EXIT_FAILURE);
        }

        return 0;
    }

    bool operator>(const IOperand &rhs) const override
    {
        eOperandType type = (m_type >= rhs.getType()) ? m_type : rhs.getType();

        try
        {
            bool result = false;
            std::stringstream stream(std::stringstream::out);
            if (type < Float)
            {
                long long leftValue = std::stoll(m_str);
                long long rightValue = std::stoll(rhs.toString());

                result = (leftValue > rightValue);
            }
            else
            {
                long double leftValue = std::stold(m_str);
                long double rightValue = std::stold(rhs.toString());

                result = (leftValue > rightValue);
            }

            return result;
        }
        catch(const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    bool operator<(const IOperand &rhs) const override
    {
        return !(*this > rhs);
    }

    // just for canonical form
    Operand()
        : m_value(0),
        m_type(Int8),
        m_precision(0),
        m_line(0)
    {
    }

    const Operand& operator=(const Operand& operand)
    {
        if (this != &operand)
        {
            this->m_factory = operand.m_factory;
            this->m_value = operand.m_value;
            this->m_type = operand.m_type;
            this->m_precision = operand.m_precision;
            this->m_str = operand.m_str;
            this->m_line = operand.m_line;
        }

        return *this;
    }

    Operand(const Operand& operand)
    {
        *this = operand;
    }

private:
    T m_value;
    eOperandType m_type;
    int m_precision;
    const OperandFactory &m_factory;
    std::string m_str;
    int m_line;
};

#endif
