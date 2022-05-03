/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:41:01 by lnarvaez          #+#    #+#             */
/*   Updated: 2022/04/22 16:41:03 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(char const	*str, ...);
int		ft_printstr(char *str);
int		ft_printnbr(int nbr);
int		ft_printptr(unsigned long long nbr);
int		ft_printhexa(int nbr, const char format);
int		ft_percent(void);
int		ft_printuns(unsigned int nbr);
char	*ft_itoa(int n);

#endif
