/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:10:59 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/13 18:14:14 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_length;
	unsigned int	src_length;

	dest_length = 0;
	src_length = ft_strlen(src);
	while (*dest && size > 0)
	{
		dest++;
		dest_length++;
		size--;
	}
	while (*src && size > 1)
	{
		size--;
		*dest++ = *src++;
	}
	if (size == 1 || *src == 0)
		*dest = 0;
	return (src_length + dest_length);
}
