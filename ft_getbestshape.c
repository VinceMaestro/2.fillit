/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbestshape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 04:15:14 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/01 16:33:26 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*ft_getbestshape(t_matrix *matrix)
{
	t_map		*map;
	t_matrix	tmp;

	map = (*map)malloc(sizeof(map));
	tmp = ft_iter(matrix, map);
	if (tmp)
		matrix = tmp;
	else
	{
		matrix = ft_m_increasedim(matrix);
		matrix = ft_transfallmatrix(matrix);
	}
	return (matrix);
}

static t_matrix	ft_m_increasedim(t_matrix *matrix)
{
	return (matrix);
}

static t_matrix	ft_m_append(t_map *map, t_matrix *matrix)
{
	return (matrix);
}

static t_matrix	ft_iter(t_matrix *matrix, t_map *map)
	while (!ft_m_append(map, matrix))
	{
		if (matrix == ft_m_xplus(matrix, 1))
		{
			if (matrix == ft_m_yplus(matrix, -1));
			{
				if matrix == ft_m_pop(map, matrix)
					return (NULL);
				else
				{
					ft_m_swap(matrix);
					return (ft_getbestshape(matrix));
				}

			}
		}
	}
}
