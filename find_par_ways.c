/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_par_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 17:13:58 by dtelega           #+#    #+#             */
/*   Updated: 2017/06/03 17:03:16 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		find_short_way(t_read *read)
{
	int		i;
	int		len;
	int		res_i;
	int		check;

	i = -1;
	check = 0;
	len = 2147483647;
	res_i = 0;
	while (read->ways->ways[++i][0] != '\0')
		if (len >= check_len_way(read->ways->ways[i]) &&
			read->ways->ways[i][0] != '#' && non_par(read, read->ways->ways[i]))
		{
			res_i = i;
			check = 1;
			len = check_len_way(read->ways->ways[i]);
		}
	if (check == 0)
		return (-1);
	return (res_i);
}

int		check_len_way(char *way)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (way[i])
	{
		if (way[i] == ' ')
			len++;
		i++;
	}
	return (len);
}

void	find_par_ways(t_read *read)
{
	read->par_ways = (t_ways *)malloc(1 * sizeof(read->par_ways));
	read->par_ways->ways = (char **)malloc(4 * sizeof(read->par_ways->ways));
	read->par_ways->ways[0] = ft_strdup(read->ways->ways[find_short_way(read)]);
	read->ways->ways[find_short_way(read)][0] = '#';
	read->par_ways->ways[1] = ft_strdup(read->ways->ways[find_short_way(read)]);
	read->ways->ways[find_short_way(read)][0] = '#';
	read->par_ways->ways[2] = ft_strdup(read->ways->ways[find_short_way(read)]);
	read->ways->ways[find_short_way(read)][0] = '#';
	read->par_ways->ways[3] = ft_strdup(read->ways->ways[find_short_way(read)]);
	read->ways->ways[find_short_way(read)][0] = '#';
	mo_memory_way(read->par_ways);
}

int		non_par(t_read *read, char *way)
{
	int		i;

	i = 0;
	while (i != read->par_ways->count_ways)
	{
		if (!check_par(read->par_ways->ways[i], way,
			check_len_way(read->par_ways->ways[i]), check_len_way(way)))
			return (0);
		i++;
	}
	return (1);
}

int		check_par(char *way1, char *way2, int count1, int count2)
{
	char	**split1;
	char	**split2;
	int		m;
	int		k;

	if (!ft_strcmp(way1, way2))
		return (0);
	count1 = check_len_way(way1);
	count2 = check_len_way(way2);
	if ((k = 0) != 0 || count2 == 2)
		return (1);
	split1 = ft_strsplit(way1, ' ');
	split2 = ft_strsplit(way2, ' ');
	while (++k != count1 - 1 && (m = 0) == 0)
		while (++m != count2 - 1)
			if (!ft_strcmp(split1[k], split2[m]))
			{
				free_split(split1);
				free_split(split2);
				return (0);
			}
	free_split(split1);
	free_split(split2);
	return (1);
}
