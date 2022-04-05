/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:15:06 by ekern             #+#    #+#             */
/*   Updated: 2022/04/05 15:33:24 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fc_sort_3_nbrs(t_push_swap *info)
{
	t_stacks	*temp1;
	t_stacks	*temp3;

	temp1 = info->a;
	temp3 = temp1->next;
	temp3 = temp3->next;
	while (fc_check_in_order(info) != 0)
	{
		if (temp1->nbr > temp3->nbr)
		{
			fc_rotate(info, 'a');
			temp1 = info->a;
			temp3 = temp1->next;
			temp3 = temp3->next;
		}
		if (temp1->nbr < temp3->nbr)
		{
			fc_swap(info, 'a');
			temp1 = info->a;
			temp3 = temp1->next;
			temp3 = temp3->next;
		}
	}
}

static void	fc_pos_check(t_push_swap *info, int nbr_of_elem, int pos)
{
	t_stacks	*temp1;

	temp1 = info->a;
	if (pos == nbr_of_elem - 1)
		fc_swap(info, 'a');
	else if (pos == 3 && nbr_of_elem == 5)
	{
		fc_rotate(info, 'a');
		fc_swap(info, 'a');
	}
	else if (pos == 2)
	{
		fc_re_rotate(info, 'a');
		fc_re_rotate(info, 'a');
	}
	else if (pos == 1)
		fc_re_rotate(info, 'a');
	fc_push_b(info);
}

static void	fc_small_sort(t_push_swap *info, int nbr_of_elem)
{
	t_stacks	*temp1;
	t_stacks	*temp2;
	int			pos[2];

	while (nbr_of_elem > 3)
	{
		pos[0] = nbr_of_elem;
		temp1 = info->a;
		temp2 = temp1->next;
		while (temp2)
		{
			pos[0]--;
			if (temp1->nbr > temp2->nbr)
			{
				pos[1] = pos[0];
				temp1 = temp2;
			}
			temp2 = temp2->next;
		}
		fc_pos_check(info, nbr_of_elem, pos[1]);
		nbr_of_elem--;
	}
	fc_sort_3_nbrs(info);
	fc_push_a(info);
	fc_push_a(info);
}

void	fc_check_nb_element(t_push_swap *info, int nbr_of_elem)
{
	if (nbr_of_elem == 2)
		fc_swap(info, 'a');
	else if (nbr_of_elem <= 5)
		fc_small_sort(info, nbr_of_elem);
	else
		fc_big_sort(info, nbr_of_elem);
}
