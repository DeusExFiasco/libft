/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik <kixik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:01:32 by kixik             #+#    #+#             */
/*   Updated: 2026/01/30 18:55:07 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_and_check(int fd, const char c, int *retval)
{
	if (write(fd, &c, 1) == -1)
	{
		*retval = -1;
		return ;
	}
	(*retval)++;
}

static void	handle_format(int fd, const char **str, va_list args, int *retval)
{
	if (**str == 'c')
		handle_character(fd, va_arg(args, int), retval);
	else if (**str == 's')
		handle_string(fd, va_arg(args, char *), retval);
	else if (**str == 'p')
		handle_pointer(fd, va_arg(args, void *), retval);
	else if (**str == 'd' || **str == 'i')
		handle_integer(fd, va_arg(args, int), retval);
	else if (**str == 'u')
		handle_unsigned_decimal(fd, va_arg(args, int), retval);
	else if (**str == 'x')
		handle_hex_lower(fd, va_arg(args, unsigned long), retval);
	else if (**str == 'X')
		handle_hex_upper(fd, va_arg(args, unsigned long), retval);
	else if (**str == '%')
		write_and_check(fd, '%', retval);
	else
		*retval = -2;
}

static int	*format_parse(int fd, const char *str, va_list args, int *retval)
{
	while (*str)
	{
		if (*str == '%' && *++str)
		{
			handle_format(fd, &str, args, retval);
			if (*retval == -1 || *retval == -2)
				return (retval);
		}
		else
		{
			if (write(fd, str, 1) == -1)
			{
				*retval = -1;
				return (retval);
			}
			(*retval)++;
		}
		str++;
	}
	return (retval);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		retval;

	retval = 0;
	va_start(args, str);
	retval = *format_parse(STDOUT_FILENO, str, args, &retval);
	va_end(args);
	return (retval);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		retval;

	retval = 0;
	va_start(args, str);
	retval = *format_parse(fd, str, args, &retval);
	va_end(args);
	return (retval);
}
