/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:23:06 by arebelo           #+#    #+#             */
/*   Updated: 2022/03/07 13:09:36 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include "../ftprintf/includes/libftprintf.h"
# include "../ftprintf/libft/libft.h"

typedef struct s_char
{
	int		nb;
	char	c;
	char	*str;
	int		client_pid;
}	t_char;

#endif
