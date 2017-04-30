/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:47:26 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/08 12:35:47 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*str;

	if (!s)
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && len)
	{
		str[i] = s[start + i];
		i++;
		len--;
	}
	while (len)
	{
		str[i++] = '\0';
		len--;
	}
	str[i] = '\0';
	return (str);
}
