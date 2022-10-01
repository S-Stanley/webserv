SRCS = srcs/main.cpp srcs/parsing.cpp helpers/remove_space.cpp helpers/split_string.cpp helpers/down.cpp
ODIR = .obj
OBJS = $(addprefix $(ODIR)/, $(SRCS:.cpp=.o))
DEP = $(OBJS:.o=.d)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
CFLAGS = $(FLAGS) -MMD
RM = rm -rf
NAME = webserv

all: init $(NAME)

init:
	@mkdir -p .obj/tests .obj/srcs .obj/helpers

-include $(DEP)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

$(ODIR)/%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(DEP)
	$(RM) $(ODIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
