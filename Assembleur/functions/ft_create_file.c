/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:48:12 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/05/20 16:36:50 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_create_file(t_asm **as, char *name)
{
	char	*str;
	int		fd;
	int		i;

	str = ft_new_name(name);
	fd = open(str, O_RDWR | O_CREAT, 0600);
	(*as)->s_err = ft_strdup(str);
	if (fd == -1)
		ft_error_asm(8, as);
	fd = open(str, O_WRONLY);
	i = 0;
	while (i < (*as)->i)
		write(fd, &(*as)->buf[i++], 1);
	ft_printf("Writing output program to %s\n", str);
	ft_cleaning(NULL, str);
}

char	*ft_new_name(char *name)
{
	char	*s;
	char	*ext;
	int		i;

	i = ft_strlen(name) - 1;
	ext = ft_strdup("cor");
	s = (char*)malloc(sizeof(char) * (i + 4));
	s = ft_strncpy(s, name, i);
	s = ft_strcat(s, ext);
	ft_cleaning(NULL, ext);
	return (s);
}
