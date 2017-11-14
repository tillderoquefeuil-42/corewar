/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coding_bit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:48:27 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/05/20 16:36:39 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_coding_bit(char **tab, t_asm **as, int p)
{
	int		i;
	int		j;
	int		para;
	char	*t;

	j = 0;
	i = (*as)->lbl + 1;
	while (p-- > 0)
	{
		t = NULL;
		para = ft_w_para(tab[i++]);
		if (para == 1)
			t = ft_strdup("01");
		else if (para == 2)
			t = ft_strdup("10");
		else if (para == 3)
			t = ft_strdup("11");
		(*as)->bitco[j++] = t[0];
		(*as)->bitco[j++] = t[1];
		ft_cleaning(NULL, t);
	}
	while (j < 8)
		(*as)->bitco[j++] = '0';
	i = ft_btoi((*as)->bitco);
	return (i);
}

void	ft_print_hex(char *buf, int size)
{
	int	i;

	i = 0;
	while (i < 2192 + size)
	{
		ft_printf("%02hhx ", buf[i++]);
		if (i % 8 == 0)
			ft_printf(" ");
		if (i % 16 == 0)
			ft_printf("\n");
		if (i == 32 || i == 176)
			ft_printf("\n");
		if (i == 32)
			i = 128;
		if (i == 176)
			i = 2048;
	}
	ft_printf("\n\n");
}
