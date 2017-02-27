/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_increasedim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:41:51 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/27 20:55:25 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*ft_m_increasedim(t_matrix *matrix)
{
	while (matrix)
	{
		matrix->dim += 1;
		if (!matrix->next)
			return (matrix = matrix->first);
		matrix = matrix->next;
	}
	ft_error();
	return (NULL);
}
