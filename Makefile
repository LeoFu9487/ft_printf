NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRCS = ft_printf.c	out.c\
	./0/ft_0.c	./0/ft_0_0.c\
	./1/ft_1.c	./1/ft_1_0.c\
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
	./parse/parse.c	./parse/parse2.c\
	./put/ft_put.c	./put/ft_put_flag_e.c	./put/ft_put_flag_g.c	./put/ft_putdouble.c\
	./utils/ft_itoa_base.c	./utils/ft_itoa_base_2.c	./utils/ft_minmax.c

HEADER = ./includes/

INCLUDE = ./includes/ft_printf.h

OBJS = $(SRCS:.c=.o)

LIBFT = ./Libft/libft.a

LIBFTPATH = ./Libft/

LIBFTFILE = ft_split.c       ft_strchr.c \
ft_atoi.c                       ft_strdup.c \
ft_bzero.c                      ft_strjoin.c \
ft_calloc.c                     ft_memccpy.c            ft_strlcat.c \
ft_isalnum.c            ft_memchr.c                     ft_strlcpy.c \
ft_isalpha.c            ft_memcmp.c                     ft_strlen.c \
ft_isascii.c            ft_memcpy.c                     ft_strmapi.c \
ft_isdigit.c            ft_memmove.c            ft_strncmp.c \
ft_isprint.c            ft_memset.c                     ft_strnstr.c \
ft_itoa.c                       ft_strrchr.c \
ft_putchar_fd.c         ft_strtrim.c \
ft_putendl_fd.c         ft_substr.c \
ft_putnbr_fd.c          ft_tolower.c \
ft_putstr_fd.c          ft_toupper.c	libft.h

LIBFTSRCS = $(addprefix $(LIBFTPATH), $(LIBFTFILE))

LIBFTOBJS = $(LIBFTSRCS:.c=.o)

$(NAME) : $(LIBFTSRCS) $(LIBFTOBJS) $(LIBFT) $(INCLUDE) $(OBJS) $(SRCS)
	@$(MAKE) -C ./Libft/
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libftprintf.a created / updated successfully"

$(LIBFTOBJS) :
	@$(MAKE) -C ./Libft/

$(LIBFT) :
	@$(MAKE) -C ./Libft/

%.o : %.c $(INCLUDE) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(HEADER)  -c $< -o $@

all : $(LIBFTSRCS) $(LIBFTOBJS) $(LIBFT) $(INCLUDE) $(OBJS) $(SRCS) $(NAME)

bonus : $(LIBFTSRCS) $(LIBFTOBJS) $(LIBFT) $(INCLUDE) $(OBJS) $(SRCS) $(NAME)
	@echo "(bonus)"

clean : 
	@rm -rf $(OBJS)
	@$(MAKE) clean -C ./Libft
	@echo "libftprintf.a clean finished"

fclean :
	@rm -rf $(NAME) $(OBJS)
	@$(MAKE) fclean -C ./Libft
	@echo "libftprintf.a fclean finished"

re : fclean all

norm :
	@norminette $(SRCS)
	@norminette $(INCLUDE)
	@norminette $(LIBFTSRCS)

git :
	@git add $(SRCS)
	@git add $(INCLUDE)
	@git add $(LIBFTSRCS)
	@git add Makefile
	@git add ./Libft/Makefile
	git commit -m "autocommit0"

.PHONY: all bonus clean fclean re
