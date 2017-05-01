/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 13:40:37 by dtelega           #+#    #+#             */
/*   Updated: 2017/04/21 13:42:00 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"
# include "get_next_line.h"


# include <stdio.h>



typedef struct 	s_read
{
	int 			ants;
	int 			count_room;
	char			**map;
	struct s_room	**rooms;
	struct s_ways	*ways;
	int				count_ways;
}				t_read;

typedef struct 	s_room
{
	char	**name;
	int 	x;
	int 	y;
	int 	ants_in;
}				t_room;

typedef struct 	s_ways
{
	char	**ways;
	int		count_ways;
}				t_ways;

char			*ft_strjoin_free(char *s1, char *s2);
void			read_map(t_read *read);
void			get_nb_of_ants(t_read *map);
void			get_rooms(t_read *read);
int				get_nb_rooms(t_read *read, int i);
void			get_room(t_read *read, int i, int type);
void			clear_read(t_read *read);
void			invalid_room(t_read *read, t_room *room);
void			clear_rooms(t_read *read);
void			check_rooms(t_read *read);
void			check_st_en(t_read *read);
int 			exist(t_read *read, char *name);
void			get_links(t_read *read);
void			get_link(t_read *read, char	*name1, char *name2, char **s);
int				room_exist(t_read *read, char *name);
t_room			*create_room(void);
void			invalid_link(t_read *read, char **s);

void			start_push(t_read *read);
void			push_ants(t_read *read);
void			print_map(t_read *read);
int 			way_is_found(t_read *read);
void			start_finding(t_read *read, t_ways *ways, char *name);
void			free_split(char **split);
int				room(t_read *read, char	*name);
void 			delete_last_room(t_ways *ways);
void			mo_memory_way(t_ways *ways);
int				room_is_here(char *way, char *name);

#endif