/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:35:52 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/10 19:16:58 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

# define LAST 1
# define I t_p.i
# define J t_p.j
# define DIESE t_p.diese
# define PIECES t_p.pieces

typedef struct s_matrix	t_matrix;
typedef struct s_pos	t_pos;
typedef struct s_map	t_map;
typedef	struct s_pieces	t_pieces;

struct	s_matrix
{
	char		name;
	int			dim;
	t_pos		*pos;
	t_matrix	*first;
	t_matrix	*next;
};

struct	s_pos
{
	int		x;
	int		y;
};

struct	s_map
{
	int		**axis;
};

struct	s_pieces
{
	int		i;
	int		j;
	int		diese;
	int		pieces;
};

void		ft_error();
void		ft_getstr(int open_fd, char **line);
int			ft_isvalid_shape(char **bloc, int i, int j, int *count);
int			ft_reader(char *input);
t_matrix	*ft_matrix_maker(char *str, int piece_nb);
t_matrix	*ft_m_xplus(t_matrix *matrix, int num);
t_matrix	*ft_m_yplus(t_matrix *matrix, int num);
t_matrix	*ft_getbestshape(t_matrix *matrix);
t_matrix	*ft_transfallmatrix(t_matrix *matrix, int piece_nb);
t_matrix	*ft_transfmatrix(t_matrix *matrix);
void		ft_printmatrix(t_matrix *matrix);
void		ft_print_allmatrix(t_matrix *matrix);
int			ft_roundup_sqrt(int nb);
t_map		*ft_mapalloc(t_map *map, int dim);
t_matrix	*ft_m_prev(t_matrix *matrix);
void		ft_printmap(t_map map, int dim);
char		**ft_map(t_matrix *first);
t_matrix	*ft_m_increasedim(t_matrix *matrix);

#endif
