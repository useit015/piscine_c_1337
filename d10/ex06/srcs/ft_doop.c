/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 04:12:25 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/20 21:41:33 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_calcul(char *nb1, char *c, char *nb2)
{
	if (*c == '+')
		return (ft_atoi(nb1) + ft_atoi(nb2));
	if (*c == '-')
		return (ft_atoi(nb1) - ft_atoi(nb2));
	if (*c == '*')
		return (ft_atoi(nb1) * ft_atoi(nb2));
	if (*c == '/')
		return (ft_atoi(nb1) / ft_atoi(nb2));
	if (*c == '%')
		return (ft_atoi(nb1) % ft_atoi(nb2));
	return (0);
}

int		ft_cmp(char *s1, const char *s2)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		if (s1[i] != s2[i])
		{
			result = (s1[i] - s2[i]);
			break ;
		}
	}
	return (result);
}

int		is_oprt(char *c)
{
	if (!(ft_cmp(c, "+")) || !(ft_cmp(c, "-")))
		return (1);
	if (!(ft_cmp(c, "*")) || !(ft_cmp(c, "/")) || !(ft_cmp(c, "%")))
		return (1);
	return (0);
}

int		f_alpha(char *str)
{
	if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z'))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	if (is_oprt(av[2]))
	{
		if (!(ft_cmp(av[2], "/")) || !(ft_cmp(av[2], "%")))
		{
			if (f_alpha(av[1]) || f_alpha(av[3]))
			{
				ft_putstr("0\n");
				return (0);
			}
			if (ft_atoi(av[3]) == 0)
			{
				ft_display_err(av[2]);
				return (0);
			}
		}
		ft_putnbr(ft_calcul(av[1], av[2], av[3]));
		ft_putchar(10);
		return (0);
	}
	ft_putstr("0\n");
	return (0);
}
