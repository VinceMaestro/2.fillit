/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfmatrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:18:20 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/10 18:11:43 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*ft_transfmatrix(t_matrix *matrix)
{
	matrix = ft_m_xplus(matrix, -matrix->dim);
	matrix = ft_m_yplus(matrix, matrix->dim);
	return (matrix);
}
