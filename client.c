/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:29:25 by mogonzal          #+#    #+#             */
/*   Updated: 2022/07/08 13:07:52 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	ft_client(int pid, char *msg)
{
	int		counter;
	char	byte;

	while (*msg)
	{
		counter = 7;
		byte = *msg;
		while (counter >= 0)
		{
			if (byte >> counter & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			counter--;
			usleep(100);
		}
		msg++;
	}
}

void	ft_error(int pid, char *msg)
{
	if (!pid || !*msg)
	{
		write(1, "\aNULL pid or NULL msg\n", 22);
		exit(1);
	}
	else if (pid == -1)
	{
		write(1, "\aWrong pid\n", 11);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc != 3)
	{
		write(1, "\aWrong number of arguments\n", 27);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	ft_error(pid, msg);
	ft_client(pid, msg);
	return (0);
}
