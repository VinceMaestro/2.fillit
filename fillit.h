/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:35:52 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/12 16:16:23 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define LAST 1

typedef struct s_matrix	t_matrix;
typedef struct s_pos	t_pos;

struct	s_matrix
{
	char		name;
	int			dim;
	t_pos		*pos;
	s_matrix	*first;
	s_matrix	*next;
};

struct	s_pos
{
	int		x;
	int		y;
	int		z;
};

void	ft_error(void);

#endif
