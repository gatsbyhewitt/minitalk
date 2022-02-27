/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abestaev <abestaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:05:58 by abestaev          #+#    #+#             */
/*   Updated: 2022/02/26 17:32:11 by abestaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = -n;
		write(fd, "-", 1);
	}
	else
		nb = n;
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	nb %= 10;
	nb += '0';
	write(fd, &nb, 1);
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ((void) NULL);
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ((void) NULL);
	write(fd, s, ft_strlen(s));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
