/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:46:34 by lnarvaez          #+#    #+#             */
/*   Updated: 2022/04/05 13:46:35 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
cambia un int a str
*/
#include <stdlib.h>

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

char	*ft_itoa(int n)
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
/*
int	main(void)
{
	int n = 0;
	printf("\nnum: %d\nstr: %s\n", n, ft_itoa(n));
}*/
