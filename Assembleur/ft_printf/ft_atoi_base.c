/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 14:26:06 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/05/27 10:47:09 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define VALID_LOW "0123456789abcdef"
#define VALID_UP "0123456789ABCDEF"

int	ft_backint(char c, int nb, int base)
{
	if (ft_isdigit(c))
		nb = nb * base + c - 48;
	else if (ft_isupper(c))
		nb = nb * base + c - 55;
	else
		nb = nb * base + c - 87;
	return (nb);
}

int	ft_atoi_base(const char *str, int base)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			neg = -1;
		i++;
	}
	while (ft_strnchr(VALID_LOW, str[i], base - 1)
			|| ft_strnchr(VALID_UP, str[i], base - 1))
		nb = ft_backint(str[i++], nb, base);
	nb *= neg;
	return (nb);
}
