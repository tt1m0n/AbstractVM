XX = clang++

CXXFLAGS = -std=c++14 -Wall -Wextra -Werror

NAME = avm

SRC = main.cpp Lexer.cpp OperandFactory.cpp Parser.cpp\
	MyException.cpp LexerException.cpp OperandException.cpp\
	ParserException.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
