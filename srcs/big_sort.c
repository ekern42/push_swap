/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:15:03 by ekern             #+#    #+#             */
/*   Updated: 2022/04/05 15:53:45 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fc_big_sort(t_push_swap *info, int nbr_of_elem)
{
	t_stacks	*temp;
	int			*binary_tab;
	int			a;
	int			bit;

//	a = nbr_of_elem;
	bit = 32;
//	fc_print_list(info);
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
		
		}
		while (info->b != NULL)
			fc_push_a(info);
		
	}
//	fc_print_list(info);
}
