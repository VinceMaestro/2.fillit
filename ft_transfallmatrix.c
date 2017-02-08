/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfallmatrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 13:10:26 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/08 19:18:31 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*ft_transfallmatrix(t_matrix *matrix)
{
	int		end;

	end = 0;
	while (matrix && end == 0)
	{
		matrix = ft_transfmatrix(matrix);
		if (matrix->next)
			matrix = matrix->next;
		else
			end = 1;
	}
	matrix = matrix->first;
	return (matrix);
}
