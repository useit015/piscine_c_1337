/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 20:35:35 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/12 06:39:39 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_puthex(char c)
{
	char *base;

	base = "0123456789abcdef";
	if (c < 16)
		ft_putchar(base[(int)c]);
	else
	{
		ft_puthex(c / 16);
		ft_puthex(c % 16);
	}
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
		{
			ft_putchar(92);
			if (*str < 0)
				ft_putstr("ff");
			else
			{
				if (*str < 16)
					ft_putchar(48);
				ft_puthex(*str);
			}
		}
		else
			ft_putchar(*str);
		str++;
	}
}
