/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 12:07:44 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/06/23 17:12:56 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*ft_comm(char *str)
{
	char	**tab;
	char	*s;

	tab = ft_strsplittr(str, ';');
	s = ft_strdup(tab[0]);
	ft_cleaning(tab, NULL);
	return (s);
}

int		ft_is_comment(t_asm **as)
{
	char	**tab;
	int		ret;

	ret = 0;
	tab = ft_strsplit((*as)->str, ' ');
	if (tab[0] != NULL)
		if (tab[0][0] == COMMENT_CHAR || tab[0][0] == ';')
			ret = 1;
	ft_cleaning(tab, NULL);
	return (ret);
}

int		ft_is_label(t_asm **as)
{
	char	**tab;
	char	*s;
	int		size;

	s = ft_comm((*as)->str);
	tab = ft_strsplit(s, ' ');
	size = 0;
	if (tab[0] != NULL)
	{
		size = ft_strlen(tab[0]) - 1;
		if (tab[0][size] == ':')
		{
			if (tab[1] != NULL)
				size = 1;
			else
				size = 2;
			ft_lst_lab(as, tab[0]);
		}
		else
			size = 0;
	}
	ft_cleaning(tab, s);
	(*as)->lbl = size;
	return (1);
}

int		ft_mult_inst(t_asm **as)
{
	char	**tab;
	char	*s;
	int		i;

	if ((*as)->lbl == 2)
		return (0);
	s = ft_comm((*as)->str);
	tab = ft_strsplit(s, ' ');
	i = (*as)->lbl + 1;
	while (tab[i] != NULL)
	{
		if (ft_is_inst(tab[i]) != 0)
		{
			ft_cleaning(tab, s);
			return (1);
		}
		i++;
	}
	ft_cleaning(tab, s);
	return (0);
}

void	ft_good_inst(t_asm **as)
{
	char		**tab;
	char		*s;
	int			i;
	static int	(*lstft[17])(char **tab, t_asm **as) = {ft_not_inst, \
				ft_is_live, ft_is_ld, ft_is_st, ft_is_add, ft_is_sub, \
				ft_is_and, ft_is_or, ft_is_xor, ft_is_zjmp, ft_is_ldi, \
				ft_is_sti, ft_is_fork, ft_is_lld, ft_is_lldi, ft_is_lfork, \
				ft_is_aff};

	if ((*as)->lbl == 2)
		(*as)->gdi = 0;
	else
	{
		s = ft_comm((*as)->str);
		tab = ft_strsplit(s, ' ');
		i = (*as)->lbl;
		if (tab[i] != NULL)
			(*as)->gdi = (*lstft[ft_is_inst(tab[i])])(tab, as);
		ft_cleaning(tab, s);
	}
}
