/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:29:36 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/29 19:21:18 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

// int	ft_prueba(int pid, unsigned char byte)
// {
// 	unsigned char shift = 1 << 7;
// 	int		counter = 7;
	
// 	(void)pid;
// 	while(counter >= 0)
// 	{
// 		if ((shift & byte) == shift)
// 		{
// 			write(1, "1\n", 2);
// 		}
// 		else
// 		{
// 			write(1, "0\n", 2);
// 		}
// 		shift = shift >> 1;
// 		counter--;
// 		usleep(350);
// 	}

// 	return (0);
// }

void show_pid()
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
}

void ft_answer(int sign)
{
	static unsigned char	byte = 0;
	static unsigned char	shift = 1 << 7;
	static int 				counter = 7;
	
	if (counter >= 0)
	{
		if (sign == SIGUSR1)
		{
			//ft_printf("llego senal de 1\n");
			byte = shift ^ byte;
			shift = shift >> 1;
		}
		if (sign == SIGUSR2)
		{
			//ft_printf("llego senal de 0\n");
			shift = shift >> 1;
		}
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



int ft_server(void)
{
	// signal(SIGUSR1,  &ft_answer);
	// 	ft_printf("he recibido la senal 1");
	// signal(SIGUSR2, &ft_answer);
	// 	ft_printf("he recibido la senal 1");
	if (signal(SIGUSR1,  &ft_answer) == SIG_ERR)
    {
      	ft_printf("Error\n");
      	exit(1);
    }
	else if (signal(SIGUSR2, &ft_answer) == SIG_ERR)
    {
		ft_printf("Error\n");
			exit(1);
	}
	while (1)
		pause();
	return (0);
}

int main()
{
	show_pid();
	ft_server();
	return(0);
}