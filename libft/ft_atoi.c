/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:35:09 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/03 21:08:24 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_test_letter(const char *str)
{
	int	letter;

	letter = 0;
	if (str[letter] == '-')
		letter++;
	if (str[letter] == '+' || str[letter] == '-')
		letter++;
	return (letter);
}

static int	ft_test_sign(const char *str)
{
	int	sign;
	int	letter;

	sign = 1;
	letter = 0;
	if (str[letter] == '-')
	{
		sign = -1;
		letter++;
	}
	if ((str[letter] == '+' || str[letter] == '-') && letter)
		sign = 0;
	return (sign);
}

static int	ft_check_len(unsigned long number, char letter, int sign)
{
	if (sign == -1 && (number * 10 + letter - 48 > \
		(unsigned long)9223372036854775807))
		return (0);
	else if (sign == 1 && (number * 10 + letter - 48 > \
		(unsigned long)9223372036854775806))
		return (-1);
	return (42);
}

int			ft_atoi(const char *str)
{
	int			letter;
	int			sign;
	long int	number;

	letter = 0;
	number = 0;
	while (ft_isinvisible(str[letter]))
		letter++;
	sign = ft_test_sign(&str[letter]);
	if (!sign)
		return (0);
	letter = letter + ft_test_letter(&str[letter]);
	while (str[letter] && ft_isdigit(str[letter]))
	{
		if (ft_check_len(number, str[letter], sign) != 42)
			return (ft_check_len(number, str[letter], sign));
		number = number * 10 + str[letter] - 48;
		letter++;
	}
	return (number * sign);
}
