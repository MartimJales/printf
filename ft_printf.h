/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:13:53 by mjales            #+#    #+#             */
/*   Updated: 2022/04/02 16:48:03 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_handle_flags(char flag, va_list *vl);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
int		ft_char(char c);
int		ft_string(char *s);
int		ft_integer(long long n, char *base);
int		ft_pointer(unsigned long n, char *base);

#endif