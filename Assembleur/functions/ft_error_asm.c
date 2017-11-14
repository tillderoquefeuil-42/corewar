/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 12:23:46 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/08/05 15:08:42 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_error_asm(int nb, t_asm **as)
{
	if (nb == -1)
		ft_printf("Error -1\nMalloc failed\n");
	else if (nb == 0)
		ft_printf("Error 00\nUse : ./asm <namefile.s>\n");
	else if (nb == 1)
		ft_printf("Error 01\nOpen error: File doesn't exist/wrong format\n");
	else if (nb == 2)
	{
		ft_printf("Syntax error at token [TOKEN]");
		ft_printf("[%03d:%03d] INSTRUCTION \"%s\"\n",
				(*as)->l_err + 1, (*as)->c_err + 1, (*as)->s_err);
	}
	else if (nb == 3)
		ft_printf("Invalid parameter %d type %s for instruction %s\n",
				(*as)->p_err, (*as)->t_err, (*as)->i_err);
	else if (nb == 4)
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ENDLINE\n",
				(*as)->l_err + 1, (*as)->c_err + 1);
	else if (nb == -2)
		ft_printf("Error : Invalid header\n");
	else
		ft_error_asm_bis(nb, as);
	exit(0);
}

void	ft_error_asm_bis(int nb, t_asm **as)
{
	if (nb == 5)
		ft_printf("Invalid parameter count for instruction %s\n", (*as)->i_err);
	else if (nb == 6)
		ft_printf("Wrong header format\n");
	else if (nb == 7)
	{
		ft_printf("No such label %s while ", (*as)->i_err);
		ft_printf("attempting to dereference token [TOKEN]");
		ft_printf("[%03d:%03d] DIRECT_LABEL \"%s\"\n",
				(*as)->l_err + 1, (*as)->c_err + 1, (*as)->s_err);
	}
	else if (nb == 8)
		ft_printf("File \"%s\" can't be created\n", (*as)->s_err);
	else if (nb == 9)
		ft_printf("Champion name too long (Max length 128)\n");
	else if (nb == 10)
		ft_printf("Champion comment too long (Max length 2048)\n");
	else if (nb == 11)
	{
		ft_printf("Invalid instruction at token [TOKEN]");
		ft_printf("[%03d:%03d] INSTRUCTION \"%s\"\n",
				(*as)->l_err + 1, (*as)->c_err + 1, (*as)->s_err);
	}
}

t_asm	**ft_clean(t_asm **as)
{
	ft_cleaning(NULL, (*as)->s_err);
	ft_cleaning(NULL, (*as)->i_err);
	ft_cleaning(NULL, (*as)->t_err);
	ft_cleaning(NULL, (*as)->buf);
	(*as)->s_err = NULL;
	(*as)->i_err = NULL;
	(*as)->t_err = NULL;
	(*as)->buf = NULL;
	ft_clean_file(&(*as)->file);
	ft_clean_lab(&(*as)->lab);
	if (*as)
		free(*as);
	*as = NULL;
	return (NULL);
}
