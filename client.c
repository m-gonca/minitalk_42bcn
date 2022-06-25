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

char    *ft_client(int  pid, char *str)
{

}

int main(int argc,char *argv)
{
	if (argc <= 1)
		return(0);
	else
	{
		ft_server();
		ft_client(pid, argv[1]);
	return(0);
}
