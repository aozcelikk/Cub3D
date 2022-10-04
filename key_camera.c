/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:45:43 by aozcelik          #+#    #+#             */
/*   Updated: 2022/10/04 14:45:45 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

void	camera_right(t_proc *proc)
{
	double	oldcamx;
	double	olddirx;

	oldcamx = proc->g_plyr.cam_x;
	olddirx = proc->g_plyr.dir_x;
	proc->g_plyr.dir_x = proc->g_plyr.dir_x * \
	cos(-proc->g_plyr.rotspd) - proc->g_plyr.dir_y * sin(-proc->g_plyr.rotspd);
	proc->g_plyr.dir_y = olddirx * \
	sin(-proc->g_plyr.rotspd) + proc->g_plyr.dir_y * cos(-proc->g_plyr.rotspd);
	proc->g_plyr.cam_x = proc->g_plyr.cam_x * \
	cos(-proc->g_plyr.rotspd) - proc->g_plyr.cam_y * sin(-proc->g_plyr.rotspd);
	proc->g_plyr.cam_y = oldcamx * \
	sin(-proc->g_plyr.rotspd) + proc->g_plyr.cam_y * cos(-proc->g_plyr.rotspd);
}

void	camera_left(t_proc *proc)
{
	double	oldcamx;
	double	olddirx;

	oldcamx = proc->g_plyr.cam_x;
	olddirx = proc->g_plyr.dir_x;
	proc->g_plyr.dir_x = proc->g_plyr.dir_x * \
	cos(proc->g_plyr.rotspd) - proc->g_plyr.dir_y * sin(proc->g_plyr.rotspd);
	proc->g_plyr.dir_y = olddirx * \
	sin(proc->g_plyr.rotspd) + proc->g_plyr.dir_y * cos(proc->g_plyr.rotspd);
	proc->g_plyr.cam_x = proc->g_plyr.cam_x * \
	cos(proc->g_plyr.rotspd) - proc->g_plyr.cam_y * sin(proc->g_plyr.rotspd);
	proc->g_plyr.cam_y = oldcamx * \
	sin(proc->g_plyr.rotspd) + proc->g_plyr.cam_y * cos(proc->g_plyr.rotspd);
}
