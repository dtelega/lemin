/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:52:45 by dtelega           #+#    #+#             */
/*   Updated: 2016/11/30 18:15:47 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		len1;
	size_t		len2;
	size_t		i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (len1 < (len1 + len2) && i < n)
	{
		s1[len1] = s2[i];
		i++;
		len1++;
		len2--;
	}
	s1[len1] = '\0';
	return (s1);
}
