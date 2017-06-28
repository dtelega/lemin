/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:25:52 by dtelega           #+#    #+#             */
/*   Updated: 2017/04/21 15:25:53 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_nb_rooms(t_read *read, int i)
{
	int		count;

	count = 0;
	while (read->map[i] && !ft_strchr(read->map[i], '-'))
	{
		if (read->map[i][0] != '#')
			count++;
		i++;
	}
	return (count);
}

void	get_rooms(t_read *read)
{
	int		i;
	int		count;

	count = get_nb_rooms(read, 1);
	read->count_room = 2;
	i = 0;
	read->e = 0;
	read->s = 0;
	while (read->map[++i])
	{
		if (!ft_strcmp(read->map[i], "##start") && (++read->s) != 0)
			get_room(read, ++i, 1);
		else if (!ft_strcmp(read->map[i], "##end") && (++read->e) != 0)
			get_room(read, ++i, 0);
		else if (read->map[i][0] == '#')
			;
		else if (!ft_strchr(read->map[i], '-'))
			get_room(read, i, 2);
	}
	check_rooms(read);
}

void	get_room(t_read *read, int i, int type)
{
	char	**split;
	t_room	*room;

	room = create_room();
	split = ft_strsplit(read->map[i], ' ');
	if (!split[0] || !split[1] || !split[2] || split[3])
		invalid_room(read, room);
	room->name[0] = ft_strjoin_free(room->name[0], split[0]);
	if (!(room->x = ft_atoi(split[1])) && ft_strcmp(split[1], "0"))
		invalid_room(read, room);
	if (!(room->y = ft_atoi(split[2])) && ft_strcmp(split[2], "0"))
		invalid_room(read, room);
	if (room->name[0][0] == 'L')
		invalid_room(read, room);
	if (type > 1)
		type = read->count_room++;
	else if (type == 0 && read->e != 1)
		free_room(read, 0);
	else if (type == 1 && read->s != 1)
		free_room(read, 1);
	read->rooms[type] = room;
	free_split(split);
}

void	check_rooms(t_read *read)
{
	int		i;
	int		k;
	int		count;

	count = read->count_room;
	i = 0;
	while (--count != 0)
	{
		k = read->count_room;
		while (--k != 0)
		{
			if ((!ft_strcmp(read->rooms[k]->name[0], read->rooms[i]->name[0]) &&
				i != k) || (read->rooms[k]->x == read->rooms[i]->x &&
				read->rooms[k]->y == read->rooms[i]->y && i != k))
			{
				ft_putstr_fd("ERROR! Invalid room\n", 2);
				exit(0);
			}
		}
		i++;
	}
}

t_room	*create_room(void)
{
	t_room	*room;

	room = (t_room *)malloc(2 * sizeof(room));
	room->name = (char **)malloc(2 * sizeof(room->name));
	room->name[0] = ft_strnew(0);
	room->name[1] = ft_strnew(0);
	return (room);
}
