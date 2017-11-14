/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:38:35 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/05/09 17:24:04 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strnstr(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	if (s2[i] == '\0')
		return (0);
	while (s1[i] != 0)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i] == s2[j] && s1[i] != 0)
			{
				i++;
				j++;
			}
			if (s2[j] == '\0')
				return (i - j);
			i = i - j;
		}
		i++;
	}
	return (0);
}
