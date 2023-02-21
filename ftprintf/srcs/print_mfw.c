/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mfw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:55:51 by arebelo           #+#    #+#             */
/*   Updated: 2022/01/31 12:46:51 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_mfw(t_print *specs, unsigned int i)
{
	if (specs->percent == 2)
		specs->filler = '0';
	while (specs->mfw > i)
	{
		specs->len += write(1, &specs->filler, 1);
		specs->mfw--;
	}
}
