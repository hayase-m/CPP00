NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP

SRCS = PhoneBook.cpp Contact.cpp main.cpp

OBJDIR = objs
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
RM = rm -rf

-include $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
