NAME = philo
FLAGS = -Wall -Werror -Wextra -g
FILES = $(shell find src -type f -name "*.c")
OBJS = $(FILES:.c=.o)
DATE = $(shell /usr/bin/date)

all :$(NAME)

$(NAME) : $(OBJS)
	@gcc $(FLAGS) $(OBJS) -o $(NAME)

src/%.o : src/%.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	make -C include clean

fclean:
	@rm -f $(NAME) $(OBJS)
	make -C include fclean

re: fclean all

git:
	git add .
	git commit -m "Daily sync $(DATE)"
	git push origin main

.PHONY: re all fclean clean git