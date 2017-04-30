/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:12:48 by dtelega           #+#    #+#             */
/*   Updated: 2017/04/21 15:12:49 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	read_map(t_read *read)
{
	char		*s;
	char		*mapp;

	s = NULL;
	mapp = ft_strnew(0);
	while (get_next_line(0, &s) > 0)
	{
		mapp = ft_strjoin_free(mapp, s);
		free(s);
		mapp = ft_strjoin_free(mapp, "\n");
	}
	if (!ft_strcmp(s, ""))
		free(s);
	if (mapp[0] == '\0')
	{
		ft_putstr_fd("Empty line!\n", 2);
		free(mapp);
		free(read);
		exit(0);
	}
	read->map = ft_strsplit(mapp, '\n');
	free(mapp);
}

void	get_nb_of_ants(t_read *read)
{
	read->ants = ft_atoi(read->map[0]);
	if (read->ants < 1)
	{
		ft_putstr("Bad count of ants!\n");
		exit(0);
	}
}