/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:16:00 by lnarvaez          #+#    #+#             */
/*   Updated: 2022/04/25 13:16:18 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_nbrlen(long nb)
{
	long	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*ft_un_itoa(unsigned int n)
{
	long	nbr;
	char	*str;
	long	len;

	nbr = n;
	len = ft_nbrlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	str[len] = 0;
	while (nbr)
	{
		str[len - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

int	ft_printuns(unsigned int nbr)
{
	char	*n;
	int		len;

	len = 0;
	n = ft_un_itoa(nbr);
	len = ft_printstr(n);
	free (n);
	return (len);
}
