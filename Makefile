NAME = ft_containers

SRCS = main.cpp

OBJECTS = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS += -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

all : $(NAME)

$(NAME) : $(OBJECTS)

	@${CXX} ${CXXFLAGS} -o ${NAME} -DTESTED_NAMESPACE=ft  $(OBJECTS) 
	@${CXX} ${CXXFLAGS} -o std_containers -DTESTED_NAMESPACE=std $(OBJECTS) 

clean : 
	@/bin/rm -f $(OBJECTS)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
