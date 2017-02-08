/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfmatrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:18:20 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/08 19:18:21 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*ft_transfmatrix(t_matrix *matrix)
{
	while (matrix->pos[1].x != (ft_m_xplus(matrix, -1))->pos[1].x)
		;
	while (matrix->pos[1].y != (ft_m_yplus(matrix, 1))->pos[1].y)
		;
	return (matrix);
}
