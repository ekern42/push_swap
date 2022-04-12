/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:30:31 by ekern             #+#    #+#             */
/*   Updated: 2022/04/12 11:46:32 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* mette node 1 en derniere pos */

static int	fc_rotate_a(t_push_swap *info)
{
	t_stacks	*temp1;
	t_stacks	*temp2;

	if (info->a == NULL)
		return (0);
	temp1 = info->a;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	temp1->next = info->a;
	temp2 = info->a;
	info->a = temp2->next;
	temp2->next = NULL;
	return (1);
}

static int	fc_rotate_b(t_push_swap *info)
{
	t_stacks	*temp1;
	t_stacks	*temp2;

	if (info->b == NULL)
		return (0);
	temp1 = info->b;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	temp1->next = info->b;
	temp2 = info->b;
	info->b = temp2->next;
	temp2->next = NULL;
	return (2);
}

void	fc_rotate(t_push_swap *info, int a)
{
	int	b;

	b = 0;
	if (a == 'a')
	{
		b = fc_rotate_a(info);
	}
	else if (a == 'b')
	{
		b = fc_rotate_b(info);
	}
	else if (a == 'r')
	{
		b = fc_rotate_a(info);
		b += fc_rotate_b(info);
	}
	else
		ft_printf("Error rotate int\n");
	if (b == 1)
		write(1, "ra\n", 3);
	else if (b == 2)
		write(1, "rb\n", 3);
	else if (b == 3)
		write(1, "rr\n", 3);
}
