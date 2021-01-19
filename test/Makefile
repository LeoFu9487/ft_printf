NAME = test

CFLAGS = -Wall -Werror -Wextra

go :
	gcc $(CFLAGS) main.c libftprintf.a -o test
	./test -| cat -e

$(NAME) :
	$(MAKE) re -C ../
	cp ../libftprintf.a .
	gcc $(CFLAGS) main.c libftprintf.a -o test
	./test

all : $(NAME)

re :
	make clean
	make all

clean :
	rm test