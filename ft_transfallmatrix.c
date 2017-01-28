/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfallmatrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 13:10:26 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/28 16:00:55 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_transfallmatrix(t_matrix *matrix)
{
	t_matrix	*last;

	ft_getmatrix(matrix, LAST);
	last = matrix;
	matrix = matrix->first;
	while (matrix != last)
	{
		printf("matrix WAS :\n");
		ft_printmatrix(matrix);
		while (!(ft_m_plus(matrix, -1, 'x')))
			printf("matrix up x\n");
		while (!(ft_m_plus(matrix, 1, 'y')))
			printf("matrix up y\n");
		printf("matrix IS :\n");
		ft_printmatrix(matrix);
		matrix = matrix->next;
	}
	return (1);
}
