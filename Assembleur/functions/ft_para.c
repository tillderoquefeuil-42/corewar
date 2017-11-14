/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_para.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:51:30 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/07/01 11:12:31 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_is_para(char *str, t_asm **as)
{
	if (str == NULL)
		return (0);
	if (ft_is_regist(str) == 1)
	{
		(*as)->size = (*as)->size + 1;
		return (1);
	}
	else if (ft_is_direct(str) > 0)
	{
		ft_check_label(str, as, ft_is_direct(str));
		(*as)->size = (*as)->size + 2;
		return (2);
	}
	else if (ft_is_indire(str) > 0)
	{
		ft_check_label(str, as, ft_is_indire(str));
		(*as)->size = (*as)->size + 2;
		return (3);
	}
	return (0);
}

char	*ft_type_para(char *str)
{
	char	*para;

	para = NULL;
	if (ft_is_regist(str) == 1)
		para = ft_strdup("register");
	else if (ft_is_direct(str) > 0)
		para = ft_strdup("direct");
	else if (ft_is_indire(str) > 0)
		para = ft_strdup("indirect");
	return (para);
}

int		ft_is_regist(char *str)
{
	int	i;
	int	nb;

	i = 1;
	if (str[0] == 'r')
	{
		while (str[i] != 0 && (ft_isdigit(str[i]) == 1 || str[i] == '-'))
			i++;
		if (str[i] == ',')
			i++;
		nb = ft_atoi(str + 1);
		if (str[i] == 0 && 1 <= nb && nb <= REG_NUMBER)
			return (1);
	}
	return (0);
}

int		ft_is_direct(char *str)
{
	int	i;

	i = 1;
	if (str != NULL)
	{
		if (str[0] == '%' && (ft_isdigit(str[i]) == 1 || str[i] == '-'))
		{
			while (str[i] != 0 && (ft_isdigit(str[i]) == 1 || str[i] == '-'))
				i++;
			if (str[i] == ',')
				i++;
			if (str[i] == 0)
				return (1);
			else
				return (0);
		}
		else if (str[0] == '%' && str[i] == ':')
			return (2);
		else
			return (0);
	}
	else
		return (0);
}

int		ft_is_indire(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		if (str[i] != '%' && (ft_isdigit(str[i]) == 1 || str[i] == '-'))
		{
			while (str[i] != 0 && (ft_isdigit(str[i]) == 1 || str[i] == '-'))
				i++;
			if (str[i] == ',')
				i++;
			if (str[i] == 0)
				return (1);
		}
		else if (str[i] == ':')
			return (2);
	}
	return (0);
}
