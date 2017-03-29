/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_allmatrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:28:31 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/10 18:15:43 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_allmatrix(t_matrix *matrix)
{
	ft_printmatrix(matrix);
	while (matrix->next)
	{
		matrix = matrix->next;
		ft_printmatrix(matrix);
	}
}
