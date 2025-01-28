# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadib <yadib@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 15:15:10 by yadib             #+#    #+#              #
#    Updated: 2025/01/26 08:30:30 by yadib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap
BONUS_NAME = checker
MAIN_FUNC = main_func.c
MAIN_BONUS = bonus_part/cheacker_bonus.c

LIBR = tools.a
LIBR_BONUS = bonus_part/mylib.a

DIR_TOOLS = Tools_dir
DIR_OP = Operations
DIR_SORT = sorts_tools
DIR_BONUS = bonus_part

_TOOLS = atoiaXstrlen.c mini_tools.c	linkes_lists_tools.c	ft_split.c leaks_tools.c  check_duplicate.c
_OP_TOOLS =  push_logic.c swap_logic.c rotate_logic.c reverse_rotate_logic.c 
_SORT_TOOLS =  	find_help.c sort_single_3.c algo_of_5_nums.c calculate_best_solutions.c \
				partition.c    algo_3_tools.c \
				algo_version_1.c sort_of_4_nums.c  algo_version_3.c

FILES = insert_data.c indexing.c

_BONUS_FILES = cheacker_utils_bonus.c  get_next_line_bonus.c get_next_line_utils_bonus.c linked_list_bonus.c

TOOLS = $(addprefix $(DIR_TOOLS)/, $(_TOOLS))
OP_TOOLS = $(addprefix $(DIR_OP)/, $(_OP_TOOLS))
SORT_TOOLS = $(addprefix $(DIR_SORT)/, $(_SORT_TOOLS))
BONUS_FILES = $(addprefix $(DIR_BONUS)/, $(_BONUS_FILES))

TOOLS_HEAD = tools.h
OP_HEAD = operations.h


MAIN_OBJECTS = $(FILES:.c=.o)
TOOL_OBJECTS = $(TOOLS:.c=.o)
OP_OBJECTS = $(OP_TOOLS:.c=.o)
SORT_OBJECTS = $(SORT_TOOLS:.c=.o)
BONUS_OBJECTS = $(BONUS_FILES:.c=.o)

all: $(NAME)

# bonus part

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBR_BONUS) $(MAIN_BONUS)
	$(CC) $(CFLAGS) $(MAIN_BONUS) $(LIBR_BONUS) -o $(BONUS_NAME)

$(LIBR_BONUS): $(TOOL_OBJECTS) $(OP_OBJECTS) $(MAIN_OBJECTS) $(BONUS_OBJECTS)
	ar -rcs $(LIBR_BONUS) $(TOOL_OBJECTS) $(OP_OBJECTS) $(MAIN_OBJECTS) $(BONUS_OBJECTS)

# mandatory part
	
$(NAME): $(LIBR) $(MAIN_FUNC)
	$(CC) $(CFLAGS) $(MAIN_FUNC) $(LIBR) -o $(NAME)

#create libary tools

$(LIBR): $(TOOL_OBJECTS) $(OP_OBJECTS) $(MAIN_OBJECTS) $(SORT_OBJECTS)
	ar -rcs $(LIBR) $(TOOL_OBJECTS) $(OP_OBJECTS) $(MAIN_OBJECTS) $(SORT_OBJECTS)

$(DIR_SORT)/%.o: $(DIR_SORT)/%.c $(DIR_SORT)/algo_lib.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_OP)/%.o: $(DIR_OP)/%.c $(DIR_OP)/operations.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_TOOLS)/%.o: $(DIR_TOOLS)/%.c $(DIR_TOOLS)/$(TOOLS_HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_BONUS)/%.o: $(DIR_BONUS)/%.c $(DIR_BONUS)/cheacker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TOOL_OBJECTS) $(OP_OBJECTS) $(MAIN_OBJECTS) $(SORT_OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME) $(LIBR) $(BONUS_NAME) $(LIBR_BONUS)

re: fclean all

.PHONY: clean 
