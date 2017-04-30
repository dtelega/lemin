/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:26:09 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/08 12:15:44 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*res;
	const char	*find;
	const char	*temp;
	size_t		i;

	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		i = len;
		res = big;
		temp = big;
		find = little;
		while (*temp == *find && *find && i)
		{
			temp++;
			find++;
			i--;
		}
		if (!*find)
			return ((char *)res);
		big++;
		len--;
	}
	return (0);
}
