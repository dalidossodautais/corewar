/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:37:00 by jlereffa          #+#    #+#             */
/*   Updated: 2017/09/18 12:41:19 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int	main(int ac, char **av)
{
	int		i;

	if (ac < 2)
		return (error(ERROR_NOFILE));
	i = 0;
	while (++i < ac)
		if (!compile(av[i]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
