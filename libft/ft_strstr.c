/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:06:34 by dtelega           #+#    #+#             */
/*   Updated: 2016/11/30 18:25:02 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *res;
	const char *find;
	const char *temp;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		res = big;
		temp = big;
		find = little;
		while (*temp == *find && *temp && *find)
		{
			temp++;
			find++;
			if (!*find)
				return ((char *)res);
		}
		big++;
	}
	return (NULL);
}
