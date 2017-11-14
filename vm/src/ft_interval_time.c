/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interval_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 16:49:28 by amineau           #+#    #+#             */
/*   Updated: 2016/06/22 17:29:03 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

int		ft_sum_tab(int *tab, int length)
{
	int	i;
	int	tot;

	i = 0;
	tot = 0;
	while (++i < length)
		tot += tab[i];
	return (tot);
}

void	ft_action_getch(int key, int *tempo)
{
	if (key == 27)
	{
		endwin();
		exit(1);
	}
	else if (key == 43 && *tempo <= 495)
		*tempo += 5;
	else if (key == 45 && *tempo >= 15)
		*tempo -= 5;
	else if (key == 32)
	{
		nodelay(stdscr, FALSE);
		while (getch() != 32)
			;
		nodelay(stdscr, TRUE);
	}
	usleep((int)(1000000 / *tempo));
}

void	ft_first_disp(void)
{
	int	i;

	i = 0;
	attron(COLOR_PAIR(101));
	while (i < D_LARG * 3 + 5)
	{
		mvprintw(0, i, "*");
		mvprintw(3 + MEM_SIZE / D_LARG, i++, "*");
	}
	i = 0;
	while (i <= 3 + MEM_SIZE / D_LARG)
	{
		mvprintw(i, 0, "*");
		mvprintw(i++, D_LARG * 3 + 4, "**");
	}
	attroff(COLOR_PAIR(101));
}

void	ft_interval_time(t_disp *dp)
{
	int	usec_prev;
	int	usec_next;
	int	realtime;

	usec_prev = (dp->tv.tv_sec % 10) * 1000000 + dp->tv.tv_usec;
	gettimeofday(&dp->tv, NULL);
	usec_next = (dp->tv.tv_sec % 10) * 1000000 + dp->tv.tv_usec;
	if (usec_next < usec_prev)
		usec_next += 10000000;
	realtime = 10000000 / (usec_next - usec_prev);
	mvprintw(12, 3 * D_LARG + 8, "Real cycles / sec : %d   ", realtime);
}

void	ft_options(int fac, int tab[], int cycles, int tempo)
{
	int	i;
	int	j;

	i = 1;
	mvprintw(10, 3 * D_LARG + 8, "Cycles : %d", cycles);
	mvprintw(11, 3 * D_LARG + 8, "Cycles / sec : %d   ", tempo);
	while (i < MAX_PLAYERS + 1)
	{
		attron(COLOR_PAIR(20 + i));
		j = 0;
		move(15 + i, 3 * D_LARG + 8);
		while (j < 30)
		{
			if ((int)(tab[i] / fac) == j++)
				attroff(COLOR_PAIR(20 + i));
			printw(" ");
		}
		i++;
	}
}
