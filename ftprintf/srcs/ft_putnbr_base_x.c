/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:43:12 by arebelo           #+#    #+#             */
/*   Updated: 2022/01/26 20:11:48 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putnbr_base_x(unsigned long nbr, char *base,
			t_print *specs, unsigned int temp)
{
	unsigned long	size;

	size = ft_strlen(base);
	if (nbr >= size)
	{
		ft_putnbr_base_x(nbr / size, base, specs, temp);
		nbr = nbr % size;
	}	
	if (nbr < size)
	{
		if (specs->r_ident == 0 && specs->filler == '0')
			print_mfw(specs, temp);
		precision_putnbr(specs);
		specs->len += write (1, &base[nbr], 1);
	}
}
