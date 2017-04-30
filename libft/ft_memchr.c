/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:10:39 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/07 19:56:42 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned char		sym;
	size_t				i;

	i = 0;
	str = (unsigned char *)s;
	sym = (unsigned char)c;
	while (n)
	{
		if (*str == sym)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
