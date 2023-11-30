# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mawad <mawad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 19:34:03 by mawad             #+#    #+#              #
#    Updated: 2023/11/15 21:13:46 by mawad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c utils.c get_next_line.c map.c image.c manager.c move.c message.c map_rules.c valid_path.c destroy.c \
		ft_printf/ft_print_address.c ft_printf/ft_print_hex.c ft_printf/ft_print_nbr.c ft_printf/ft_print_unsigned.c \
		ft_printf/ft_printf_utils.c ft_printf/ft_printf.c

OBJS = $(SRCS:.c=.o)

BONUS_DIR = bonus

BONUS_SRCS = $(addprefix $(BONUS_DIR)/, animation1_bonus.c animation2_bonus.c destroy_bonus.c enemy_rules_bonus.c ft_itoa_bonus.c \
				get_next_line_bonus.c image_bonus.c main_bonus.c manager_bonus.c map_bonus.c map_rules_bonus.c message_bonus.c \
			 	move_bonus.c utils_bonus.c valid_path_bonus.c) ft_printf/ft_print_address.c ft_printf/ft_print_hex.c \
				ft_printf/ft_print_nbr.c ft_printf/ft_print_unsigned.c ft_printf/ft_printf_utils.c ft_printf/ft_printf.c
				
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $^ -o $@


bonus: $(BONUS_NAME)
	
$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME)

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $^ -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus