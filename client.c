/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:12:46 by acash             #+#    #+#             */
/*   Updated: 2021/11/16 17:12:49 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_answers = 0;

void	output(int sig)
{
	(void)sig;
	g_answers++;
	usleep(800);
}

void	connect_to_server(int pid, int n)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		if (n & 1 << bits)
		{
			if (kill(pid, SIGUSR1))
				exit(0);
		}
		else
		{
			if (kill(pid, SIGUSR2))
				exit(0);
		}
		bits--;
		usleep(900);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	si;

	ft_memset(&si, 0, sizeof(si));
	signal(SIGUSR2, output);
	i = 0;
	if (argc != 3)
	{
		ft_putstr("wrong input! try write 'PID' 'message' ");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		connect_to_server(pid, argv[2][i]);
		i++;
	}
	connect_to_server(pid, 0);
	ft_putstr("count of answers: ");
	ft_putnbr(g_answers);
	ft_putchar('\n');
	return (0);
}
