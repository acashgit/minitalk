/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:12:40 by acash             #+#    #+#             */
/*   Updated: 2021/11/16 17:12:41 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	pid_check(int *bit_nubmer, int *newhexn, int *spid, int newpid)
{
	(*bit_nubmer) = 0;
	(*newhexn) = 0;
	(*spid) = newpid;
}

void	ft_send(int pid)
{
	kill(pid, SIGUSR2);
}

static void	client_send(int sig, siginfo_t *info, void *answer)
{
	static int		newhexn = 0;
	static int		bit_number = 0;
	static int		clientpid = 0;

	(void)answer;
	if (!clientpid || clientpid != info->si_pid)
		pid_check(&bit_number, &newhexn, &clientpid, info->si_pid);
	if (sig == SIGUSR1)
		newhexn += 1 << (7 - bit_number);
	bit_number++;
	if (bit_number == 8)
	{
		write(1, &newhexn, 1);
		newhexn = 0;
		bit_number = 0;
	}
	ft_send(clientpid);
}

int	main(void)
{
	struct sigaction	sig;

	ft_memset(&sig, 0, sizeof(sig));
	sig.sa_sigaction = client_send;
	if (sigaction(SIGUSR1, &sig, NULL) == -1
		|| sigaction(SIGUSR2, &sig, NULL) == -1)
		return (0);
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
