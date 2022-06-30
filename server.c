/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:29:36 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/30 19:15:58 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	ft_answer(int sign)
{
	static unsigned char	byte = 0;
	static unsigned char	shift = 1 << 7;
	static int				counter = 7;

	if (counter >= 0)
	{
		if (sign == SIGUSR1)
		{
			byte = shift ^ byte;
			shift = shift >> 1;
		}
		else if (sign == SIGUSR2)
			shift = shift >> 1;
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
	if (signal(SIGUSR1, &ft_answer) == SIG_ERR)
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
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	ft_server();
	return (0);
}
