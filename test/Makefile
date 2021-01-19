NAME = test

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

TEST :
	gcc $(CFLAGS) -D TEST_0 -D TEST_1 -D TEST_2 -D TEST_3 -D TEST_4 -D TEST_5 -D TEST_6 -D TEST_7 -D TEST_8 -D TEST_9 -D TEST_10 -D TEST_11 -D TEST_12  main.c libftprintf.a -o test
	./test -| cat -e

TEST0 :
	gcc $(CFLAGS) -D TEST_0 main.c libftprintf.a -o test
	./test -| cat -e

TEST1 :
	gcc $(CFLAGS) -D TEST_1 main.c libftprintf.a -o test
	./test -| cat -e
	
TEST2 :
	gcc $(CFLAGS) -D TEST_2 main.c libftprintf.a -o test
	./test -| cat -e

TEST3 :
	gcc $(CFLAGS) -D TEST_3 main.c libftprintf.a -o test
	./test -| cat -e

TEST4 :
	gcc $(CFLAGS) -D TEST_4 main.c libftprintf.a -o test
	./test -| cat -e

TEST5 :
	gcc $(CFLAGS) -D TEST_5 main.c libftprintf.a -o test
	./test -| cat -e

TEST6 :
	gcc $(CFLAGS) -D TEST_6 main.c libftprintf.a -o test
	./test -| cat -e

TEST7 :
	gcc $(CFLAGS) -D TEST_7 main.c libftprintf.a -o test
	./test -| cat -e

TEST8 :
	gcc $(CFLAGS) -D TEST_8 main.c libftprintf.a -o test
	./test -| cat -e

TEST9 :
	gcc $(CFLAGS) -D TEST_9 main.c libftprintf.a -o test
	./test -| cat -e

TEST10 :
	gcc $(CFLAGS) -D TEST_10 main.c libftprintf.a -o test
	./test -| cat -e

TEST11 :
	gcc $(CFLAGS) -D TEST_11 main.c libftprintf.a -o test
	./test -| cat -e

TEST12 :
	gcc $(CFLAGS) -D TEST_12 main.c libftprintf.a -o test
	./test -| cat -e

$(NAME) :
	$(MAKE) re -C ../
	cp ../libftprintf.a .
	gcc $(CFLAGS) main.c libftprintf.a -o test
	./test

re :
	make clean
	make all

clean :
	rm test
