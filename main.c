/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:22:55 by dtelega           #+#    #+#             */
/*   Updated: 2017/04/21 15:22:59 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	lemin(int i)
{
	t_read	*read;

	read = (t_read *)malloc(sizeof(t_read));
	read_map(read);
	check_st_en(read);
	get_nb_of_ants(read);
	read->rooms = (t_room **)malloc((get_nb_rooms(read, 1) + 1) *
						sizeof(read->rooms));
	get_rooms(read);
	get_links(read);
	push_ants(read);
	while (read->ways->ways[++i][0] != '\0')
		free(read->ways->ways[i]);
	free(read->ways->ways[i]);
	free(read->ways->ways);
	free(read->ways);
	i = -1;
	while (++i < read->par_ways->count_ways)
		free(read->par_ways->ways[i]);
	free(read->par_ways->ways);
	free(read->par_ways);
	clear_rooms(read);
	clear_read(read);
	free(read);
}

int		main(int ac, char **av)
{
	av[0] = av[0] + 1 - 1;
	if (ac != 1)
	{
		ft_putstr_fd("ERROR! Try ./lemin < map\n", 2);
		return (0);
	}
	else
		lemin(-1);
	return (1);
}
