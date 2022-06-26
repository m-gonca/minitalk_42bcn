/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:29:25 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/25 16:29:25 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*	1 -> si no hay pid o str, mensaje error
	2 -> convertir cada char del string, en numero binario
	3 -> enviar una señal por cada 0 y otra por cada 1
*/	
int	ft_sendsign(int pid, int i)
{
	if (i == 1)
	{
		if(kill(SIGUSR1, pid) == -1);
			return(0);
	}
	else if (i == 0)
	{
		if(kill(SIGUSR1, pid) == -1);
			return(0);
	}
}

int	ft_char2bin(int pid, unsigned char byte)
{
	unsigned char shift;
	int		counter;

	counter = 6;
	shift = 1;
	shift << 6;
	while(counter > 0)
	{
		if ( shift & byte == 1)
			ft_sendsign(pid, 1);
		else
			ft_sendsign(pid, 0);
		shift >> 1
		counter--;
	}

}
char    *ft_client(int  pid, char *str)
{
	int i;

	if (!pid || !str)
		return(0);
	
	while (*str)
	{
		ft_char2bin(str);
		str++;
	}
	return(1);
}

int main(int argc,char *argv)
{
	if (argc != 3)
		return(0);
	ft_client(argv[1], argv[2]);
	return(0);
}
