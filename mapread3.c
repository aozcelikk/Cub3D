/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:39:23 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/26 14:39:25 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

void	gmap_control(t_proc *proc)
{
	char	**map;
	int		i;
	int		j;

	map = proc->g_map.map;
	i = 0;
	j = 0;
	while (i < proc->row_cnt - 6)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'N' || \
				map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E' || \
				map[i][j] == ' ')
					j++;
			else
			{
				printf("Error\nWrong chacter in map\n");
				exit(1);
			}
		}
		i++;
	}
	//gmap_oc_check(proc);
}

void	gmap_oc_check(t_proc *proc)
{
	char	**map;
	int		i;
	int		j;

	map = proc->g_map.map;
	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == ' ')
			j++;
		else if (map[i][j] == '1' && map[i++][j] == '1')
		{
			i++;
		}
		else if (map[i][j] == '1')
		{
			if (map[i][j--] == '1')
				j--;
			else if (map[i][j++] == '1')
				j++;
			i++;
		}
		else
			i--;
		printf("i = %d\tj%d\n", i, j);
	}
	printf("%c\n", map[5][0]);
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
}
