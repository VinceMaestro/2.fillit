/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:58:16 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/31 19:09:35 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_getmatrix(t_matrix *matrix, char name)
{
	if (matrix)
	{
		if (!matrix->next || !matrix->name || matrix->name == name)
			return (1);
		ft_putstr("matrix next AAAAAAAAAAAAAAA 2222222\n");
		while (matrix->next && matrix->name != name)
		{
			ft_putstr("matrix next AAAAAAAAAAAAAAA\n");
			matrix = matrix->next;
		}
		if (matrix->name == name)
			return (1);
		ft_putstr("matrix next AAAAAAAAAAAAAAA 333333\n");
	}
	return (0);
}
