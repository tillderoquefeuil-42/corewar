/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:38:35 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/05/05 16:32:16 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_howmanywords(const char *s, char c)
{
	int	i;
	int	hmw;

	i = 0;
	hmw = 1;
	if (s == NULL)
		return (0);
	while ((s[i] == c || s[i] == '\t') && s[i] != 0)
		i++;
	if (s[i] == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == c || s[i] == '\t')
		{
			while ((s[i] == c || s[i] == '\t') && s[i] != 0)
				i++;
			if (s[i] != 0)
				hmw++;
		}
		else
			i++;
	}
	return (hmw);
}

static char	*ft_strcut(char const *s, int *start, char c)
{
	char	*str;
	int		i;
	int		len;

	while (s[*start] == c || s[*start] == '\t')
		*start = *start + 1;
	i = *start;
	len = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != c && s[i] != '\t' && s[i++] != 0)
		len++;
	i = 0;
	str = ft_strnew(len);
	while (i < len)
	{
		str[i++] = s[*start];
		*start = *start + 1;
	}
	while (s[*start] == c || s[*start] == '\t')
		*start = *start + 1;
	str[i] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		j;
	int		i;
	int		n;

	j = 0;
	i = 0;
	n = ft_howmanywords(s, c);
	tab = (char**)malloc(sizeof(char*) * (n + 1));
	if (tab == NULL)
		return (NULL);
	if (n != 0)
	{
		while (j < n)
		{
			tab[j] = ft_strcut(s, &i, c);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
