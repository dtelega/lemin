/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:47:22 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/09 16:40:53 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmap(char **s)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (*s)
	{
		ft_putstr("[");
		ft_putchar(i + '0');
		ft_putstr("]->");
		ft_putstr(*s);
		ft_putstr("<-");
		ft_putchar('\n');
		s++;
		i++;
	}
}
