/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:34:18 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/22 16:34:21 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1[0] == s2[0])
	{
		if (s1[1] == s2[1] && s1[1] != ' ')
			return (1);
		else
			return (0);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 0;
	if (str == NULL)
		return (-1);
	while (str[a] == '\t' || str[a] == ' ' || str[a] == '\n'
		|| str[a] == '\v' || str[a] == '\f' || str[a] == '\r')
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			b = -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		c = (c * 10) + (str[a] - '0');
			a++;
	}
	return (c * b);
}

int	ft_strcmpc(const char *s1, const char s2)
{
	if (s1[0] == s2)
	{
		return (1);
	}
	return (0);
}
