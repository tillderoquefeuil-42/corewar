/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <nflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 16:40:20 by nflores           #+#    #+#             */
/*   Updated: 2016/06/28 15:18:09 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

int		ft_index_value(t_mem *mem, int val, int size, char dir)
{
	if (dir == 1)
		return (val);
	if (val >= 0)
		return (read_value(mem, size + val % IDX_MOD + 1, REG_SIZE));
	return (read_value(mem, size - (val * -1) % IDX_MOD - 1, REG_SIZE));
}

void	ft_set_addrind(t_mem *mem, int addr, int *reg)
{
	if (addr >= 0)
		*reg = read_value(mem, addr + 1, REG_SIZE);
	else
		*reg = read_value(mem, addr - 1, REG_SIZE);
}
