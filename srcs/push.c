/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:29:58 by ekern             #+#    #+#             */
/*   Updated: 2022/05/03 12:26:33 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fc_push_a(t_push_swap *info)
{
	t_stacks	*temp;

	if (info->b == NULL)
		return ;
	temp = info->b;
	info->b = temp->next;
	temp->next = info->a;
	info->a = temp;
	write(1, "pa\n", 3);
}

void	fc_push_b(t_push_swap *info)
{
	t_stacks	*temp;

	if (info->a == NULL)
		return ;
	temp = info->a;
	info->a = temp->next;
	temp->next = info->b;
	info->b = temp;
	write(1, "pb\n", 3);
}
