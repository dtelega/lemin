/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:47:06 by dtelega           #+#    #+#             */
/*   Updated: 2017/06/03 16:49:34 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		room(t_read *read, char *name)
{
	int		i;

	i = 0;
	while (read->rooms[i] && ft_strcmp(read->rooms[i]->name[0], name))
		i++;
	return (i);
}

void	delete_last_room(t_ways *ways)
{
	int		i;
	int		len;

	i = ways->count_ways;
	len = ft_strlen(ways->ways[i]);
	ways->ways[i][len - 1] = '\0';
	while (ways->ways[i][len - 1] != ' ' && len - 1 >= 0)
	{
		ways->ways[i][len - 1] = '\0';
		len--;
	}
}

void	mo_memory_way(t_ways *ways)
{
	int		i;
	char	**new_way;

	i = 0;
	while (ways->ways[i])
		i++;
	new_way = (char **)malloc(++i * sizeof(new_way));
	i = 0;
	while (i < ways->count_ways)
	{
		new_way[i] = ft_strdup(ways->ways[i]);
		free(ways->ways[i]);
		i++;
	}
	free(ways->ways);
	new_way[i] = ft_strnew(0);
	ways->ways = new_way;
}

void	print_map(t_read *read)
{
	int		i;

	i = 1;
	ft_putnbr(read->ants);
	ft_putstr("\n");
	while (read->map[i])
	{
		if (read->map[i][0] == '#' && read->map[i][1] == '#'
			&& ft_strcmp(read->map[i], "##start") &&
			ft_strcmp(read->map[i], "##end"))
			i++;
		else
		{
			ft_putstr(read->map[i++]);
			ft_putstr("\n");
		}
	}
	ft_putstr("\n");
}

int		room_is_here(char *way, char *name)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(way, ' ');
	while (split[i])
	{
		if (!ft_strcmp(split[i], name))
		{
			i = -1;
			while (split[++i])
				free(split[i]);
			free(split);
			return (1);
		}
		i++;
	}
	free_split(split);
	return (0);
}
