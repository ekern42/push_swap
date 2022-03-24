/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:03:42 by ekern             #+#    #+#             */
/*   Updated: 2022/03/24 14:39:23 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	c = 1;
	while ((str[a] > 8 && str[a] < 14) || str[a] == 32)
		a++;
	if (str[a] == 45 || str[a] == 43)
	{
		if (str[a] == 45)
			c *= -1;
		a++;
	}
	while (str[a] > 47 && str[a] < 58 && str[a] != '\0')
	{
		b += str[a];
		b -= 48;
		a++;
		if (str[a] > 47 && str[a] < 58)
			b *= 10;
	}
	return (c * b);
}
/*
int main(void)
{
	char	a[] = "      2147483648";
	
	printf("%d\n", ft_atoi(a));
}*/
