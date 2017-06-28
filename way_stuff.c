/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:51:16 by dtelega           #+#    #+#             */
/*   Updated: 2017/06/03 17:51:17 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		way_is_found(t_read *read)
{
	t_ways		*ways;

	ways = (t_ways *)malloc(1 * sizeof(t_ways));
	ways->ways = (char **)malloc(1 * sizeof(read->ways));
	ways->ways[0] = ft_strnew(0);
	ways->count_ways = 0;
	read->ways = ways;
	start_finding(read, ways, read->rooms[1]->name[0]);
	if (ways->ways[0][0] == '\0')
		return (0);
	return (1);
}

void	start_finding(t_read *read, t_ways *ways, char *name)
{
	char	**split;
	int		i;
	int		k;

	i = room(read, name);
	ways->ways[ways->count_ways] =
		ft_strjoin_free(ways->ways[ways->count_ways], name);
	ways->ways[ways->count_ways] =
		ft_strjoin_free(ways->ways[ways->count_ways], " ");
	if ((k = -1) == -1 && i == 0)
	{
		ways->count_ways++;
		mo_memory_way(ways);
		ways->ways[ways->count_ways] =
			ft_strjoin_free(ways->ways[ways->count_ways],
				ways->ways[ways->count_ways - 1]);
		delete_last_room(ways);
		return ;
	}
	split = ft_strsplit(read->rooms[i]->name[1], ' ');
	while (split[++k] && read->ways->count_ways < 30000)
		if (!room_is_here(ways->ways[ways->count_ways], split[k]))
			start_finding(read, ways, split[k]);
	delete_last_room(ways);
	free_split(split);
}
