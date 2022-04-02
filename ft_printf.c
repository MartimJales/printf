/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:39:12 by mjales            #+#    #+#             */
/*   Updated: 2022/04/02 16:47:54 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (flag == 'i' || flag == 'd')
		return (ft_integer(va_arg(*vl, int), "0123456789"));
	else if (flag == 'x')
		return (ft_integer(va_arg(*vl, unsigned int), "0123456789abcdef"));
	else if (flag == 'X')
		return (ft_integer(va_arg(*vl, unsigned int), "0123456789ABCDEF"));
	else if (flag == 'u')
		return (ft_integer(va_arg(*vl, unsigned int), "0123456789"));
	else if (flag == 'p')
		return (ft_pointer(va_arg(*vl, unsigned long), "0123456789abcdef"));
	else if (flag == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		counter;
	va_list	vl;

	i = -1;
	counter = 0;
	va_start(vl, s);
	while (s[++i])
	{
		if (s[i] == '%')
			counter += ft_handle_flags(s[++i], &vl);
		else
			counter += write(1, &s[i], 1);
	}
	va_end(vl);
	return (counter);
}

// int	main(void)
// {	
// 	int		real;
// 	int		mine;
// 	char 	*s;
// 	int 	n;

// 	n = -32;
// 	s = NULL;
// 	// mine = ft_printf("ola %c != %c, %c\n", 'a', 'b', 'C');
// 	// real = printf("ola %c != %c, %c\n", 'a', 'b', 'C');
// 	// printf("Mine: %d\nReal: %d\n", mine, real);

// 	// mine = ft_printf("%s\n", "");
// 	// real = printf("%s\n", s);
// 	// printf("Mine: %d\nReal: %d\n", mine, real);

// 	mine = ft_printf("n = %%a\n");
// 	real = printf("n = %%a\n");
// 	printf("Mine: %d\nReal: %d\n", mine, real);
// }
