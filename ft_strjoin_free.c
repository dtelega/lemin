/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 13:52:59 by dtelega           #+#    #+#             */
/*   Updated: 2017/04/21 13:53:01 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*ft_strjoin_free(char *s1, const char *s2)
{
	size_t			i;
	int				k;
	char			*str;
	size_t			len1;
	size_t			len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	k = 0;
	while (i < len1 + len2)
		str[i++] = s2[k++];
	str[i] = '\0';
	free(s1);
	return (str);
}