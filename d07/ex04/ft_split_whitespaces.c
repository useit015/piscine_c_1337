/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 02:05:35 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/17 06:21:48 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_whitespace(char c)
{
	if (c == 9 || c == 10 || c == 0 || c == 32)
		return (1);
	return (0);
}

int		count_whitespaces(char *str)
{
	int spaces;

	spaces = 0;
	while (*str)
	{
		if (is_whitespace(*str) && !is_whitespace(*(str + 1)))
			spaces++;
		str++;
	}
	return (spaces);
}

int		chars_in_word(char *str)
{
	int chars;

	chars = 0;
	while (*str)
	{
		if (!is_whitespace(*str))
			chars++;
		else
			break ;
		str++;
	}
	return (chars);
}

char	*make_word(char *str, int *index)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (chars_in_word(str + *index) + 1));
	while (!is_whitespace(str[*index]))
	{
		word[i] = str[*index];
		(*index)++;
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	char	**strv;

	i = 0;
	j = 0;
	strv = (char **)malloc(sizeof(char *) * (count_whitespaces(str) + 2));
	while (str[i])
	{
		if (is_whitespace(str[i]))
			i++;
		else
		{
			strv[j] = make_word(str, &i);
			j++;
		}
	}
	strv[j] = NULL;
	return (strv);
}
