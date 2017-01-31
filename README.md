# fillit
42 project fillit

Pour avoir la string, voir main fillit ligne 43 -> 48


Compiler : (la partie enregistrement de la str est fonctionel)

Pour toi:
compile main_fillit.c ft_getstr.c ./libft/ft_bzero.c ./libft/ft_memcpy.c libft/ft_putstr_fd.c libft/ft_putnbr.c ft_error.c ft_reader.c -I libft/libft.h fillit.h

Pour moi:
gcc main_fillit.c ft_getstr.c ft_error.c ft_reader.c ft_isvalid_shape.c ft_matrix_maker.c ft_transfallmatrix.c ft_m_plus.c ./libft/ft_bzero.c ./libft/ft_memcpy.c ./libft/ft_putstr_fd.c ./libft/ft_putnbr.c ./libft/ft_putstr.c ./libft/ft_strsplit.c ./libft/ft_strsub.c ./libft/ft_memalloc.c ./libft/ft_memset.c ./libft/ft_isalpha.c ./libft/ft_tolower.c ./libft/ft_toupper.c -I ./libft/libft.h ./fillit.h

lancer:
./a.out test.txt

MAKEFILE fonctionel:
	Pour le moment le programme bug encore: Creation d'une matrice vide en trop qui fait planter

MAKEFILE:
	all:

	clean:

	fclean:

	re

./fillit test.txt
