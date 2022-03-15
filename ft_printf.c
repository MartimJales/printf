/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:39:12 by mjales            #+#    #+#             */
/*   Updated: 2022/03/15 20:04:34 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
			if (ft_strchr("cspdiuxX-+# 0", s[++i]))
				write(1, "!", 1);
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
	ft_printf("ola %+d != %+04d\n", 5, 6);
	printf("ola %+f != %+50d", -5.244, -35);
}
