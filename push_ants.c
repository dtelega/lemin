/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:58:41 by dtelega           #+#    #+#             */
/*   Updated: 2017/06/03 17:49:58 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	push_ants(t_read *read)
{
	int i;

	if (!way_is_found(read))
	{
		ft_putstr_fd("ERROR. Way is not found\n", 2);
		exit(0);
	}
	read->par_ways = (t_ways *)malloc(1 * sizeof(read->par_ways));
	read->par_ways->ways = (char **)malloc(read->ways->count_ways *
											sizeof(read->par_ways->ways));
	read->par_ways->count_ways = 0;
	while ((i = find_short_way(read)) != -1)
	{
		read->par_ways->ways[read->par_ways->count_ways++] =
					ft_strdup(read->ways->ways[i]);
		read->ways->ways[i][0] = '#';
	}
	print_map(read);
	push(read);
}

void	push(t_read *read)
{
	int		i;

	i = -1;
	while (++i != read->count_room)
	{
		read->rooms[i]->x = 0;
		read->rooms[i]->y = 0;
	}
	read->rooms[1]->x += 1;
	read->rooms[1]->y += 1;
	read->nb_ant = 1;
	while (read->rooms[0]->y < read->ants)
		push_in_next(read);
}

void	push_in_next(t_read *read)
{
	int i;

	i = -1;
	read->rooms[1]->y = 1;
	while (++i < read->par_ways->count_ways)
	{
		read->rooms[1]->y = read->nb_ant;
		push_this_way(read, read->par_ways->ways[i]);
	}
	ft_putstr("\n");
}

void	push_this_way(t_read *read, char *way)
{
	char	**split;
	int		i;

	split = ft_strsplit(way, ' ');
	i = 0;
	while (split[i])
		i++;
	while (--i != 0)
		if (read->rooms[room(read, split[i])]->x == 0 &&
			read->rooms[room(read, split[i - 1])]->x == 1)
		{
			if (read->rooms[room(read, split[i - 1])]->y > read->ants)
				break ;
			move(read, split, i);
		}
	free_split(split);
}

void	move(t_read *read, char **split, int i)
{
	ft_putstr("L");
	ft_putnbr(read->rooms[room(read, split[i - 1])]->y);
	ft_putstr("-");
	ft_putstr(split[i]);
	ft_putstr(" ");
	read->rooms[room(read, split[i])]->x = 1;
	read->rooms[room(read, split[i - 1])]->x = 0;
	if (room(read, split[i]) != 0)
		read->rooms[room(read, split[i])]->y =
			read->rooms[room(read, split[i - 1])]->y;
	else
		read->rooms[0]->y++;
	if (room(read, split[i - 1]) == 1)
		read->nb_ant += 1;
	if (room(read, split[i]) == 0)
		read->rooms[0]->x = 0;
	if (read->rooms[room(read, split[i - 1])]->y >= read->ants)
	{
		read->rooms[1]->x = 0;
		read->rooms[1]->y = 0;
	}
	else
		read->rooms[1]->x = 1;
}
