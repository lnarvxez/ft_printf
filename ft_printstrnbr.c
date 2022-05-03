/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:57:51 by lnarvaez          #+#    #+#             */
/*   Updated: 2022/04/22 16:57:56 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write (1, &str[i++], 1);
	return (i);
}

int	ft_printnbr(int nbr)
{
	char	*n;
	int		len;

	len = 0;
	n = ft_itoa(nbr);
	len = ft_printstr(n);
	free (n);
	return (len);
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}
