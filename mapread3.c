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

void	gmap_control_check(t_proc *proc)
{
	char	**map;
	int		i;
	int		j;

	map = proc->g_map.map;
	i = 0;
	j = 0;
	while (map[i][j])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'N' \
				|| map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E' \
				|| map[i][j] == ' ' || map[i][j] == '\t' )
				j++;
			else
			{
				printf("Error\nWrong chacter in map\n");
				exit(1);
			}
		}
		i++;
	}
}
