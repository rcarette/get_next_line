all :
	make -C libft fclean
	make -C libft/
	gcc -I libft/includes/ -c get_next_line.c
	gcc -I libft/includes/ -c main.c
	gcc -o gnl *.o -L libft/ -lft
	./gnl | cat -e
