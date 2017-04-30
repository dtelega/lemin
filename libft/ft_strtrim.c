/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:36:27 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/03 17:11:36 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	int			l;
	int			i;
	int			k;

	if (!s)
		return (NULL);
	l = (int)ft_strlen(s) - 1;
	while (s[l] == '\t' || s[l] == '\n' || s[l] == ' ')
		l--;
	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	if ((l - i) <= 0)
		l = i;
	str = (char *)malloc((l - i + 2) * sizeof(*str));
	if (!str)
		return (NULL);
	k = 0;
	while (i <= l)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
