/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:14:38 by aozcelik          #+#    #+#             */
/*   Updated: 2022/10/12 14:14:40 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

static int	map_space(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'F' || map[i] == 'C')
		{
			while (map[i])
			{
				if (map[i] == '\n')
					break ;
				else
					i++;
			}
		}
		else if (map[i] != '1')
			i++;
		else
			break ;
	}
	return (i);
}

static void	wall_enter(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			printf("Error\nMap is not close\n");
			exit(1);
		}
		i++;
	}
}

void	map_enter_check(char *map)
{
	int	i;

	i = map_space(map);
	wall_enter(map + i);
}
