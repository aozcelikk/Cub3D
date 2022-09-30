/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_build2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:17:10 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/30 14:17:12 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

static void	loc_n(t_proc *proc, int x, int y)
{
	proc->g_plyr.loc_x = x;
	proc->g_plyr.loc_y = y;
	proc->g_plyr.cam_x = 0;
	proc->g_plyr.cam_y = 0.66;
}

static void	loc_s(t_proc *proc, int x, int y)
{
	proc->g_plyr.loc_x = x;
	proc->g_plyr.loc_y = y;
	proc->g_plyr.cam_x = 0;
	proc->g_plyr.cam_y = 0.66;
}

static void	loc_w(t_proc *proc, int x, int y)
{
	proc->g_plyr.loc_x = x;
	proc->g_plyr.loc_y = y;
	proc->g_plyr.cam_x = 0;
	proc->g_plyr.cam_y = 0.66;
}

static void	loc_e(t_proc *proc, int x, int y)
{
	proc->g_plyr.loc_x = x;
	proc->g_plyr.loc_y = y;
	proc->g_plyr.cam_x = 0;
	proc->g_plyr.cam_y = 0.66;
}

void	character_rot(t_proc *proc)
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
			if (map[i][j] == 'N')
				loc_n(proc, i, j);
			else if (map[i][j] == 'S')
				loc_s(proc, i, j);
			else if (map[i][j] == 'W')
				loc_w(proc, i, j);
			else if (map[i][j] == 'E')
				loc_e(proc, i, j);
			else
				j++;
		}
		i++;
	}
}
