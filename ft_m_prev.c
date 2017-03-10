/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_prev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:39:43 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/10 18:15:27 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*ft_m_prev(t_matrix *matrix)
{
	t_matrix	*current;

	current = matrix;
	matrix = matrix->first;
	while (matrix->next != current && matrix != current)
		matrix = matrix->next;
	return (matrix);
}
