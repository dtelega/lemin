/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:58:41 by dtelega           #+#    #+#             */
/*   Updated: 2017/04/22 19:58:42 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	push_ants(t_read *read)
{
	if (!way_is_found(read))
	{
		ft_putstr_fd("ERROR. Way is not found\n", 2);
		return ;
	}
	print_map(read);
}

int 	way_is_found(t_read *read)
{
	t_ways		*ways;

	ways = (t_ways *)malloc(1 * sizeof(ways));
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
	int 	i;
	int 	k;

	i = room(read, name);
	//printf("Start finding %s\n", name);
	//printf("index room = %d\n", i);
	ways->ways[ways->count_ways] =
		ft_strjoin_free(ways->ways[ways->count_ways], name);
	ways->ways[ways->count_ways] = 
		ft_strjoin_free(ways->ways[ways->count_ways], " ");
	if (i == 0)
	{
		ways->count_ways++;
		printf("END IS FOUND!\n");
		mo_memory_way(ways);
		ways->ways[ways->count_ways] =
			ft_strjoin_free(ways->ways[ways->count_ways],
				ways->ways[ways->count_ways - 1]);
		delete_last_room(ways);
		return ;
	}
	split = ft_strsplit(read->rooms[i]->name[1], ' ');
	k = 0;
	while (split[k])
	{
		if (!room_is_here(ways->ways[ways->count_ways], split[k]))
			start_finding(read, ways, split[k]);
		k++;
	}
	delete_last_room(ways);
	free_split(split);
}


/*   -------------------------------          HELP STUFF           ------------------------*/
/**/

void	free_split(char **split)
{
	int 	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int		room(t_read *read, char	*name)
{
	int 	i;

	i = 0;
	while (read->rooms[i] && ft_strcmp(read->rooms[i]->name[0], name))
		i++;
	return (i);
}

void 	delete_last_room(t_ways *ways)
{
	int		i;
	int		len;

	i = ways->count_ways;
	printf("delete last room\n");
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
/**/
/*   -------------------------------          HELP STUFF  ------------------------*/



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


void	print_map(t_read *read)
{
	int 	i;

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