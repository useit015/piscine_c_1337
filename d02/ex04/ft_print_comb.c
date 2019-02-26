/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 22:11:37 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/03 03:02:25 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_put_screen(int n, int a, int i)
{
	ft_putchar(n + 48);
	ft_putchar(i + 48);
	ft_putchar(a + 48);
	if (n != 7 || i != 8 || a != 9)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int n;
	int a;
	int i;

	n = 0;
	while (n <= 7)
	{
		i = n + 1;
		while (i <= 8)
		{
			a = i + 1;
			while (a <= 9)
			{
				ft_put_screen(n, a, i);
				a++;
			}
			i++;
		}
		n++;
	}
}
