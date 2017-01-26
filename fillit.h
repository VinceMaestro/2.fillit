/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:35:52 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/26 16:43:42 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

# define LAST 1

typedef struct s_matrix	t_matrix;
typedef struct s_pos	t_pos;

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
// static	int	ft_isvalid_char(char c);
// static	int	ft_isvalid(char *input);
//static	int	ft_right(char **bloc, int i, int j);
//static	int	ft_left(char **bloc, int i, int j);
//static	int	ft_up(char **bloc, int i, int j);
//static	int	ft_down(char **bloc, int i, int j);
int			ft_isvalid_shape(char **bloc, int i, int j, int *count);
// static	int	ft_scan_bloc(char **tmp);
// static	int	ft_scan_pieces(char **bloc, int pieces);
int			ft_reader(char	*input);
char		*ft_strtrimpiece(char const *s);
t_matrix	*ft_matrix_maker(char *str, int dim);
int			ft_transfmatrix(t_matrix *matrix, char axis, int num);
char		*ft_getbestshape(t_matrix *matrix);


#endif
