/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:26:06 by onahiz            #+#    #+#             */
/*   Updated: 2018/09/08 07:21:19 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (!new_word && str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		if (new_word)
		{
			if (str[i] >= 97 && str[i] <= 122)
				str[i] -= 32;
			new_word = 0;
		}
		if (str[i] < 48)
			new_word = 1;
		i++;
	}
	return (str);
}
