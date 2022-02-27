/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abestaev <abestaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:25:48 by abestaev          #+#    #+#             */
/*   Updated: 2022/02/26 17:31:39 by abestaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	number;
	int	n;

	i = 0;
	number = 0;
	n = 1;
	while (nptr[i] != '\0' && ((nptr[i] >= 9 && nptr[i] <= 13)
			|| nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n *= -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		number *= 10;
		number += nptr[i] - '0';
		i++;
	}
	number *= n;
	return (number);
}