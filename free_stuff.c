/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:58:02 by dtelega           #+#    #+#             */
/*   Updated: 2017/05/21 16:58:02 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	clear_rooms(t_read *read)
{
	int		i;
	int		count;

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
	free_split(read->map);
}

void	free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
