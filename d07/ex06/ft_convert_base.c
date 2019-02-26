/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 18:43:39 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/18 06:28:32 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				ft_get_val(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

unsigned int	ft_to_decimal(char *str, char *base_from)
{
	int i;
	int nb;
	int power;
	int	base_len;

	nb = 0;
	power = 1;
	base_len = ft_strlen(base_from);
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (ft_get_val(str[i], base_from) < 0)
			return (0);
		nb += ft_get_val(str[i], base_from) * power;
		power *= base_len;
		i--;
	}
	return (nb);
}

char			*ft_to_base(unsigned int nbr, char *base_to, int sign)
{
	int		i;
	int		base_l;
	char	*result;

	i = 0;
	base_l = ft_strlen(base_to);
	result = (char *)malloc(sizeof(char) * 32);
	if (nbr == 0)
	{
		result[i] = base_to[i];
		i++;
	}
	while (nbr > 0)
	{
		result[i] = base_to[nbr % base_l];
		nbr /= base_l;
		i++;
	}
	if (sign < 0)
	{
		result[i] = '-';
		i++;
	}
	result[i] = 0;
	return (result);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		j;
	int		sign;
	char	temp;
	char	*result;

	i = -1;
	sign = 1;
	if (nbr[0] == '-')
		sign = -1;
	if (nbr[0] == '-' || nbr[0] == '+')
		nbr++;
	result = ft_to_base(ft_to_decimal(nbr, base_from), base_to, sign);
	j = ft_strlen(result);
	while (++i < --j)
	{
		temp = result[i];
		result[i] = result[j];
		result[j] = temp;
	}
	return (result);
}
