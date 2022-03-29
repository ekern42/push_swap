/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:41:23 by ekern             #+#    #+#             */
/*   Updated: 2022/03/29 16:24:24 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fc_insert(t_push_swap *info, int b)
{
	t_stacks	*newa;

	newa = malloc(sizeof(*newa));
	newa->nbr = b;
	newa->next = info->a;
	info->a = newa;
}

static int	fc_multiple_args(char **tab_str, int nbr_arg, t_push_swap *info)
{
	int	a;
	int	b;
	int	c;
	int	d;

	c = nbr_arg;
	a = -1;
	while (c-- != 0)
	{
		fc_argv_digit(info, tab_str[++a]);
		b = ft_atoi(tab_str[a]);
		fc_insert(info, b);
	}
//	fc_print_list(info);
	fc_check_same_digit(info);
	d = fc_check_in_order(info);
	if (d == 1)
		fc_check_nb_element(info, nbr_arg);
	return (1);
}

static int	fc_one_arg(char *str, t_push_swap *info)
{
	int		a;
	int		b;
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
	t_push_swap	info;
	t_stacks	stack;

	if (ac < 2)
		return (0);
	fc_stack_init(&info, &stack);
	if (ac == 2)
		fc_one_arg(av[1], &info);
	if (ac > 2)
		fc_multiple_args(av + 1, ac - 1, &info);
	free (info.a);
	return (0);
}
