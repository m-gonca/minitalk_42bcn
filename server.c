/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:29:36 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/28 19:24:57 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void show_pid()
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
}

void ft_answer(int sign)
{
	static unsigned char	byte = 0;
	static unsigned char	shift = 1 << 6;
	static int 				counter = 6;
	
	if (counter > 0)
	{
		if (sign == 30)
		{
			byte = shift ^ byte;
			shift = shift >> counter;
		}
		if (sign == 31)
			shift = shift >> counter;
	}
	counter--;
	if (counter == 0)
	{
		write(1, &byte, 1);
		counter = 6;
		byte = 0;
		shift = shift << 6;
	}
}

void ft_server(void)
{
	ft_printf("he entrado en mandar aqui\n");
	if (signal(SIGUSR1,  ft_answer) == SIG_ERR)
    {
      ft_printf("Error\n");
      exit(1);
    }
	if (signal(SIGUSR2, ft_answer) == SIG_ERR)
    {
      ft_printf("Error\n");
      exit(1);
    }
	while (1)
	{
		ft_printf("Waiting for signals\n");
		sleep(2);
	}
}

int main()
{
	show_pid();
	ft_server();
	return(0);
}