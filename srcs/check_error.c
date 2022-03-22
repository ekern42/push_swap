/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:52:09 by ekern             #+#    #+#             */
/*   Updated: 2022/03/22 16:35:05 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fc_error(int error_nbr)
{
	ft_printf("Error\n");
	if (error_nbr == 1)
		ft_printf("In a string only number and space are authorized\n");
	if (error_nbr == 2)
	{
		/* A CHANGER */
		ft_printf("Nbr of arg should be at least 2\n");
	}
	exit (0);
}

void	fc_argv_digit(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			fc_error(1);
		str++;
	}
	
}

void	fc_print_list(t_push_swap *info)
{
	t_stacks *now;
	now = info->a;
	ft_printf("Stack a : ");
	while (now != NULL)
	{
		ft_printf("%d -> ", now->nbr);
		now = now->next;
	}
	ft_printf("END\nStack b : ");
	now = info->b;
	while (now != NULL)
	{
		ft_printf("%d -> ", now->nbr);
		now = now->next;
	}
	ft_printf("END\n");
}
