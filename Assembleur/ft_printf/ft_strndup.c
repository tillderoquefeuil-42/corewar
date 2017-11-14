/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:13:34 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/05/20 13:17:16 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(const char *s1, int size)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	s2 = (char*)malloc(size + 1);
	if (s2 == NULL)
		return (NULL);
	else
	{
		while (i < size && s1[i] != 0)
		{
			s2[i] = s1[i];
			i++;
		}
		while (i < size)
			s2[i++] = 0;
		s2[i] = 0;
		return (s2);
	}
}
