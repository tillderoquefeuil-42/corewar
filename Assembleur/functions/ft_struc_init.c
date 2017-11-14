/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struc_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:16:40 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/05/20 16:38:47 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_asm	*ft_new_struct(char *path)
{
	t_asm	*as;
	int		i;

	i = 0;
	as = (t_asm *)malloc(sizeof(t_asm));
	if (!as)
		ft_error_asm(-1, &as);
	as->fd = ft_new_struct_bis(&as);
	as->p_err = 0;
	as->c_err = 0;
	as->l_err = 0;
	as->lbl = 0;
	as->gdi = 0;
	as->i = 0;
	while (i < 9)
		as->bitco[i++] = 0;
	i = 0;
	while (path[i])
		i++;
	if (path[i - 2] == '.' && path[i - 1] == 's')
		as->fd = open(path, O_RDONLY);
	if (as->fd == -1)
		ft_error_asm(1, &as);
	return (as);
}

int		ft_new_struct_bis(t_asm **as)
{
	(*as)->buf = NULL;
	(*as)->lab = NULL;
	(*as)->file = NULL;
	(*as)->str = NULL;
	(*as)->s_err = NULL;
	(*as)->i_err = NULL;
	(*as)->t_err = NULL;
	(*as)->size = 0;
	(*as)->insi = 0;
	(*as)->r = 0;
	(*as)->o = 0;
	return (-1);
}

t_file	*ft_init_writing(t_asm **as, int *n)
{
	t_file	*tmp;

	(*as)->buf = (char *)malloc(sizeof(char) * (2192 + (*as)->size));
	if ((*as)->buf == NULL)
		ft_error_asm(-1, as);
	(*as)->r = 1;
	(*as)->o = (*as)->size;
	(*as)->size = 0;
	*n = 0;
	tmp = (*as)->file;
	return (tmp);
}
