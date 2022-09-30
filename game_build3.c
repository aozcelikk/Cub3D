/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_build3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:37:44 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/30 15:37:45 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

static void	loc_n(t_proc *proc, int nx, int ny)
{
	proc->g_plyr.dir_x = nx;
	proc->g_plyr.dir_y = ny;
	proc->g_plyr.movespd = 0.4;
	proc->g_plyr.rotspd = 0.2;
}

static void	loc_s(t_proc *proc, int sx, int sy)
{
	proc->g_plyr.dir_x = sx;
	proc->g_plyr.dir_y = sy;
	proc->g_plyr.movespd = 0.4;
	proc->g_plyr.rotspd = 0.2;
}

static void	loc_w(t_proc *proc, int wx, int wy)
{
	proc->g_plyr.dir_x = wx;
	proc->g_plyr.dir_y = wy;
	proc->g_plyr.movespd = 0.4;
	proc->g_plyr.rotspd = 0.2;
}

static void	loc_e(t_proc *proc, int ex, int ey)
{
	proc->g_plyr.dir_x = ex;
	proc->g_plyr.dir_y = ey;
	proc->g_plyr.movespd = 0.4;
	proc->g_plyr.rotspd = 0.2;
}

void	char_lock_rot(t_proc *proc)
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
				loc_n(proc, 1, 0);
			else if (map[i][j] == 'S')
				loc_s(proc, -1, 0);
			else if (map[i][j] == 'W')
				loc_w(proc, 0, -1);
			else if (map[i][j] == 'E')
				loc_e(proc, 0, 1);
			else
				j++;
		}
		i++;
	}
}
