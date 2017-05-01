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

void	lemin(void)
{
	t_read	*read;

	read = (t_read *)malloc(sizeof(read));
	
	read_map(read);
	check_st_en(read);
	get_nb_of_ants(read);
	read->rooms = (t_room **)malloc(get_nb_rooms(read, 1) * sizeof(read->rooms));
	get_rooms(read);
	get_links(read);
	push_ants(read);


//***********************************************************
	int i;
	i = 0;
	printf("RESULT\n");
	int count = get_nb_rooms(read, 1);
	while (count-- != 0)
	{
		printf("name[%i] - %s, (%d, %d) links->%s\n", i, read->rooms[i]->name[0], read->rooms[i]->x, read->rooms[i]->y, read->rooms[i]->name[1]);
		i++;
	}
	i = 0;
	printf("count ways = %d\n", read->ways->count_ways);
	while (read->ways->ways[i][0] != '\0')
	{
		printf("way %i = [%s]\n", i, read->ways->ways[i]);
		i++;
	}

// ****************************************************************


	clear_rooms(read);
	clear_read(read);
	free(read);
	
}

int		main(int ac, char **av)
{
	//av[0] = av[0] + 1 - 1;
	if (ac != 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	else
		lemin();
	printf("check leaks\n"); while(1){}
	return (1);
}
