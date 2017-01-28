/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:35:52 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/28 15:57:18 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

# define LAST 1

typedef struct s_matrix	t_matrix;
typedef struct s_pos	t_pos;
typedef struct s_piece	t_piece;

struct	s_piece
{
	char		*tetri;
	char		name;
};

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
	int		z;
};

void		ft_error(char	*msg);
void		ft_getstr(int open_fd, char **line);
int			ft_isvalid_shape(char **bloc, int i, int j, int *count);
int			ft_reader(char	*input);
char		*ft_strtrimpiece(char const *s);
t_matrix	*ft_matrix_maker(char *str, int dim);
int			ft_m_plus(t_matrix *matrix, int num, char axis);
char		*ft_getbestshape(t_matrix *matrix);
int			ft_transfallmatrix(t_matrix *matrix);
void		ft_printmatrix(t_matrix *matrix);
int			ft_getmatrix(t_matrix *matrix, char name);

#endif
