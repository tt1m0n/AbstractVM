cmake_minimum_required(VERSION 3.12)
project(AbstractVM)

set(CMAKE_CXX_STANDARD 17)

add_executable(AbstractVM main.cpp IOperand.h Operand.h Lexer.h Lexer.cpp MyException.h MyException.cpp Parser.h Parser.cpp OperandFactory.h OperandFactory.cpp LexerException.h LexerException.cpp ParserException.h ParserException.cpp OperandException.h OperandException.cpp)