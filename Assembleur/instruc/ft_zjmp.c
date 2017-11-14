/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:55:36 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/05/20 16:35:00 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	ft_is_zjmp(char **tab, t_asm **as)
{
	int	i;
	int	r;

	i = ft_begin_inst(as, "zjmp", &r, 1);
	(*as)->size = (*as)->size + 1;
	if (tab[i] == NULL)
		ft_error_asm(4, as);
	else if (tab[i + 1] != NULL)
		ft_too_much_para(as, tab[i + 1]);
	else if (ft_is_para(tab[i], as) != 2)
	{
		(*as)->t_err = ft_type_para(tab[i]);
		(*as)->p_err = 0;
		ft_error_asm(3, as);
	}
	if ((*as)->r == 1)
		ft_instance(tab, as, 1, 1);
	return (1);
}
