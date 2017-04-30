/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:37:36 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/02 19:06:56 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;

	i = ft_strlen(s1);
	copy = (char *)malloc((i + 1) * sizeof(*s1));
	if (copy != NULL)
		ft_strcpy(copy, s1);
	return (copy);
}
