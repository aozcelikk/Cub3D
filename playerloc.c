/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:01:13 by aozcelik          #+#    #+#             */
/*   Updated: 2022/10/03 16:01:14 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

static void	player_loc2(t_proc *proc, char c)
{
	if (c == 'W')
	{
		c = '0';
		proc->t_cam.dir_x = -1;
		proc->t_cam.dir_y = 0;
		proc->t_cam.plane_x = 0;
		proc->t_cam.plane_y = -1;
	}
	if (c == 'E')
	{
		c = '0';
		proc->t_cam.dir_x = 1;
		proc->t_cam.dir_y = 0;
		proc->t_cam.plane_x = 0;
		proc->t_cam.plane_y = 1;
	}
}

void	player_loc(t_proc *proc, int x, int y, char c)
{
	proc->t_cam.pos_x = (double)x + 0.5;
	proc->t_cam.pos_y = (double)y + 0.5;
	if (c == 'N')
	{
		c = '0';
		proc->t_cam.dir_x = 0;
		proc->t_cam.dir_y = -1;
		proc->t_cam.plane_x = 1;
		proc->t_cam.plane_y = 0;
	}
	if (c == 'S')
	{
		c = '0';
		proc->t_cam.dir_x = 0;
		proc->t_cam.dir_y = 1;
		proc->t_cam.plane_x = -1;
		proc->t_cam.plane_y = 0;
	}
	player_loc2(proc, c);
}
