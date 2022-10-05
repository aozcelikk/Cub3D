/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zero2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:05:36 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/29 20:05:37 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

static void	set_plyr_zero(t_proc *proc)
{
	proc->g_plyr.cam_x = 0;
	proc->g_plyr.cam_y = 0.66;
	proc->g_plyr.dir_x = -1;
	proc->g_plyr.dir_y = 0;
	proc->g_plyr.loc_x = 2;
	proc->g_plyr.loc_y = 16;
	proc->g_plyr.movespd = 0.03;
	proc->g_plyr.rotspd = 0.02;
}

void	set_zero2(t_proc *proc)
{
	set_plyr_zero(proc);
}
