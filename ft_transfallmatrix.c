/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfallmatrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 13:10:26 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/16 05:38:34 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*ft_transfallmatrix(t_matrix *matrix)
{
	if (matrix)
	{
		matrix = ft_transfmatrix(matrix);
		while (matrix->next)
		{
			matrix = matrix->next;
			matrix = ft_transfmatrix(matrix);
		}
		matrix = matrix->first;
	}
	return (matrix);
}
