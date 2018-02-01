/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_process_nb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:34:03 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/08 12:34:58 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

unsigned	get_next_process_nb(void)
{
	static unsigned	last_nb = 0;

	last_nb++;
	return (last_nb);
}
