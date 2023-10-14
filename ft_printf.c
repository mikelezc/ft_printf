/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:36:14 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/14 13:42:32 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_typearg(va_list argmnts, const char type, int *length)
{
	if (type == 'c')
		ft_putcharl(va_arg(argmnts, int), length);
	else if (type == 's')
		ft_putstrl(va_arg(argmnts, char *), length);
	else if (type == 'd' || type == 'i')
		ft_putnbrl(va_arg(argmnts, int), length);
	else if (type == 'u')
		ft_putunsl(va_arg(argmnts, unsigned int), length);
	else if (type == 'x')
		ft_puthexal(va_arg(argmnts, unsigned int), "0123456789abcdef", length);
	else if (type == 'X')
		ft_puthexal(va_arg(argmnts, unsigned int), "0123456789ABCDEFG", length);
	else if (type == '%')
		ft_putcharl('%', length);
	else if (type == 'p')
	{
		ft_putstrl("0x", length);
		if (*length != -1)
			ft_puthexal(va_arg(argmnts, unsigned long long),
				"0123456789abcdef", length);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	argmnts;

	i = 0;
	length = 0;
	va_start(argmnts, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_typearg(argmnts, str[i + 1], &length);
			i++;
		}
		else
			ft_putcharl(str[i], &length);
		i++;
		if (length < 0)
			return (-1);
	}
	va_end(argmnts);
	return (length);
}

/*
int	main(void)
{
	int				a;
	char			*pointer;
	unsigned int	b;
	unsigned int	c;
	int				x;
	char			*string;

	a = ft_printf("Probando string: buenos días, probando función\n");
	ft_printf("Cantidad de caracteres del string devuelto por return: %d\n", a);
	ft_printf("Prueba de un char %c\n", 'M');

	printf(" 1                   Prueba de un porcentaje %%%\n");
	ft_printf(" 2             Prueba de un porcentaje %%%");
	printf("\n");
	ft_printf("Dirección puntero: %p\n", pointer);
	printf("Dirección puntero con printf para comparar%p\n", pointer);
	ft_printf("Prueba de impresión de enteros %d, %i\n", a, a);
	b = 23456;
	c = -23456;
	ft_printf("Prueba de impresión de unsigned int: %u\n", b);
	ft_printf("Prueba de impresión de unsigned int: %u\n", c);
	x = 3488989;
	ft_printf("Prueba de impresión de un hexadecimal: %x\n", x);
	ft_printf("Prueba de impresión de un hexadecimal: %X\n", x);
	ft_printf("Pos ya estaría!", x);
	string = "cadena";
	ft_printf("prueba cadena: %s", x);
	//printf("prueba cadena: %s", x);
	return (0);
}*/