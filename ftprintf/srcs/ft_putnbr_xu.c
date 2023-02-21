/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_xu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:15:29 by arebelo           #+#    #+#             */
/*   Updated: 2022/01/26 20:08:05 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putnbr_xu(unsigned int n, int fd, t_print *specs, unsigned int temp)
{
	if (n >= 10)
	{
		ft_putnbr_xu(n / 10, fd, specs, temp);
		n = n % 10;
	}	
	if (n < 10)
	{
		if (specs->r_ident == 0 && specs->filler == '0')
			print_mfw(specs, temp);
		precision_putnbr(specs);
		n += 48;
		specs->len += write (fd, &n, 1);
	}
}
