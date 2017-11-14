/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_inst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:14:44 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/07/01 11:20:06 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_write_inst(char **tab, t_asm **as, int p, int s)
{
	unsigned char	c;
	int				j;
	int				i;
	union u_asm		u;

	j = (*as)->lbl;
	p = p + j + 1;
	while (++j < p)
	{
		if (ft_w_para(tab[j]) == 1)
		{
			c = ft_para_to_nbr(tab[j], as);
			(*as)->buf[(*as)->i++] = c;
		}
		else
		{
			i = s;
			if (ft_w_para(tab[j]) == 3)
				i = 1;
			u.nb = ft_para_to_nbr(tab[j], as);
			while (i >= 0)
				ft_add_nbr(as, u.nbr[i--]);
		}
	}
}

void	ft_instance(char **tab, t_asm **as, int p, int sp)
{
	unsigned char	c;
	int				op;

	op = (*as)->opcode;
	c = op;
	(*as)->buf[(*as)->i++] = c;
	if (op != 1 && op != 9 && op != 12 && op != 15)
	{
		c = ft_coding_bit(tab, as, p);
		(*as)->buf[(*as)->i++] = c;
	}
	ft_write_inst(tab, as, p, sp);
}

void	ft_add_nbr(t_asm **as, char n)
{
	unsigned char	c;

	c = n;
	(*as)->buf[(*as)->i++] = c;
}

void	ft_add_size(t_asm **as, int ret)
{
	if (ret == 2)
		(*as)->size = (*as)->size + 2;
}
