/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:30:21 by ekern             #+#    #+#             */
/*   Updated: 2022/03/29 13:56:44 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fc_re_rotate_a(t_push_swap *info)
{
	t_stacks	*temp1;
	t_stacks	*temp2;

	if (info->a == NULL)
		return (0);
	temp1 = info->a;
	temp2 = info->a;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	while (temp2->next != temp1)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp1->next = info->a;
	info->a = temp1;
	return (1);
}

static int	fc_re_rotate_b(t_push_swap *info)
{
	t_stacks	*temp1;
	t_stacks	*temp2;

	if (info->b == NULL)
		return (0);
	temp1 = info->b;
	temp2 = info->b;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	while (temp2->next != temp1)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp1->next = info->b;
	info->b = temp1;
	return (2);
}

void	fc_re_rotate(t_push_swap *info, int a)
{
	int	b;

	b = 0;
	if (a == 'a')
	{
		b = fc_re_rotate_a(info);
	}
	else if (a == 'b')
	{
		b = fc_re_rotate_b(info);
	}
	else if (a == 'r')
	{
		b = fc_re_rotate_a(info);
		b += fc_re_rotate_b(info);
	}
	else
		ft_printf("Error re_rotate int\n");
	if (b == 1)
		write(1, "rra\n", 4);
	else if (b == 2)
		write(1, "rrb\n", 4);
	else if (b == 3)
		write(1, "rrr\n", 4);
}
