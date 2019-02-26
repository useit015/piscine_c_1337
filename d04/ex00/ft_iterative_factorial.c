/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:13:17 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/06 05:02:50 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int factorial;
	int i;

	i = 2;
	factorial = 1;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb < 2)
		return (1);
	while (i <= nb)
	{
		factorial *= i;
		i++;
	}
	return (factorial);
}
