/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:30:43 by ekern             #+#    #+#             */
/*   Updated: 2022/03/24 15:48:39 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fc_swap_a(t_push_swap *info)
{
	t_stacks	*temp;
	t_stacks	*temp2;

	if (info->a == NULL)
		return (0);
	temp = info->a;
	info->a = temp->next;
	temp2 = info->a;
	temp->next = temp2->next;
	temp2->next = temp;
	info->a = temp2;
	return (1);
}

static int	fc_swap_b(t_push_swap *info)
{
	t_stacks	*temp;
	t_stacks	*temp2;

	if (info->b == NULL)
		return (0);
	temp = info->b;
	info->b = temp->next;
	temp2 = info->b;
	temp->next = temp2->next;
	temp2->next = temp;
	info->b = temp2;
	return (2);
}

void	fc_swap(t_push_swap *info, int a)
{
	int	b;

	b = 0;
	if (a == 1)
		b = fc_swap_a(info);
	else if (a == 2)
		b = fc_swap_b(info);
	else if (a == 3)
	{
		b = fc_swap_a(info);
		b += fc_swap_b(info);
	}
	else
		ft_printf("error swap int\n");
	if (b == 1)
		write(1, "sa\n", 3);
	else if (b == 2)
		write(1, "sb\n", 3);
	else if (b == 3)
		write(1, "ss\n", 3);
}
