/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:29:25 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/30 19:05:35 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	checker(int sign)
{
	if (sign != SIGUSR1)
		exit(1);
	ft_printf("he confirmado un bit\n");
}

static void	ft_char2bin(int pid, unsigned char byte)
{
	unsigned char	shift;
	int				counter;

	counter = 7;
	shift = 1 << 7;
	while (counter >= 0)
	{
		if ((shift & byte) == shift)
		{
			if (kill(pid, SIGUSR1) == 1)
				exit(1);
		}
		else if (!((shift & byte) == shift))
		{
			if (kill(pid, SIGUSR2) == 1)
				exit(1);
		}
		signal(SIGUSR1, &checker);
		shift = shift >> 1;
		counter--;
		usleep(100);
	}
}

static void	ft_client(int pid, char *str_to_send)
{
	unsigned char	char_to_send;

	if (!pid || !*str_to_send)
	{
		ft_printf("NULL pid or NULL str\n");
		exit(1);
	}
	while (*str_to_send)
	{
		char_to_send = *str_to_send;
		ft_char2bin(pid, char_to_send);
		str_to_send++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str_to_send;

	if (argc != 3)
	{
		ft_printf("Wrong number of arguments\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1)
	{
		ft_printf("Wrong pid\n");
		exit(1);
	}
	str_to_send = argv[2];
	ft_client(pid, str_to_send);
	return (0);
}
