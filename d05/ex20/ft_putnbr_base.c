/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 04:57:40 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/08 19:08:11 by onahiz           ###   ########.fr       */
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

int		is_alphanumeric(char *str)
{
	while (*str)
	{
		if (*str < 48 || (*str > 57 && *str < 65)
		|| (*str > 90 && *str < 97) || *str > 122)
			return (0);
		str++;
	}
	return (1);
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

void	ft_putmaxnbr_base(unsigned int nbr, char *base, int length)
{
	unsigned int u_length;

	u_length = length;
	if (nbr >= u_length)
	{
		ft_putmaxnbr_base(nbr / length, base, length);
		ft_putmaxnbr_base(nbr % length, base, length);
	}
	else
		ft_putchar(base[nbr]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				length;
	unsigned int	max_int;

	max_int = 2147483648;
	length = ft_strlen(base);
	if (is_alphanumeric(base) && has_no_double(base) && length > 1)
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			ft_putmaxnbr_base(max_int, base, length);
		}
		else if (nbr < 0)
		{
			ft_putchar('-');
			ft_putnbr_base(-nbr, base);
		}
		else if (nbr >= length)
		{
			ft_putnbr_base(nbr / length, base);
			ft_putnbr_base(nbr % length, base);
		}
		else
			ft_putchar(base[nbr]);
	}
}
