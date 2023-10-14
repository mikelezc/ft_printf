/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:11:11 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/14 13:41:32 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharl(char a, int *length)
{
	if (write(1, &a, 1) == -1)
		*length = -1;
	else
		*length = *length +1;
}

void	ft_putstrl(char *str, int *length)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstrl("(null)", length);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putcharl(str[i], length);
		if (*length == -1)
			return ;
		i++;
	}
}
