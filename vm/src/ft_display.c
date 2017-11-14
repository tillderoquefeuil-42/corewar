/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 18:07:57 by amineau           #+#    #+#             */
/*   Updated: 2016/06/22 17:25:58 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

void	ft_display(t_vm *vm, t_disp *dp, t_proc_list *exec_proc, int opt)
{
	int		i;
	int		tab[MAX_PLAYERS + 1];
	t_pc	*pc;

	if (opt)
	{
		i = 0;
		while (i < MAX_PLAYERS + 1)
			tab[i++] = 0;
		pc = ft_init_pc(exec_proc);
		ft_arene(vm->mem, pc, tab);
		if (vm->cycles == 1)
			ft_first_disp();
		if (vm->cycles % 10 == 1)
			ft_interval_time(dp);
		ft_options(ft_sum_tab(tab, MAX_PLAYERS + 1) / 30,
				tab, vm->cycles, dp->tempo);
		refresh();
		ft_action_getch(getch(), &(dp->tempo));
		free(pc->tab);
		free(pc);
	}
}

t_disp	*ft_init_display(int opt)
{
	t_disp	*dp;
	int		i;

	if (!opt)
		return (NULL);
	i = 0;
	dp = (t_disp*)ft_memalloc(sizeof(t_disp));
	dp->tempo = 10;
	initscr();
	cbreak();
	noecho();
	start_color();
	init_color(COLOR_WHITE, 400, 400, 400);
	while (i++ < MAX_PLAYERS)
		init_pair(i, i, 0);
	i = 0;
	while (i++ < MAX_PLAYERS)
		init_pair(20 + i, 0, i);
	while (i++ < MAX_PLAYERS)
		init_pair(20 + i, 0, i);
	init_pair(101, 7, 7);
	nodelay(stdscr, TRUE);
	return (dp);
}

void	ft_finish_display(t_disp *dp, int opt)
{
	if (opt)
	{
		free(dp);
		nodelay(stdscr, FALSE);
		getch();
		endwin();
	}
}
