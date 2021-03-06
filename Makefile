# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mressier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/06 13:51:05 by mressier          #+#    #+#              #
#    Updated: 2018/01/07 15:34:48 by yguaye           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := game_2048

SRC_PATH := srcs
OBJ_PATH := bin
INC_PATH := includes

SRCS_NAMES =	main.c \
				t_grid.c \
				draw.c \
				events.c \
				menu_events.c \
				game_events.c \
				gameover_events.c \
				quit_dialog_events.c \
				score_events.c \
				t_grid_move.c \
				t_grid_tools.c \
				t_grid_map_iter.c \
				t_grid_win_or_loose.c \
				t_grid_spread_random_number.c \
				t_grid_calcul_column.c \
				t_grid_calcul_line.c \
				ft_read_file.c \
				ft_memjoin.c \
				ft_count_char.c \
				t_score_tab_file.c \
				t_score_from_string.c \
				t_score_tools.c \
				t_score_tab.c

OBJS_NAMES = $(SRCS_NAMES:.c=.o)

INC_NAMES =		draw.h \
				events.h \
				game_2048.h \
				grid.h \
				score.h


SRCS = $(addprefix $(SRC_PATH)/, $(SRCS_NAMES))
OBJS = $(addprefix $(OBJ_PATH)/, $(OBJS_NAMES))
INCS = $(addprefix $(INC_PATH)/, $(INC_NAMES))

CC = gcc
CFLAGS = --std=c99 -Wall -Werror -Wextra
CPPFLAGS = -I$(INC_PATH) -Ilibft/includes
RM = rm -f

LIBFT = libft/libft.a
LIBS = -lncurses -Llibft -lft

NORM_LOG = norm.log
NORM_FILES =

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@tput dl; tput cub 100; printf "\033[90mCreating object files: \033[32mdone!"
	@printf "\n\033[90mCompiling \033[0m$(NAME)\033[90m: \033[0m"
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIBS)
	@printf "\033[32mdone!\033[0m\n"

$(LIBFT):
	@make -C libft VERBOSE=0

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@tput dl; tput cub 100; printf "\033[90mCreating object files: \033[0m$(notdir $@)"
	@-$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(NORM_LOG)
	@$(RM) $(OBJS)
	@make -C libft fclean > /dev/null
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@printf "\033[33mRemoved \033[93mobject files!\033[0m\n"

fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean > /dev/null
	@printf "\033[33mRemoved \033[93m$(NAME) executable!\033[0m\n\n"

re: fclean all

norm:
	@printf "\033[90mChecking \033[0mThe Norm\033[90m...\033[0m\n"
	$(eval NORM_FILES = $(SRCS) $(shell find includes -type f -name "*.h"))
	@printf "Found \033[32m%s\033[0m files!\n" $(words $(NORM_FILES))
	@$(RM) $(NORM_LOG)
	@norminette $(NORM_FILES) >> $(NORM_LOG)
	@printf "Norm Errors: "
	@cat $(NORM_LOG) | grep Error | wc -l | bc
	@printf "See \033[4m$(NORM_LOG)\033[0m for details.\n"

.PHONY: all premsg clean fclean re norm
