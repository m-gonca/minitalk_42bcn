/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:29:36 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/25 16:29:36 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int show_pid();
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
}

void ft_answer(int sign)
{
	unsigned char	byte;

	byte = 0;
	if(sign = 1)
	{
		byte = byte| 1;
	}

	if(sign = 0)
}

void ft_server(void)
{
	if (signal(SIGUSR1,  ft_answer) == SIG_ERR)
    {
      ft_printf("Error.\n");
      exit(1);
    }
	if (signal(SIGUSR2, ft_answer) == SIG_ERR)
    {
      ft_printf("Error.\n");
      exit(1);
    }
	while (1)
	{
		ft_printf("Esperando señales");
		sleep(2);
	}
	return (0);
}

int main()
{
	show_pid();
	ft_server();
	return(0);
}