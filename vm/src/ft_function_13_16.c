/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_13_16.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:40:45 by nflores           #+#    #+#             */
/*   Updated: 2016/05/30 12:44:08 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

void	*ft_lld(t_vm **vm, t_param_list *lst, t_proc **proc)
{
	if (param_type((*proc)->codage, 0, 13) == DIR)
		*(lst->next->param->reg) = lst->param->dir;
	else if (lst->param->ind >= 0)
		*(lst->next->param->reg) =
			read_value((*vm)->mem, (*proc)->pc - 2 - IND_SIZE - T_REG
					+ lst->param->ind + 1, REG_SIZE);
	else
		*(lst->next->param->reg) =
			read_value((*vm)->mem, (*proc)->pc - 2 - IND_SIZE - T_REG
					- lst->param->ind * -1 - 1, REG_SIZE);
	if (*(lst->next->param->reg) == 0)
		(*proc)->carry = 1;
	else
		(*proc)->carry = 0;
	return (NULL);
}

void	ft_setreg(t_mem *mem, int *reg, int addr)
{
	if (addr >= 0)
		*reg = read_value(mem, addr + 1, REG_SIZE);
	else
		*reg = read_value(mem, addr - 1, REG_SIZE);
}

void	*ft_lldi(t_vm **vm, t_param_list *lst, t_proc **proc)
{
	int addr;
	int size;

	size = (*proc)->pc - 2 - param_size(param_type((*proc)->codage, 0, 14)) -
			param_size(param_type((*proc)->codage, 1, 14)) - T_REG;
	addr = size;
	if (param_type((*proc)->codage, 0, 14) == DIRI)
		addr += lst->param->diri;
	else if (param_type((*proc)->codage, 0, 14) == IND)
	{
		if (lst->param->ind >= 0)
			addr += read_value((*vm)->mem, size + lst->param->ind + 1, 4);
		else
			addr += read_value((*vm)->mem, size + lst->param->ind - 1, 4);
	}
	else
		addr += *(lst->param->reg);
	if (param_type((*proc)->codage, 1, 14) == DIRI)
		addr += lst->next->param->diri;
	else if (param_type((*proc)->codage, 1, 14) == REG)
		addr += *(lst->next->param->reg);
	ft_setreg((*vm)->mem, lst->next->next->param->reg, addr);
	ft_carry(*(lst->next->next->param->reg), proc);
	return (NULL);
}

void	*ft_lfork(t_vm **vm, t_param_list *lst, t_proc **proc)
{
	t_proc	*fork;
	int		i;

	fork = init_proc((*proc)->champ, (*vm)->proc);
	fork->pc = (*proc)->pc - 1 - T_DIR + lst->param->diri;
	fork->carry = (*proc)->carry;
	fork->aff = (*proc)->aff;
	fork->live = (*proc)->live;
	i = 0;
	while (i < REG_NUMBER)
	{
		fork->reg[i] = (*proc)->reg[i];
		i++;
	}
	(*vm)->proc++;
	return (fork);
}

void	*ft_aff(t_vm **vm, t_param_list *lst, t_proc **proc)
{
	unsigned char c;

	if (!(*vm) || lst != (*proc)->par_list)
		return (NULL);
	c = *(lst->param->reg);
	ft_printf("Aff : %c\n", c);
	return (NULL);
}
