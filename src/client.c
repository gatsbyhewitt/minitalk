/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abestaev <abestaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:45:48 by abestaev          #+#    #+#             */
/*   Updated: 2022/02/26 13:33:19 by abestaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minitalk.h"
#include <stdio.h>

void	ft_send_byte(int pid, char byte)
{
	int		shift;
	int		result;
	int		bit;

	shift = 0;
	while (shift < 8)
	{
		bit = (byte >> shift) & 1;
		if (bit == 0)
			result = kill(pid, SIGUSR1);
		else
			result = kill(pid, SIGUSR2);
		shift++;
		if (result == -1)
		{
			ft_putendl_fd("server PID is invalid", 1);
			exit(1);
		}
		usleep(600);
	}
}

void	ft_send_message(int pid, char *message)
{
	int		i;

	i = 0;
	while (message[i] != '\0')
	{
		ft_send_byte(pid, message[i]);
		i++;
	}
	ft_send_byte(pid, '\n');
	ft_putstr_fd("send!\n", 1);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		ft_putendl_fd("wrong arguments please specify <server pid> <your message>", 1);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	ft_putendl_fd("sending...", 1);
	ft_send_message(server_pid, argv[2]);
	return (0);
}

