/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:31:51 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 00:59:09 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_number_words(char const *s, char c)
{
	size_t	word;
	size_t	current_letter;

	word = 0;
	current_letter = 0;
	while (s[current_letter])
	{
		if (s[current_letter] != c && (current_letter == 0 || \
			s[current_letter - 1]))
			word++;
		current_letter++;
	}
	return (word);
}

static char	**ft_forstrsplit(char const *s, char c, char **dict_word)
{
	size_t	first_letter;
	size_t	current_letter;
	size_t	word;

	word = 0;
	first_letter = -1;
	current_letter = 0;
	while (s[current_letter])
	{
		if (s[current_letter] != c && first_letter == (size_t)-1)
			first_letter = current_letter;
		else if (s[current_letter] == c && first_letter != (size_t)-1)
		{
			dict_word[word] = ft_strsub(s, first_letter, \
				current_letter - first_letter);
			first_letter = -1;
			word++;
		}
		current_letter++;
	}
	if (!s[current_letter] && first_letter != (size_t)-1)
		dict_word[word++] = ft_strsub(s, first_letter, \
			current_letter - first_letter);
	dict_word[word] = 0;
	return (dict_word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**dict_word;

	if (s)
	{
		dict_word = (char**)malloc(sizeof(char*) * (ft_number_words(s, c) + 1));
		if (dict_word)
			return (ft_forstrsplit(s, c, dict_word));
	}
	else
		dict_word = (char **)malloc(sizeof(char*));
	if (dict_word)
		dict_word[0] = 0;
	return (dict_word);
}
