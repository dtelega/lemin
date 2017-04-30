/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:24:37 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/10 16:25:40 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
			if (s[i] == '\0')
				return (count);
		}
		i++;
	}
	return (count);
}

static char		**create_map(char const *s, char **map, char c)
{
	size_t	i;
	size_t	k;
	size_t	len;
	size_t	tmp;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			tmp = i;
			while (s[tmp] != c && s[tmp++])
				len++;
			if (!(map[k++] = ft_strsub(s, i, len)))
				return (NULL);
			i = i + len;
		}
	}
	map[k] = NULL;
	return (map);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**map;

	if (!s || !(map = ft_memalloc((ft_words(s, c) + 1) * sizeof(*map))))
		return (NULL);
	if (!(map = create_map(s, map, c)))
		return (NULL);
	return (map);
}
