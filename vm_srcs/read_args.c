/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:23:33 by ddosso-d          #+#    #+#             */
/*   Updated: 2018/02/01 14:18:04 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	special_flag(t_flag *flag, char **av, int i)
{
	if (av[i][1] != 'd' && av[i][1] != 's' && av[i][1] != 'v')
		return (error(ERROR_NON_EXISTENT_FLAG));
	if (!ft_isallnumber(av[i + 1]) || av[i + 1][0] == '-')
		return (error(ERROR_FLAG_NUMBER));
	if (av[i][1] == 'd')
	{
		flag->exist |= FLAG_D;
		flag->val_d = ft_atoi(av[i + 1]);
	}
	else if (av[i][1] == 's')
	{
		flag->exist |= FLAG_S;
		flag->val_s = ft_atoi(av[i + 1]);
	}
	else if (av[i][1] == 'v')
	{
		flag->exist |= FLAG_V;
		flag->val_v = ft_atoi(av[i + 1]);
	}
	return (1);
}

static int	read_flag(t_flag *flag, int ac, char **av, int *i)
{
	if (!ft_strcmp(av[*i], "--stealth"))
		flag->exist |= FLAG_STEALTH;
	else if (av[*i][1] == 'a')
		flag->exist |= FLAG_A;
	else if (av[*i][1] == 'b')
		flag->exist |= FLAG_B;
	else if (av[*i][1] == 'c')
		flag->exist |= FLAG_C;
	else
	{
		return (*i + 1 < ac ? special_flag(flag, av, (*i)++) :
			error(ERROR_NOT_FOLLOWING_FLAG));
	}
	return (1);
}

int			read_args(t_info *info, t_flag *flag, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac && av[i][0] == '-' &&
		(!av[i][2] || !ft_strcmp(av[i], "--stealth"))
		&& av[i][1] != 'n')
		if (!read_flag(flag, ac, av, &i))
			return (0);
	if (i == ac)
	{
		ft_putstr("Usage: ");
		ft_putstr(av[0]);
		ft_putendl(" [-d N -s N -v N | -b --stealth | -c --stealth] [-a] [-n] "
			"<champion1.cor> <...>");
		return (0);
	}
	if (!read_champs(info, ac - i, av + i))
		return (0);
	return (1);
}
