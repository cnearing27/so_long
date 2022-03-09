/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:11:45 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/09 15:24:24 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putnbr_u(unsigned int nb)
{
	char		p;
	static int	count;

	count = 0;
	if (nb >= 10)
		ft_putnbr_u(nb / 10);
	p = (nb % 10) + '0';
	write(1, &p, 1);
	count++;
	return (count);
}

int	ft_putnbr(int nb)
{
	static int	count;

	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		count += ft_putnbr_u(-nb);
		count++;
	}
	else
		count += ft_putnbr_u(nb);
	return (count);
}

void	ft_printf(const char *format, int num)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			ft_putnbr(num);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
}
