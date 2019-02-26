/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 04:57:46 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/12 01:46:15 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_valid(char *str, char *base)
{
	int count;
	int j;

	j = 0;
	while (base[j])
	{
		if (base[j] == 43 || base[j] == 45)
			return (0);
		j++;
	}
	while (*str)
	{
		j = 0;
		count = 0;
		while (base[j])
		{
			if (*str == base[j] || *str == 43 || *str == 45)
				count = 1;
			j++;
		}
		if (!count)
			return (0);
		str++;
	}
	return (count);
}

int		has_no_double(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[j] && i != j)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		convert_base(char *str, char *base, int i, int length)
{
	int result;
	int j;

	result = 0;
	while (str[i] > 48)
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				result = (result * length) + j;
			j++;
		}
		i++;
	}
	return (result);
}

int		ft_atoi_base(char *str, char *base)
{
	int length;
	int sign;
	int result;
	int i;

	i = 0;
	sign = 1;
	length = ft_strlen(base);
	if (is_valid(str, base) && has_no_double(base) && length > 1 && *str)
	{
		while (str[i] > 0 && str[i] < 33)
			i++;
		if (str[i] == '-')
			sign = -1;
		if (str[i] == '-' || str[i] == '+')
			i++;
		result = convert_base(str, base, i, length);
		return (result * sign);
	}
	return (0);
}
