/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:58:16 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/01 00:29:07 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix		*ft_getmatrix(t_matrix *matrix, char name)
{
	if (matrix && name)
	{
		while (matrix->next && matrix->name != name)
			matrix = matrix->next;
		if (matrix->name == name)
		{
			ft_putchar(matrix->name);
			return (matrix);
		}
	}
	else
		ft_error("FT_GETMATRIX: Parameters incorect");
	return (matrix);
}
