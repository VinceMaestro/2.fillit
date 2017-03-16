NAME = fillit

CFLAGS = -Wall -Werror -Wextra

SRC = main_fillit.c \
		ft_map.c \
		ft_getstr.c \
		ft_error.c \
		ft_reader.c \
		ft_matrix_maker.c \
		ft_m_op.c \
		ft_isvalid_shape.c \
		ft_transform.c \
		ft_getbestshape.c \
		ft_mapalloc.c \

LIBDIR = ./libft

OBJ = $(SRC:.c=.o)

INCL = $(LIBDIR) \
		./

all: $(NAME)

$(LIBDIR)/libft.a:
	@make -C $(LIBDIR)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -g $(addprefix -I, $(INCL))

$(NAME) : $(OBJ) | $(LIBDIR)/libft.a
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -L $(LIBDIR) -l ft

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
