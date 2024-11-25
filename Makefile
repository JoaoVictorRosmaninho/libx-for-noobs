
GREEN	     :=	\e[92;5;118m
YELLOW	     :=	\e[93;5;226m
GRAY	     :=	\e[33;2;37m
RESET	     :=	\e[0m
CURSIVE	     :=	\e[33;3m

NAME        := nooblibx
CC          := clang
CFLAGS      := -Wall -Wextra -Werror
GDBFLAGS    := -ggdb
STD			:= -std=c23
DIST        := build

HEADERS     := $(wildcard includes/*.h)
HEADERS     += $(wildcard libs/libft/includes/libft.h)

HEADER_DIRS := $(dir $(HEADERS)) 
IFLAGS		:= $(addprefix -I, $(HEADER_DIRS))

SOURCES		:= $(wildcard src/*.c)
SOURCES		+= $(wildcard src/buffer/*.c)
SOURCES		+= $(wildcard src/window/*.c)

OBJECTS		:= $(addprefix $(DIST)/, $(SOURCES:.c=.o))

DIRS		:= $(dir $(OBJECTS))

LIBFT       := ./libft

LIBFTBUILD  := ./build/libs/libft.a

LIBFTFLAGS  := -L./build/libs -lft

EXTRALIBFLAGS := -lm -lX11



vpath %.h $(HEADER_DIRS)
vpath %.c $(DIRS)

.PHONY:	all clean re

all: $(NAME)

$(NAME): $(DIST) $(OBJECTS) $(LIBFTBUILD)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	$(CC) $(OBJECTS) $(LIBFTFLAGS) $(EXTRALIBFLAGS) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

$(LIBFTBUILD):
	make -C libs/libft libft.a
#	ln -fsv libs/libft/libft.a build/libs
	cp -v libs/libft/libft.a build/libs

$(DIST)/%.o: %.c
	$(CC) $(STD) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(DIST):
	@mkdir -p $(DIRS)
	@mkdir build/libs

clean:
	@rm -rf $(OBJECTS)
	make -C libs/libft clean
	@printf "$1 (YELLOW)    - Objects removed.$(RESET)\n"

fclean: clean
	@rm -f   $(NAME)
	@rm -rf  $(DIST)
	make -C libs/libft fclean
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./$(NAME)
re: fclean all
