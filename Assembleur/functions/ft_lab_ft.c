/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lab_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:42:35 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/05/20 16:37:54 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_lst_lab(t_asm **as, char *str)
{
	t_lab	*tmp;
	char	**tab;

	tab = ft_strsplit(str, ':');
	tmp = ft_new_lab(tab[0], (*as)->size);
	ft_add_lab(&(*as)->lab, tmp);
	ft_cleaning(tab, NULL);
}

t_lab	*ft_new_lab(char *str, int o)
{
	t_lab	*lst;

	lst = (t_lab*)malloc(sizeof(t_lab));
	if (!lst)
		ft_error_asm(-1, NULL);
	lst->name = ft_strdup(str);
	lst->oct = o;
	lst->next = NULL;
	return (lst);
}

void	ft_add_lab(t_lab **begin, t_lab *new)
{
	t_lab	*tmp;

	if (*begin != NULL)
	{
		tmp = *begin;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*begin = new;
}

void	ft_print_lab(t_lab *lst)
{
	t_lab	*tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			ft_printf("%d. %s\n", tmp->oct, tmp->name);
			tmp = tmp->next;
		}
	}
	ft_putchar('\n');
}

void	ft_clean_lab(t_lab **lst)
{
	t_lab	*tmp;
	t_lab	*tmp2;

	tmp = *lst;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		ft_cleaning(NULL, tmp2->name);
		if (tmp2)
		{
			free(tmp2);
			tmp2 = NULL;
		}
	}
}
