/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:52:09 by ekern             #+#    #+#             */
/*   Updated: 2022/03/24 16:34:23 by ekern            ###   ########.fr       */
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
		{
			if (*str != '-')
				fc_error(1);
		}
		str++;
	}
}

void	fc_print_list(t_push_swap *info)
{
	t_stacks	*now;
	int			a;

	a = 10;
	now = info->a;
	ft_printf("Stack a : ");
	while (now != NULL && a > 0)
	{
		ft_printf("%d -> ", now->nbr);
		now = now->next;
		a--;
	}
	ft_printf("END\nStack b : ");
	now = info->b;
	while (now != NULL && a > 0)
	{
		ft_printf("%d -> ", now->nbr);
		now = now->next;
		a--;
	}
	ft_printf("END\n");
}

int	fc_check_in_order(t_push_swap *info)
{
	t_stacks	*nbr1;
	t_stacks	*nbr2;
	
	nbr1 = info->a;
	nbr2 = nbr1->next;
	while (nbr1->nbr > nbr2->nbr && nbr1->next != NULL)
	{
		nbr1 = nbr2;
		if (nbr1->next == NULL)
			break ;
		nbr2 = nbr1->next;
	}
	if (nbr1->next == NULL)
		return (0);
	else
		return (1);
}

int fc_check_same_digit(t_push_swap *info)
{
	t_stacks *temp1;
	t_stacks *temp2;

	temp1 = info->a;
	temp2 = temp1->next;
	while (temp1->nbr != temp2->nbr)
	{
		while (temp)
	}
}