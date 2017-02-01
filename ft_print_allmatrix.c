/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_allmatrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:28:31 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/01 00:14:43 by vpetit           ###   ########.fr       */
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
