/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:29:25 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/29 19:22:21 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

/*	1 -> si no hay pid o str, mensaje error
	2 -> convertir cada char del string, en numero binario
	3 -> enviar una señal por cada 0 y otra por cada 1
*/	
int	ft_sendsign(int pid, int i)
{
	if (i == 1)
	{
		//ft_printf("he entrado en mandar senal 1\n");
		if(kill(pid, SIGUSR1) == 1)
		{
			ft_printf("Client Error1\n");
			exit(1);
		}
	}
	else if (i == 0)
	{
		//ft_printf("he entrado en mandar senal 0\n");
		if(kill(pid, SIGUSR2) == 1)
		{
			ft_printf("Client Error2\n");
			exit(1);
		}
	}
	return (0);
}

int	ft_char2bin(int pid, unsigned char byte)
{
	unsigned char shift = 1 << 7;
	int		counter = 7;
	
	while (counter >= 0)
	{
		if ((shift & byte) == shift)
		{
			if (ft_sendsign(pid, 1) == 1)
				exit (1);
		}
		else
		{
			if (ft_sendsign(pid, 0) == 1)
				exit (1);
		}
		shift = shift >> 1;
		counter--;
		usleep(1250);
	}

	return (0);
}

char    ft_client(int  pid, char *str_to_send)
{
	unsigned char	char_to_send;
	
	if (!pid || !str_to_send)
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
	return(0);
}

int main(int argc, char **argv)
{
	int		pid;
	char	*str_to_send;
	
	if (argc != 3)
	{
		ft_printf("Missing arguments\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	str_to_send = argv[2];
	ft_client(pid, str_to_send);
	return(0);
}
