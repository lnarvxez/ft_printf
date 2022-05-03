/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:25:12 by lnarvaez          #+#    #+#             */
/*   Updated: 2022/04/25 14:25:13 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

static void	ft_putptr(unsigned long long num)
{
	char	*hex;
	char	hexa[16];
	int		i;
	int		j;

	i = 0;
	j = 0;
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

int	ft_printptr(unsigned long long ptr)
{
	int	res;

	res = 0;
	res += write(1, "0x", 2);
	if (ptr == 0)
		res += write (1, "0", 1);
	else
	{
		ft_putptr(ptr);
		res += ft_ptr_len(ptr);
	}
	return (res);
}
