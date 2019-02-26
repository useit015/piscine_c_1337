/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 03:47:32 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/19 00:44:09 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		size;
	int		*tab;

	size = 0;
	if (min >= max)
	{
		*range = NULL;
		return (size);
	}
	tab = (int*)malloc(sizeof(**range) * (max - min));
	if (tab)
	{
		size = max - min;
		i = 0;
		while (i < size)
		{
			tab[i] = i + min;
			i++;
		}
	}
	*range = tab;
	return (size);
}
