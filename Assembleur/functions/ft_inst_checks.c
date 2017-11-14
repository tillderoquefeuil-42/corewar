/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 13:11:44 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/06/23 17:23:23 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	ft_is_inst(char *str)
{
	if (ft_strcmp(str, "live") == 0)
		return (1);
	else if (ft_strcmp(str, "ld") == 0)
		return (2);
	else if (ft_strcmp(str, "st") == 0)
		return (3);
	else if (ft_strcmp(str, "add") == 0)
		return (4);
	else if (ft_strcmp(str, "sub") == 0)
		return (5);
	else if (ft_strcmp(str, "and") == 0)
		return (6);
	else if (ft_strcmp(str, "or") == 0)
		return (7);
	else if (ft_strcmp(str, "xor") == 0)
		return (8);
	else
		return (ft_is_inst_bis(str));
}

int	ft_is_inst_bis(char *str)
{
	if (ft_strcmp(str, "zjmp") == 0)
		return (9);
	else if (ft_strcmp(str, "ldi") == 0)
		return (10);
	else if (ft_strcmp(str, "sti") == 0)
		return (11);
	else if (ft_strcmp(str, "fork") == 0)
		return (12);
	else if (ft_strcmp(str, "lld") == 0)
		return (13);
	else if (ft_strcmp(str, "lldi") == 0)
		return (14);
	else if (ft_strcmp(str, "lfork") == 0)
		return (15);
	else if (ft_strcmp(str, "aff") == 0)
		return (16);
	return (0);
}

int	ft_not_inst(char **tab, t_asm **as)
{
	(*as)->l_err = (*as)->l_err + 1;
	(*as)->s_err = tab[(*as)->lbl];
	ft_error_asm(11, as);
	return (0);
}
