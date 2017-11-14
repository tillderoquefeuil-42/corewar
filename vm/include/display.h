/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:11:56 by amineau           #+#    #+#             */
/*   Updated: 2016/06/22 17:33:59 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# define ABS(x) (x<0)?-x:x
# include <ncurses.h>
# include <sys/time.h>

typedef struct	s_disp
{
	struct timeval	tv;
	int				tempo;
}				t_disp;

typedef struct	s_pc
{
	int	nb;
	int	act;
	int	*tab;
}				t_pc;

#endif
