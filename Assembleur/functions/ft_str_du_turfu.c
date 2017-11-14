/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_du_turfu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 12:12:32 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/07/01 12:25:03 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*ft_str_du_turfu(char **tab, int n)
{
	char	*s;

	if (!tab)
		ft_error_asm(-1, NULL);
	if (!tab[1] && n == 1)
		s = ft_strdup(ft_lab_cat(tab[0]));
	else if (n == 1)
		s = ft_strdup(ft_lab_cat(tab[1]));
	else if (!tab[1])
		s = ft_strdup(tab[0]);
	else
		s = ft_strdup(tab[1]);
	return (s);
}
