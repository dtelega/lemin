/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:13:00 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/09 20:11:22 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	long int	nb;
	size_t		len;
	char		*str;
	int			check_for_neg;

	nb = n;
	len = ft_intlen(n);
	check_for_neg = 0;
	if (nb < 0)
	{
		nb *= -1;
		check_for_neg = 1;
	}
	if (!(str = (char *)malloc((len + 1) * sizeof(*str))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (check_for_neg == 1)
		str[0] = '-';
	return (str);
}
