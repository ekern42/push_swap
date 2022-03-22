/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:15:06 by ekern             #+#    #+#             */
/*   Updated: 2022/03/22 16:27:12 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fc_small_sort(t_push_swap *info)
{
	ft_printf("Small sort\n");
}

void	fc_check_nb_element(t_push_swap *info, int nbr_of_elem)
{
	if (nbr_of_elem <= 5)
		fc_small_sort(info);
	else
		fc_big_sort(info);
}
