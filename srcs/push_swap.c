/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:41:23 by ekern             #+#    #+#             */
/*   Updated: 2022/05/03 11:21:37 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fc_insert(t_push_swap *info, long b)
{
	t_stacks	*newa;

	newa = malloc(sizeof(*newa));
	if (!newa)
		exit (0);
	newa->nbr = b;
	newa->next = info->a;
	info->a = newa;
}

static int	fc_multiple_args(char **tab_str, int nbr_arg, t_push_swap *info)
{
	long	b;
	int		c;
	int		d;

	c = nbr_arg;
	while (c != 0)
	{
		fc_argv_digit(info, tab_str[--c]);
		b = ft_atol(tab_str[c]);
		if (b > 2147483647 || b < -2147483648)
			fc_error(info);
		fc_insert(info, b);
	}
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
	a = 0;
	if (b != 0)
	{
		tab_str = ft_split(str, ' ');
		fc_multiple_args(tab_str, b + 1, info);
		while (a <= b)
			free(tab_str[a++]);
		free (tab_str);
	}
	return (1);
}

void	fc_final_free(t_push_swap *info)
{
	t_stacks	*free_time;
	t_stacks	*temp;

	free_time = info->a;
	while (free_time != NULL)
	{
		temp = free_time->next;
		free (free_time);
		free_time = temp;
	}
}

int	main(int ac, char **av)
{
	t_push_swap	info;

	if (ac < 2)
		return (0);
	else if (ac == 2)
		fc_one_arg(av[1], &info);
	else if (ac > 2)
		fc_multiple_args(av + 1, ac - 1, &info);
	fc_final_free(&info);
	return (0);
}
