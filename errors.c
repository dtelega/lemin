/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 14:59:35 by dtelega           #+#    #+#             */
/*   Updated: 2017/04/22 14:59:55 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	invalid_room(t_read *read, t_room *room)
{
	ft_putstr_fd("Invalid room\n", 2);
	clear_read(read);
	free(room->name[0]);
	free(room->name[1]);
	free(room->name);
	free(room);
	while(1){}
	exit(0);
}

void	check_st_en(t_read *read)
{
	int		i;

	i = 0;
	if (!exist(read, "##start") || !exist(read, "##end"))
	{
		if (exist(read, "##start") == 0)
			ft_putstr_fd("Start is missed!\n", 2);
		if (exist(read, "##end") == 0)
			ft_putstr_fd("End is missed!\n", 2);
		clear_read(read);
		exit(1);
	}
}

int		exist(t_read *read, char *name)
{
	int		i;

	i = 0;
	while (read->map[++i])
		if (!ft_strcmp(read->map[i], name))
			return (1);
	return (0);
}

void	clear_rooms(t_read *read)
{
	int		i;
	int		count;

	printf("Open clear_rooms\n");
	i = 0;
	count = get_nb_rooms(read, 1);
	while (count-- != 0)
	{
		free(read->rooms[i]->name[0]);
		free(read->rooms[i]->name[1]);
		free(read->rooms[i]->name);
		free(read->rooms[i]);
		i++;
	}
	free(read->rooms);
}

void	clear_read(t_read *read)
{
	printf("Open clear_read\n");
	free_split(read->map);
	free_split(read->ways);
}
