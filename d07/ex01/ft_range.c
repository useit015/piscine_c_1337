/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 03:17:57 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/14 03:26:34 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int length;
	int *range;

	i = 0;
	length = max - min;
	if (length <= 0)
		return (0);
	range = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		range[i] = min + i;
		i++;
	}
	return (range ? range : 0);
}
