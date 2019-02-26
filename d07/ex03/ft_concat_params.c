/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 05:07:28 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/17 02:58:56 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src, int last)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	if (last)
		dest[i + j] = 0;
	else
	{
		dest[i + j] = 10;
		dest[i + j + 1] = 0;
	}
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		total_length;
	int		is_last;
	char	*str;

	i = 1;
	is_last = 0;
	total_length = 0;
	while (i < argc)
	{
		total_length += ft_strlen(argv[i]) + 1;
		i++;
	}
	str = (char *)malloc(sizeof(char) * total_length);
	i = 1;
	while (i < argc)
	{
		if (i == argc - 1)
			is_last = 1;
		str = ft_strcat(str, argv[i], is_last);
		i++;
	}
	return (str);
}
