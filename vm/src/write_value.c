/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <nflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:37:26 by nflores           #+#    #+#             */
/*   Updated: 2016/06/27 13:12:35 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

t_mem	*set_oct(t_mem *mem, int addr)
{
	int		i;
	t_mem	*tmp;

	i = 0;
	tmp = mem;
	if (addr >= 0)
		while (i < addr - 1)
		{
			tmp = tmp->next;
			i++;
		}
	else
		while (i > addr - 1)
		{
			tmp = tmp->prev;
			i--;
		}
	return (tmp);
}

void	write_value(t_mem **mem, int value, int addr, t_champ *champ)
{
	t_mem	*tmp;
	int		i;

	i = 0;
	tmp = set_oct(*mem, addr);
	i = REG_SIZE;
	while (i > 0)
	{
		if (i == 1)
			tmp->oct = 0x000000ff & value;
		else
			tmp->oct = (value >> ((i - 1) * 8)) | (0xff << ((i - 1) * 8));
		tmp->champ_wr = champ->num;
		tmp = tmp->next;
		i--;
	}
}

int		read_oct(t_mem *mem, int size)
{
	int i;
	int ret;

	i = size;
	ret = 0;
	while (i > 0)
	{
		ret += (mem->oct << ((i - 1) * 8)) & (0xff << ((i - 1) * 8));
		i--;
		mem = mem->next;
	}
	return (ret);
}

int		read_value(t_mem *mem, int addr, int size)
{
	int i;

	i = 0;
	if (i <= addr)
		while (i < addr - 1)
		{
			mem = mem->next;
			i++;
		}
	else
		while (i > addr + 1)
		{
			mem = mem->prev;
			i--;
		}
	if (size == 1)
		return (mem->oct);
	return (read_oct(mem, size));
}
