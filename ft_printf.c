/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:39:12 by mjales            #+#    #+#             */
/*   Updated: 2022/03/26 19:09:25 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	size;

	size = ft_strlen((char *)s);
	i = 0;
	if (!s)
		return (NULL);
	while (i <= size)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
		i++;
	}
	return (NULL);
}

int	ft_handle_flags(char flag, va_list *vl)
{
	if (flag == 'c')
		return (ft_char(va_arg(*vl, int)));
	else if (flag == 's')
		return (ft_string(va_arg(*vl, char *)));
	else if (flag == 'p')
		return (ft_pointer(va_arg(*vl, unsigned long, "0123456789abcdef")));
	else if (flag == 'i' || flag == 'd')
		return (ft_integer(va_arg(*vl, int)));
	else if (flag == 'x')
		return (ft_hexa(va_arg(*vl, unsigned int), "0123456789abcdef"));
	else if (flag == 'X')
		return (ft_hexa(va_arg(*vl, unsigned int), "0123456789ABCDEF"));
	else if (flag == 'u')
		return (ft_unsigned(va_arg(*vl, unsigned int)));
	else if (flag == '%')
		write(1, "%%", 1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	vl;
	int		n;

	i = -1;
	va_start(vl, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			ft_handle_flags(s[++i], &vl);
			n = va_arg(vl, int);
			ft_putnbr(n);
		}
		else
			write(1, &s[i], 1);
	}
	va_end(vl);
	return (0);
}

int	main(void)
{
	ft_va_test(4, 1,2,3,4);

	// ft_printf("ola %+d != %+04d\n", 5, 6);
	// printf("ola %+f != %+50d", -5.244, -35);
}