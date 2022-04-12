/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:52:09 by ekern             #+#    #+#             */
/*   Updated: 2022/04/12 16:22:54 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fc_error(t_push_swap *info)
{
	ft_printf("Error\n");
	fc_final_free(info);
	exit (0);
}

void	fc_argv_digit(t_push_swap *info, char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			if (*str != '-')
				fc_error(info);
		}
		str++;
	}
}

void	fc_print_list(t_push_swap *info)
{
	t_stacks	*now;
	int			a;

	a = 100;
	now = info->a;
	ft_printf("Stack a : ");
	while (now != NULL && a > 0)
	{
		ft_printf("%d -> ", now->nbr);
		now = now->next;
		a--;
	}
	ft_printf("END\n");
	ft_printf("Stack b : ");
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
	while (nbr1->nbr < nbr2->nbr && nbr1->next != NULL)
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

void	fc_check_same_digit(t_push_swap *info)
{
	t_stacks	*temp1;
	t_stacks	*temp2;

	temp1 = info->a;
	temp2 = temp1->next;
	while (temp1->next != NULL)
	{
		while (temp2)
		{
			if (temp1->nbr == temp2->nbr)
				fc_error (info);
			temp2 = temp2->next;
		}	
		temp1 = temp1->next;
		temp2 = temp1->next;
	}
}
