/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:29:36 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/30 19:13:21 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_sendconfirmation(siginfo_t *info)
{
	pid_t	client_pid;

	client_pid = info->si_pid;
	kill(client_pid, SIGUSR1);
}

static void	ft_answer(int sign, siginfo_t *info, void *context)
{
	static unsigned char	byte = 0;
	static unsigned char	shift = 1 << 7;
	static int				counter = 7;

	(void)context;
	if (counter >= 0)
	{
		if (sign == SIGUSR1)
		{
			byte = shift ^ byte;
			shift = shift >> 1;
		}
		else if (sign == SIGUSR2)
			shift = shift >> 1;
		ft_sendconfirmation(info);
	}
	counter--;
	if (counter < 0)
	{
		write(1, &byte, 1);
		counter = 7;
		byte = 0;
		shift = 1 << 7;
	}
}

static void	ft_server(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_answer;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	else if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	while (1)
		pause();
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	ft_server();
	return (0);
}
