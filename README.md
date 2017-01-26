# fillit
42 project fillit

Pour avoir la string, voir main fillit ligne 43 -> 48


Compiler : (la partie enregistrement de la str est fonctionel)

Pour toi:
compile main_fillit.c ft_getstr.c ./libft/ft_bzero.c ./libft/ft_memcpy.c libft/ft_putstr_fd.c libft/ft_putnbr.c ft_error.c ft_reader.c -I libft/libft.h fillit.h

Pour moi:
gcc main_fillit.c ft_getstr.c ./libft/ft_bzero.c ./libft/ft_memcpy.c libft/ft_putstr_fd.c libft/ft_putnbr.c ft_error.c ft_reader.c ft_matrix_maker.c ft_isvalid_shape.c ./libft/ft_putstr.c ./libft/ft_strsplit.c ./libft/ft_strsub.c ./libft/ft_memalloc.c ./libft/ft_memset.c ./libft/ft_isalpha.c ./libft/ft_tolower.c ./libft/ft_toupper.c -I libft/libft.h fillit.h

lancer:
./a.out test.txt

ft_matrixmaker(string, dimension carre)
va creer une liste de matrices au fur et a mesure qu'elle parcourt la string
pour chaque matrice elle va mettre toutes les pieces le plus en haut a gauche possible
apelle ft_bestfit

ft_bestfit:
TotalMatrice += Matrice 1
	si fonctionne: Matrice 1++
	sinon: Matrice 1 += 1x
		si pas possible:
			Matrice 1 -= 1y + maxX
