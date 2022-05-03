/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:47:36 by lnarvaez          #+#    #+#             */
/*   Updated: 2022/04/22 17:47:37 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static void	ft_hexa(unsigned int num, const char format)
{
	char	*hex;
	char	hexa[8];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (format == 'X')
		hex = "0123456789ABCDEF";
	else if (format == 'x')
		hex = "0123456789abcdef";
	while (num >= 16)
	{
		hexa[i] = hex[num % 16];
		num /= 16;
		i++;
	}
	hexa[i] = hex[num];
	j = i;
	while (j >= 0)
	{
		write(1, &hexa[j], 1);
		j--;
	}
}

int	ft_printhexa(int nbr, const char format)
{
	if (nbr == 0)
		return (write (1, "0", 1));
	else
		ft_hexa(nbr, format);
	return (ft_hexa_len(nbr));
}
/*
int	main(void)
{
	int n;

	n = 160;
	int res = ft_hexa(n, 'x');
	printf("%i",  res);
	return (0);
}*/
