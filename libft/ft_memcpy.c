/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:32:13 by dtelega           #+#    #+#             */
/*   Updated: 2016/11/30 16:56:48 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*newdst;
	const char	*newsrc;
	size_t		i;

	i = 0;
	newdst = dst;
	newsrc = src;
	while (i < n)
	{
		newdst[i] = newsrc[i];
		i++;
	}
	return (newdst);
}
