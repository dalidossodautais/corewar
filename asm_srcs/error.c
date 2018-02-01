/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:51:06 by jlereffa          #+#    #+#             */
/*   Updated: 2017/09/06 15:53:45 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		error(char *err_msg)
{
	ft_putendl(err_msg);
	return (0);
}