/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:10:48 by dtelega           #+#    #+#             */
/*   Updated: 2017/04/22 16:10:49 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_links(t_read *read)
{
	int		i;
	char	**split;

	i = 0;
	while (read->map[i] && !ft_strchr(read->map[i], '-'))
		i++;
	while (read->map[i])
	{
		if (read->map[i][0] != '#')
		{
			split = ft_strsplit(read->map[i], '-');
			get_link(read, split[0], split[1], split);
			get_link(read, split[1], split[0], split);
			free(split[0]);
			free(split[1]);
			free(split);
		}
		i++;
	}
}

void	get_link(t_read *read, char *name1, char *name2, char **s)
{
	if (room_exist(read, name1) != -1 && room_exist(read, name2) != -1)
	{
		if (!ft_strcmp(name1, name2))
			return ;
		read->rooms[room_exist(read, name1)]->name[1] =
		ft_strjoin_free(read->rooms[room_exist(read, name1)]->name[1], name2);
		read->rooms[room_exist(read, name1)]->name[1] =
		ft_strjoin_free(read->rooms[room_exist(read, name1)]->name[1], " ");
	}
	else
		invalid_link(read, s);
}

int		room_exist(t_read *read, char *name)
{
	int		i;
	int		count;

	i = 0;
	count = read->count_room;
	while (count-- != 0)
	{
		if (!ft_strcmp(read->rooms[i]->name[0], name))
			return (i);
		i++;
	}
	return (-1);
}

void	invalid_link(t_read *read, char **s)
{
	ft_putstr_fd("ERROR! Invalid link\n", 2);
	free(s[0]);
	free(s[1]);
	free(s);
	clear_rooms(read);
	clear_read(read);
//	sleep(10); // LEEAaaaaKs
	exit(0);
}
