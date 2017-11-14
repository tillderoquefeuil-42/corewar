/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 11:48:38 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/07/01 12:07:32 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	main(int argc, char **argv)
{
	t_asm	*as;

	if (argc != 2)
		ft_error_asm(0, NULL);
	as = ft_new_struct(argv[1]);
	if (!as)
		ft_error_asm(-1, &as);
	ft_get_champ(&as);
	ft_process_champ(&as);
	ft_create_file(&as, argv[1]);
	ft_clean(&as);
	return (0);
}
