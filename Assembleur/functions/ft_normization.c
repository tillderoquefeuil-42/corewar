/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:16:34 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/08/05 13:58:33 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_begin_inst(t_asm **as, char *str, int *r, int p)
{
	int	i;

	*r = p;
	i = (*as)->lbl + p;
	(*as)->insi = (*as)->size;
	ft_cleaning(NULL, (*as)->i_err);
	(*as)->i_err = ft_strdup(str);
	(*as)->opcode = ft_is_inst(str);
	(*as)->c_err = ft_strlen((*as)->str);
	return (i);
}

void	ft_too_much_para(t_asm **as, char *str)
{
	(*as)->s_err = str;
	(*as)->c_err = ft_strnstr((*as)->str, str);
	ft_error_asm(2, as);
}

void	ft_end_inst(t_asm **as, char *str, int r)
{
	(*as)->t_err = ft_type_para(str);
	(*as)->p_err = r;
	ft_error_asm(3, as);
}

void	ft_cleaning(char **tab, char *s)
{
	int	i;

	i = 0;
	if (s)
		free(s);
	s = NULL;
	if (tab)
	{
		while (tab[i] != NULL)
		{
			free(tab[i]);
			tab[i++] = NULL;
		}
		free(tab);
	}
	tab = NULL;
}

char	*ft_lab_cat(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == ',')
		str[i] = 0;
	return (str);
}
