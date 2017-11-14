/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 16:44:05 by amineau           #+#    #+#             */
/*   Updated: 2016/06/22 17:27:14 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

int		ft_next_pc(int *tab, int length, int prev)
{
	int	next;
	int	i;

	i = 0;
	next = MEM_SIZE + 1;
	while (i < length)
	{
		if (tab[i] > prev && tab[i] < next)
			next = tab[i];
		i++;
	}
	return (next);
}

int		ft_number_pc(t_proc_list *exec)
{
	int	i;

	i = 0;
	while (exec)
	{
		i++;
		exec = exec->next;
	}
	return (i);
}

int		*ft_tab_pc(t_proc_list *exec, int length)
{
	int	*table;
	int	i;

	i = 0;
	table = (int*)ft_memalloc(sizeof(int) * length);
	while (exec)
	{
		table[i++] = exec->proc->pc;
		exec = exec->next;
	}
	return (table);
}

t_pc	*ft_init_pc(t_proc_list *exec)
{
	t_pc	*pc;

	pc = (t_pc*)ft_memalloc(sizeof(t_pc));
	pc->nb = ft_number_pc(exec);
	pc->tab = ft_tab_pc(exec, pc->nb);
	pc->act = ft_next_pc(pc->tab, pc->nb, 0);
	return (pc);
}

void	ft_arene(t_mem *tmp, t_pc *pc, int tab[])
{
	int	i;
	int	oct;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (tmp->oct < 0)
			oct = 256 + tmp->oct;
		else
			oct = tmp->oct;
		attron(COLOR_PAIR(ABS(tmp->champ_wr)));
		if (pc->act == i)
		{
			attron(A_BOLD);
			mvprintw(2 + i / D_LARG, 3 + (i % D_LARG) * 3, "%.2x ", oct);
			attroff(A_BOLD);
			pc->act = ft_next_pc(pc->tab, pc->nb, i);
		}
		else
			mvprintw(2 + i / D_LARG, 3 + (i % D_LARG) * 3, "%.2x ", oct);
		attroff(COLOR_PAIR(ABS(tmp->champ_wr)));
		tab[ABS(tmp->champ_wr)]++;
		i++;
		tmp = tmp->next;
	}
}
