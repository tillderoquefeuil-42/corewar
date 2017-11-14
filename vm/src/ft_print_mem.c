/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <nflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 10:36:14 by nflores           #+#    #+#             */
/*   Updated: 2016/06/27 11:04:18 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

void	ft_print_mem(t_mem *mem)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.2hhx ", mem->oct);
		i++;
		mem = mem->next;
		if (i != 0 && i % 64 == 0)
			ft_putchar('\n');
	}
}
