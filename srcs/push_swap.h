/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:41:25 by ekern             #+#    #+#             */
/*   Updated: 2022/03/22 16:25:48 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Includes */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/big_lib.h"

/* STRUCT */

typedef struct s_stacks
{
	int	nbr;
	struct s_stacks *next;
} 				t_stacks;

typedef struct s_push_swap
{
	t_stacks	*a;
	t_stacks	*b;
}				t_push_swap;

/* Functions */

void	fc_argv_digit(char *str);
void	fc_error(int error_nbr);
void	fc_print_list(t_push_swap *info);
void	fc_check_nb_element(t_push_swap *info, int nbr_of_elem);
void	fc_big_sort(t_push_swap *info);

#endif