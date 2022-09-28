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
				printf("Error\nWrong chacter in map\ni %d\tj %d\n", i + 1, j + 1);
				exit(1);
			}
		}
		i++;
	}
	gmap_oc_check(proc);
}

static void	map_tab_bot_control(char *map1, char *map2, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		if (map1[i] == '1')
		{
			if (map2[i + 1] == '1')
				i++;
			else
			{
				printf("Error\nMap is open\n");
				exit (1);
			}
			printf("%c\n", map2[i + 1]);
		}
		else
			i++;
	}
}

void	gmap_oc_check(t_proc *proc)
{
	char	**map;
	int		i;
	int		j;
	int		k;

	map = proc->g_map.map;
	i = 0;
	j = 0;
	k = 0;
	while (map[i][j] && map[i + 1][j])
	{
		j = 0;
		k = 0;
		while (map[i][j])
			j++;
		while (map[i + 1][k])
			k++;
		if (j > k)
			map_tab_bot_control(map[i + 1], map[i], j);
		else if (k > j)
			map_tab_bot_control(map[i], map[i + 1], k);
		else
			map_tab_bot_control(map[i], map[i + 1], k);
	}
}
