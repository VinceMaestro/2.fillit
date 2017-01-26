/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfmatrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:44:08 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/26 18:18:20 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_transfmatrix(t_matrix *matrix, char axis, int num)
{
	int		subunit;
	int		end;

	subunit = 0;
	end = 0;
	while (subunit < 4 && end == 0)
	{
		if (axis == x && matrix->pos[subunit]->x + num >= 0 && \
			matrix->pos[subunit]->x + num <= matrix->dim)
			matrix->pos[subunit]->x = matrix->pos[subunit]->x + num;
		else if (axis == y && matrix->pos[subunit]->y + num >= 0 && \
			matrix->pos[subunit]->y + num <= matrix->dim)
			matrix->pos[subunit]->y = matrix->pos[subunit]->y + num;
		else
			end = 1;
	}
	return (1); //sucess
}

static int		ft_m_xplus(t_matrix *matrix, int num)
{
	int		subunit;
	int		end;

	subunit = 0;
	end = 0;
	while (end == 0 && matrix)
	{
		if (!(matrix->pos[subunit]->x + num >= 0 && \
			matrix->pos[subunit]->x + num <= matrix->dim))
			end = 1;
		else
			subunit++;
		if (subunit == 4)
		{
			while (subunit > 0 && end == 0)
			{
				matrix->pos[subunit]->x = matrix->pos[subunit]->x + num;
				subunit--;
			}
		}
	}
	return (end);
}

static int		ft_m_yplus(t_matrix *matrix, int num)
{
	int		subunit;
	int		end;

	subunit = 0;
	end = 0;
	while (end == 0 && matrix)
	{
		if (!(matrix->pos[subunit]->y + num <= 0 && \
			matrix->pos[subunit]->y + num >= -matrix->dim))
			end = 1;
		else
			subunit++;
		if (subunit == 4)
		{
			while (subunit > 0 && end == 0)
			{
				matrix->pos[subunit]->y = matrix->pos[subunit]->y + num;
				subunit--;
			}
		}
	}
	return (end);
}

static int		ft_m_plus(t_matrix *matrix, int num, char axis)
{
	int		ret;

	ret = 1;
	if (axis == 'x' || axis == 'X')
		ret = ft_m_xplus(matrix, num);
	else if (axis == 'y' || axis == 'Y')
		ret = ft_m_yplus(matrix, num);
	else
		ft_error("addition failed: unknown axis");
	return (ret);
}

// A finir
int			ft_transfallmatrix(t_matrix *matrix)
{
	int		subunit;
	int		end;

	subunit = 0;
	end = 0;
	while (matrix)
	{
		while (!(ft_m_plus(matrix, num)))
		{

		}
		matrix = matrix->next;
	}
	return (1); //sucess
}
