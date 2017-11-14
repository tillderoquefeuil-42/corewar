/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:46:47 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/08/05 15:08:02 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_is_naco(t_asm **as)
{
	char	**tab;
	char	*s;
	int		ret;

	ret = 0;
	if (ft_is_comment(as) == 1 || (*as)->str[0] == 0)
		return (0);
	s = ft_comm((*as)->str);
	tab = ft_strsplit(s, ' ');
	if (ft_strcmp(tab[0], ".name") == 0)
	{
		ft_is_too_long(as, 0, s);
		if ((*as)->r == 1)
			ft_is_name(as);
		ret = 1;
	}
	else if (ft_strcmp(tab[0], ".comment") == 0)
	{
		ft_is_too_long(as, 1, s);
		if ((*as)->r == 1)
			ft_is_comm(as);
		ret = 2;
	}
	ft_cleaning(tab, s);
	return (ret);
}

void	ft_is_name(t_asm **as)
{
	unsigned char	c;
	int				j;
	union u_asm		u;

	u.nb = COREWAR_EXEC_MAGIC;
	j = 3;
	while (j >= 0)
	{
		c = u.nbr[j--];
		(*as)->buf[(*as)->i++] = c;
	}
	j = 0;
	while ((*as)->str[j] != '"')
		j++;
	while ((*as)->str[++j] != '"')
	{
		c = (*as)->str[j];
		(*as)->buf[(*as)->i++] = c;
	}
	if ((*as)->i > 136)
		ft_error_asm(9, as);
	c = 0;
	while ((*as)->i < 136)
		(*as)->buf[(*as)->i++] = c;
}

void	ft_is_comm(t_asm **as)
{
	int			c;
	int			j;
	union u_asm	u;

	u.nb = (*as)->o;
	j = 3;
	while (j >= 0)
	{
		c = u.nbr[j--];
		(*as)->buf[(*as)->i++] = c;
	}
	j = 0;
	while ((*as)->str[j] != '"')
		j++;
	while ((*as)->str[++j] != '"')
	{
		c = (*as)->str[j];
		(*as)->buf[(*as)->i++] = c;
	}
	if ((*as)->i > 2192)
		ft_error_asm(10, as);
	c = 0;
	while ((*as)->i < 2192)
		(*as)->buf[(*as)->i++] = c;
}

void	ft_is_too_long(t_asm **as, int i, char *s)
{
	int	j;

	j = 0;
	while (s[j] != 0)
	{
		if (s[j] == '"')
			i = i - 2;
		j++;
	}
	i = i + 4;
	if (i == 0)
	{
		if (ft_strlen(s) > 136)
			ft_error_asm(9, as);
	}
	else if (i == 1)
	{
		if (ft_strlen(s) > 2059)
			ft_error_asm(10, as);
	}
	else
		ft_error_asm(-2, as);
}
