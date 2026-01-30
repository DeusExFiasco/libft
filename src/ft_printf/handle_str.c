/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:44:34 by kixik             #+#    #+#             */
/*   Updated: 2024/10/17 18:12:47 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_string(int fd, char *str, int *retval)
{
	if (!str)
	{
		if (write(fd, "(null)", 6) == -1)
		{
			*retval = -1;
			return ;
		}
		(*retval) += 6;
		return ;
	}
	while (*str)
	{
		if (write(fd, str, 1) == -1)
		{
			*retval = -1;
			return ;
		}
		str++;
		(*retval)++;
	}
}
