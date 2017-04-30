/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:15:14 by dtelega           #+#    #+#             */
/*   Updated: 2016/11/30 18:15:30 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t		len1;
	size_t		len2;
	size_t		i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (len1 < (len1 + len2))
	{
		s1[len1] = s2[i];
		i++;
		len1++;
		len2--;
	}
	s1[len1] = '\0';
	return (s1);
}
