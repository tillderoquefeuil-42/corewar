/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_para_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:56:35 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/07/01 12:20:08 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_check_label(char *str, t_asm **as, int t)
{
	char	**tab;
	t_lab	*tmp;
	char	*s;
	int		ret;

	ret = 1;
	if (t == 2 && (*as)->r == 1 && --ret >= 0)
	{
		tab = ft_strsplit(str, ':');
		s = ft_str_du_turfu(tab, 1);
		tmp = (*as)->lab;
		while (tmp != NULL)
		{
			if (ft_strcmp(s, tmp->name) == 0)
				ret = 1;
			tmp = tmp->next;
		}
		ft_cleaning(NULL, (*as)->i_err);
		(*as)->i_err = ft_strdup(s);
		ft_cleaning(tab, s);
	}
	(*as)->s_err = str;
	if (ret == 0)
		ft_error_asm(7, as);
}

int		ft_para_to_nbr(char *str, t_asm **as)
{
	int	nb;

	if (ft_is_direct(str) == 2 || ft_is_indire(str) == 2)
		nb = ft_para_lab(str, as);
	else
	{
		if (ft_is_indire(str) == 1)
			nb = ft_atoi(str);
		else
			nb = ft_atoi(str + 1);
	}
	return (nb);
}

int		ft_para_lab(char *str, t_asm **as)
{
	int		nb;
	t_lab	*tmp;
	char	**tab;
	char	*s;

	tab = ft_strsplit(str, ':');
	s = ft_str_du_turfu(tab, 0);
	ft_cleaning(tab, NULL);
	tab = ft_strsplit(s, ',');
	tmp = (*as)->lab;
	while (tmp != NULL)
	{
		if (ft_strcmp(tab[0], tmp->name) == 0)
			break ;
		tmp = tmp->next;
	}
	nb = tmp->oct;
	if ((*as)->insi < nb)
		nb = nb - (*as)->insi;
	else
		nb = 4294967296 - ((*as)->insi - nb);
	ft_cleaning(tab, s);
	return (nb);
}

int		ft_w_para(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_is_regist(str) == 1)
		return (1);
	else if (ft_is_direct(str) > 0)
		return (2);
	else if (ft_is_indire(str) > 0)
		return (3);
	return (0);
}
