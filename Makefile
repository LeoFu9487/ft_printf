NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRCS = ft_printf.c	out.c\
	./0/ft_0.c\
	./1/ft_1.c\
	./2/ft_2.c\
	./3/ft_3.c	./3/ft_3_.c	./3/ft_3_0.c	./3/ft_3_1.c	./3/ft_3_2.c	./3/ft_3_3.c\
	./5/ft_5.c	./5/ft_5_.c	./5/ft_5_0.c	./5/ft_5_1.c	./5/ft_5_2.c	./5/ft_5_3.c\
	./6/ft_6.c	./6/ft_6_.c	./6/ft_6_0.c	./6/ft_6_1.c	./6/ft_6_2.c	./6/ft_6_3.c\
	./7/ft_7.c	./7/ft_7_.c	./7/ft_7_0.c	./7/ft_7_1.c	./7/ft_7_2.c	./7/ft_7_3.c\
	./8/ft_8.c\
	./9/ft_9.c	./9/ft_9_.c	./9/ft_9_0.c	./9/ft_9_1.c	./9/ft_9_2.c	./9/ft_9_3.c\
	./10/ft_10.c\
	./11/ft_11.c\
	./12/ft_12.c\
	./parse/parse.c\
	./put/ft_put.c	./put/ft_put_flag_e.c	./put/ft_put_flag_g.c	./put/ft_putdouble.c\
	./utils/ft_itoa_base.c	./utils/ft_itoa_base_2.c	./utils/ft_minmax.c

HEADER = ./includes/

INCLUDE = ./includes/ft_printf.h

OBJS = $(SRCS:.c=.o)

LIBFT = ./Libft/libft.a

$(NAME) : $(OBJS) $(INCLUDE) $(LIBFT)
	@$(MAKE) bonus -C ./Libft
	@cp Libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

all : $(NAME)

bonus : $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER)  -c $< -o $@

clean : 
	@rm -rf $(OBJS)
	@$(MAKE) clean -C ./Libft
	
fclean : clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C ./Libft

git : 
	git add *
	git commit -m "autocommit"
	git push

re : fclean all

.PHONY: all bonus clean fclean re
