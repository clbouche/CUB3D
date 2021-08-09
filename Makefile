########
# NAME #
########

NAME = cub3D

###################
# FLAGS & LIBRARY #
###################

#compiler
CC = gcc

#compiler flags
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -lm
CFLAGS += -lbsd
CFLAGS += -lX11
CFLAGS += -lXext

#MLX_MACOS = -lmlx -framework OpenGL -framework Appkit

###################
# PRINT VARIABLES #
###################

# Reset
NC = \033[0m

# Colors
YELLOW = \033[0;33m
GREEN = \033[32m
BLUE = \033[0;34m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
BLACK = \033[0;30
WHITE = \033[0;37m

# One Line Output
ONELINE =\e[1A\r

############
# Includes #
############

INCLUDES += -I /includes/cub.h
INCLUDES+= includes/get_next_line.h
INCLUDES += includes/minilibx/libmlx.a

########################
# Sources compilations #
########################

PATH_SRCS = sources

SRCS += main.c
SRCS += utils.c
SRCS += check_color.c
SRCS += parse_cub.c
SRCS += check_map.c
SRCS += fill_map.c
SRCS += get_next_line.c
SRCS += get_next_line_utils.c
SRCS += hook_move.c
SRCS += hook_rotate.c
SRCS += mlx_fct.c
SRCS += raycast.c
SRCS += textures.c
SRCS += errors.c
SRCS += utils_2.c
SRCS += drawing.c

vpath %.c $(PATH_SRCS)

########################
# Objects compilations #
########################

PATH_OBJS = objs/
OBJS = $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

#########
# RULES #
#########

all: $(PATH_OBJS) $(NAME)

$(NAME): $(OBJS) 
		@$(CC) $(OBJS) $(INCLUDES) $(CFLAGS) -o $(NAME)
		@echo "$(GREEN)$@ is ready.\n\n$(NC)"

$(OBJS): $(PATH_OBJS)%.o: %.c Makefile
		@$(CC) -c $< -o $@ 
		@echo "$(ONELINE)$(CYAN)Compiling $<\n$(NC)"

$(PATH_OBJS):
	@mkdir $@

clean:
	@$(RM) $(OBJS)
	@$(RM) -R $(PATH_OBJS)
	@echo "$(PURPLE)CLEAN $<"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(PURPLE)FCLEAN"

re: fclean all

.PHONY : all clean fclean re
