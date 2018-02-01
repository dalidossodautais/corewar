/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:46:03 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/23 15:26:03 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int	get_next_nb_champ(t_info *info)
{
	unsigned	i;
	int			res;

	i = 0;
	res = -1;
	while (i < info->nbr_player)
	{
		if (res == info->champs[i].nb_champ)
		{
			res--;
			i = 0;
		}
		else
			i++;
	}
	return (res);
}

static int	check_header(t_champ champ, int ret)
{
	if (ret != sizeof(t_header))
		return (error(ERROR_FILE_TOO_SHORT));
	if (champ.header.magic != COREWAR_EXEC_MAGIC)
		return (error(ERROR_BAD_HEADER));
	if (champ.header.prog_size > CHAMP_MAX_SIZE)
		return (error(ERROR_CHAMP_TOO_BIG));
	return (1);
}

static int	read_one_champ(char *file, t_info *info, int nb_champ)
{
	t_champ		champ;
	int			fd;
	int			ret;

	if (nb_champ > MAX_ARGS_NUMBER)
		return (error(ERROR_FLAG_N_NUMBER_TOO_BIG));
	if ((fd = open(file, O_RDONLY)) < 0)
		return (error(ERROR_OPEN));
	if ((ret = read(fd, &champ.header, sizeof(t_header))) < 0)
		return (error(ERROR_READ));
	ft_reversebyte(&champ.header.magic, sizeof(unsigned));
	ft_reversebyte(&champ.header.prog_size, sizeof(unsigned));
	if (!check_header(champ, ret))
		return (0);
	ft_bzero(champ.prog, sizeof(champ.prog));
	if ((ret = read(fd, champ.prog, champ.header.prog_size)) < 0)
		return (error(ERROR_READ));
	close(fd);
	if ((unsigned)ret != champ.header.prog_size)
		return (error(ERROR_BAD_HEADER));
	if (!(champ.nb_champ = (nb_champ ? nb_champ : get_next_nb_champ(info))))
		return (error(ERROR_NB_CHAMP_TAKEN));
	info->champs[info->nbr_player++] = champ;
	return (1);
}

static int	check_champs(t_info *info)
{
	unsigned	i;
	unsigned	j;

	i = 0;
	while (i < info->nbr_player)
	{
		if (info->champs[i].header.magic != COREWAR_EXEC_MAGIC)
			return (error(ERROR_BAD_HEADER));
		j = 0;
		while (j < info->nbr_player)
		{
			if (i != j && info->champs[i].nb_champ == info->champs[j].nb_champ)
				return (error(ERROR_NB_CHAMP_TAKEN));
			j++;
		}
		i++;
	}
	return (1);
}

int			read_champs(t_info *info, int ac, char **av)
{
	int	i;

	i = -1;
	while (++i < ac)
	{
		if (info->nbr_player >= MAX_PLAYERS)
			return (error(ERROR_TOO_MUCH_PLAYERS));
		if (ft_strequ(av[i], "-n"))
		{
			if (!(++i < ac) || !ft_isallnumber(av[i]))
				return (error(ERROR_FLAG_NUMBER));
			if (!(read_one_champ(av[i + 1], info, ft_atoi(av[i]))))
				return (0);
			i++;
		}
		else
		{
			if (!(read_one_champ(av[i], info, 0)))
				return (0);
		}
		if (!(check_champs(info)))
			return (0);
	}
	return (1);
}
