/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:13:32 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/17 18:31:40 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_format(char *ptr, va_list argptr);
int	ft_printchar(char c);
int	ft_printstr(char *s);
int	ft_printptr(void *addr);
int	ft_printint(int n);
int	ft_printunint(unsigned int n);
int	ft_printhexa(unsigned int n);
int	ft_printhexacaps(unsigned int n);

#endif
