/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 11:38:02 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/08/05 13:55:19 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_get_champ(t_asm **as)
{
	int	n;

	n = 0;
	while (++n <= 2)
	{
		get_next_line((*as)->fd, &(*as)->str);
		while (ft_is_naco(as) != n && (*as)->l_err++ >= 0)
		{
			if (ft_is_comment(as) != 1 && (*as)->str[0] != 0)
				ft_error_asm(6, as);
			ft_cleaning(NULL, (*as)->str);
			get_next_line((*as)->fd, &(*as)->str);
		}
		ft_save_file(as);
	}
	while (get_next_line((*as)->fd, &(*as)->str) != 0 && (*as)->l_err++ >= 0)
	{
		if ((*as)->str[0] != 0 && ft_is_comment(as) == 0)
			if (ft_is_label(as) == 1 && ft_mult_inst(as) == 0)
				ft_good_inst(as);
		ft_save_file(as);
	}
	ft_cleaning(NULL, (*as)->str);
}

void	ft_process_champ(t_asm **as)
{
	t_file	*tmp;
	int		n;

	tmp = ft_init_writing(as, &n);
	while (++n <= 2)
	{
		(*as)->str = tmp->line;
		while (ft_is_naco(as) != n)
		{
			tmp = tmp->next;
			(*as)->str = tmp->line;
		}
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		(*as)->str = tmp->line;
		if ((*as)->str[0] != 0 && ft_is_comment(as) == 0)
		{
			ft_is_label(as);
			if (ft_mult_inst(as) == 0)
				ft_good_inst(as);
		}
		tmp = tmp->next;
	}
}
