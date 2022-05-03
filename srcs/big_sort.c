/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:15:03 by ekern             #+#    #+#             */
/*   Updated: 2022/05/03 12:31:09 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fc_new_nbr(t_push_swap *info, int *nbr_tab)
{
	t_stacks	*temp;
	int			pos;

	temp = info->a;
	pos = 0;
	while (temp)
	{
		temp->nbr = nbr_tab[pos++];
		temp = temp->next;
	}
	free (nbr_tab);
}

static void	fc_change_nbr(t_push_swap *info, int nbr_of_elem, int *nbr_tab)
{
	t_stacks	*temp1;
	t_stacks	*temp2;
	int			pos[2];

	while (nbr_of_elem-- > 0)
	{
		temp1 = info->a;
		pos[0] = 0;
		pos[1] = 0;
		temp2 = temp1;
		while (temp2)
		{
			if (temp1->nbr < temp2->nbr)
			{
				temp1 = temp2;
				pos[1] = pos[0];
			}
			temp2 = temp2->next;
			pos[0]++;
		}
		if (temp1->nbr != -2147483648)
			nbr_tab[pos[1]] = nbr_of_elem;
		temp1->nbr = -2147483648;
	}
	fc_new_nbr(info, nbr_tab);
}

void	fc_big_sort(t_push_swap *info, int nbr_of_elem)
{
	t_stacks	*temp;
	int			*binary_tab;
	int			a;
	int			bit;

	binary_tab = ft_calloc(sizeof(int), nbr_of_elem);
	fc_change_nbr(info, nbr_of_elem, binary_tab);
	bit = 32;
	while (--bit > 0 && fc_check_in_order(info) != 0)
	{
		a = nbr_of_elem;
		while (a-- > 0)
		{
			temp = info->a;
			binary_tab = fc_dec_to_binary(temp->nbr);
			if (binary_tab[bit] == 0)
				fc_push_b(info);
			else
				fc_rotate(info, 'a');
			free (binary_tab);
		}
		while (info->b != NULL)
			fc_push_a(info);
	}
}
