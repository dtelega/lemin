/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:56:38 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/06 19:55:02 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	l;
	size_t	i;
	char	tmp;

	if (!s)
		return (NULL);
	l = ft_strlen(s) - 1;
	i = 0;
	while (i < l)
	{
		tmp = s[i];
		s[i] = s[l];
		s[l] = tmp;
		i++;
		l--;
	}
	return (s);
}
