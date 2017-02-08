NAME = fillit

CFLAGS = -Wall -Werror -Wextra

SRCFILLIT = main_fillit.c \
		ft_getstr.c \
		ft_error.c \
		ft_reader.c \
		ft_matrix_maker.c \
		ft_transfallmatrix.c \
		ft_m_xplus.c \
		ft_m_yplus.c \
		ft_isvalid_shape.c \
		ft_printmatrix.c \
		ft_getmatrix.c \
		ft_print_allmatrix.c \
		ft_roundup_sqrt.c \
		ft_transfmatrix.c \
		ft_getbestshape.c \
		ft_mapalloc.c \
		ft_m_prev.c

SRCLIB = ft_bzero.c \
		ft_memcpy.c \
		ft_putstr_fd.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putchar.c \
		ft_strsplit.c \
		ft_strsub.c \
		ft_memalloc.c \
		ft_memset.c \
		ft_isalpha.c \
		ft_tolower.c \
		ft_toupper.c

LIBDIR = ./libft

SRC = $(foreach element,$(SRCLIB), ./$(LIBDIR)/$(element)) \
		$(SRCFILLIT)

OBJ = $(SRCFILLIT:.c=.o)\
		$(SRCLIB:.c=.o)

INCL = ./libft/libft.h \
		./fillit.h

all: $(NAME)

$(NAME) : $(SRC)
			gcc $(CFLAGS) -c $(SRC) -I $(INCL)
			gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
