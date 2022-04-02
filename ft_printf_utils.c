/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:58:53 by mjales            #+#    #+#             */
/*   Updated: 2022/04/02 16:45:13 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_string(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_integer(long long n, char *base)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		counter += write(1, "-", 1);
		n *= -1;
	}
	if (n >= (long long)ft_strlen(base))
		counter += ft_integer(n / ft_strlen(base), base);
	counter += write(1, &base[n % ft_strlen(base)], 1);
	return (counter);
}

int	ft_pointer(unsigned long n, char *base)
{
	int	counter;

	write(1, "0x", 2);
	counter = 0;
	if (n < 0)
	{
		counter += write(1, "-", 1);
		n *= -1;
	}
	if (n >= (unsigned long)ft_strlen(base))
		counter += ft_integer(n / ft_strlen(base), base);
	counter += write(1, &base[n % ft_strlen(base)], 1);
	return (counter + 2);
}
