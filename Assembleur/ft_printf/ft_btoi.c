/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 14:26:06 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/05/20 14:12:31 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_btoi(char *nbr)
{
	int	nb;
	int i;
	int	d;

	i = 7;
	d = 1;
	nb = 0;
	while (nbr[i] != '0' && nbr[i] != '1' && i >= 0)
		i--;
	while (nbr[i] == '0' || nbr[i] == '1')
	{
		if (nbr[i] == '1')
			nb = nb + d;
		d = d * 2;
		i--;
	}
	return (nb);
}
