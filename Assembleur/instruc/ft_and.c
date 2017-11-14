/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:18:59 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/05/27 10:42:45 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	ft_is_and(char **tab, t_asm **as)
{
	int	i;
	int	r;
	int ret;

	i = ft_begin_inst(as, "and", &r, 3);
	(*as)->size = (*as)->size + 2;
	if (tab[i] == NULL || tab[i - 1] == NULL || tab[i - 2] == NULL)
		ft_error_asm(5, as);
	else if (tab[i + 1] != NULL)
		ft_too_much_para(as, tab[i + 1]);
	if (ft_is_para(tab[i--], as) != 1)
		r = 2;
	ret = ft_is_para(tab[i--], as);
	if (ret == 0)
		r = 1;
	ft_add_size(as, ret);
	ret = ft_is_para(tab[i], as);
	if (ret == 0)
		r = 0;
	ft_add_size(as, ret);
	if (r != 3)
		ft_end_inst(as, tab[i + r], r);
	if ((*as)->r == 1)
		ft_instance(tab, as, 3, 3);
	return (1);
}
