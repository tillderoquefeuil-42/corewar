/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:49:24 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/08/05 13:56:28 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_file	*ft_new_file(char *str)
{
	t_file	*lst;

	lst = (t_file*)malloc(sizeof(t_file));
	if (!lst)
		ft_error_asm(-1, NULL);
	lst->line = ft_strdup(str);
	lst->next = NULL;
	return (lst);
}

void	ft_add_file(t_file **begin, t_file *new)
{
	t_file	*tmp;

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

void	ft_print_file(t_file *lst)
{
	t_file	*tmp;
	int		i;

	if (lst)
	{
		i = 0;
		tmp = lst;
		while (tmp != NULL)
		{
			ft_printf("%d. %s\n", i, tmp->line);
			tmp = tmp->next;
			i++;
		}
	}
	ft_putchar('\n');
}

void	ft_clean_file(t_file **lst)
{
	t_file	*tmp;
	t_file	*tmp2;

	tmp = *lst;
	if (tmp)
	{
		while (tmp != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			if (tmp2)
			{
				ft_cleaning(NULL, tmp2->line);
				free(tmp2);
				tmp2 = NULL;
			}
		}
	}
	tmp = NULL;
}

void	ft_save_file(t_asm **as)
{
	t_file	*tmp;

	tmp = ft_new_file((*as)->str);
	ft_add_file(&(*as)->file, tmp);
	ft_cleaning(NULL, (*as)->str);
}
