NAME = ft_containers
STD_NAME = std_containers

SRCS = main.cpp

OBJECTS = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS += -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECTS)

	@${CXX} ${CXXFLAGS} -o ${NAME} -DTESTED_NAMESPACE=ft  $(OBJECTS) 
	@${CXX} ${CXXFLAGS} -o ${STD_NAME} -DTESTED_NAMESPACE=std $(OBJECTS) 

clean : 
	@/bin/rm -f $(OBJECTS)

fclean : clean
	@/bin/rm -f $(NAME) ${STD_NAME}

re : fclean all
