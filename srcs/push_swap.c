/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:41:23 by ekern             #+#    #+#             */
/*   Updated: 2022/03/22 16:26:29 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void fc_insert(t_push_swap *info, int b)
{
	t_stacks *newa;
	t_stacks *newb;
	
	newa = malloc(sizeof(*newa));
	newb = malloc(sizeof(*newb));
	newa->nbr = b;
	newa->next = info->a;
	info->a = newa;
	newb->nbr = 0;
	newb->next = info->b;
	info->b = newb;
}

static int	fc_multiple_args(char **tab_str, int nbr_arg, t_push_swap *info)
{
	int	a;
	int	b;
	int	c;

	c = nbr_arg;
	a = -1;
	while (c-- != 0)
	{
		fc_argv_digit(tab_str[++a]);
		b = ft_atoi(tab_str[a]);
		fc_insert(info, b);
	}
	fc_print_list(info);
	fc_check_nb_element(info, nbr_arg);
	return (1);
	
}

static int	fc_one_arg(char *str, t_push_swap *info)
{
	int	a;
	int	b;
	char	**tab_str;

	a = -1;
	b = 0;
	while (str[++a] != '\0')
	{
		if (str[a] == ' ')
			b++;
	}
	tab_str = ft_split(str, ' ');
	fc_multiple_args(tab_str, b + 1, info);
	free (tab_str);
	return (1);
}

static void	fc_stack_init(t_push_swap *info, t_stacks *stack)
{
	info = malloc(sizeof(*info));
	stack = malloc(sizeof(*stack));
	if (!info || !stack)
		exit (0);
	stack->next = NULL;
	stack->nbr = 0;
	info->a = stack;
	info->b = stack;
}

int	main(int ac, char **av)
{
	t_push_swap info;
	t_stacks	stack;
	
	if (ac < 2)
		fc_error(2);
	fc_stack_init(&info, &stack);
	if (ac == 2)
		fc_one_arg(av[1], &info);
	if (ac > 2)
		fc_multiple_args(av + 1, ac - 1, &info);
	return (0);
}
