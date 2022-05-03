/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:46:05 by lnarvaez          #+#    #+#             */
/*   Updated: 2022/04/22 16:46:07 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_formatos(va_list args, const char format)
{
	int	ret;

	ret = 0;
	if (format == 'c')
		ret += ft_putchar(va_arg(args, int));
	if (format == 's')
		ret += ft_printstr(va_arg(args, char *));
	if (format == 'd' || format == 'i')
		ret += ft_printnbr(va_arg(args, int));
	if (format == 'p')
		ret += ft_printptr(va_arg(args, unsigned long long));
	if (format == 'u')
		ret += ft_printuns(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		ret += ft_printhexa(va_arg(args, int), format);
	if (format == '%')
		ret += ft_percent();
	return (ret);
}

int	ft_printf(char const	*str, ...)
{
	int		i;
	int		retorno;
	va_list	args;

	i = 0;
	retorno = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			retorno += ft_formatos(args, str[i + 1]);
			i++;
		}
		else
			retorno += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (retorno);
}
/*
int	main(void)
{
	void	*ptr;
	ft_printf("-----* ft_printf *-----");
	ft_printf("\n");
	ft_printf("\nCaracter        : %c", 'L');
	ft_printf("\nCadena          : %s", "Hola soy Leo");
	ft_printf("\nPuntero         : %p", ptr);
	ft_printf("\nNumero          : %d", -42);
	ft_printf("\nEntero(10)      : %i", 42);
	ft_printf("\nDecimal(10)     : %u", 42);
	ft_printf("\nHexadecimal (m) : %x", 42);
	ft_printf("\nHexadecimal (M) : %X", 42);
	ft_printf("\nPorcentaje      : %%");
	ft_printf("\n");
	printf("-----* printf *-----");
	printf("\nCaracter        : %c", 'L');
	printf("\nCadena          : %s", "Hola soy Leo");
	printf("\nPuntero         : %p", ptr);
	printf("\nNumero          : %d", -42);
	printf("\nEntero(10)      : %i", 42);
	printf("\nDecimal(10)     : %u", 42);
	printf("\nHexadecimal (m) : %x", 42);
	printf("\nHexadecimal (M) : %X", 42);
	printf("\nPorcentaje      : %%");
	return (0);
}*/
