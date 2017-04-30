/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:42:34 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/02 14:43:33 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*newdst;
	const char		*newsrc;

	newdst = (char *)dst;
	newsrc = (const char *)src;
	while (n)
	{
		if ((*newdst++ = *newsrc++) == c)
			return (void *)(newdst);
		n--;
	}
	return (NULL);
}
