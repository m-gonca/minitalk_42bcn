/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:29:36 by mogonzal          #+#    #+#             */
/*   Updated: 2022/07/08 12:51:24 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	ft_answer(int sign)
{
	static int				i = 0;
	static unsigned char	byte = 0;
	int						check;

	check = 0;
	if (sign == SIGUSR2)
		check = 1;
	byte = byte | check;
	if (++i == 8)
	{
		i = 0;
		write(1, &byte, 1);
		byte = 0;
	}
	else
		byte <<= 1;
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, &ft_answer);
	signal(SIGUSR2, &ft_answer);
	while (1)
		pause();
	return (0);
}
