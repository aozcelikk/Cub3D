/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:25:22 by aozcelik          #+#    #+#             */
/*   Updated: 2022/10/01 18:25:43 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

void	key_forward(t_proc *proc, int iMap[24][24])
{
	if (!iMap[(int)(proc->g_plyr.loc_x + proc->g_plyr.dir_x * \
	proc->g_plyr.movespd)][(int)(proc->g_plyr.loc_y)])
		proc->g_plyr.loc_x += proc->g_plyr.dir_x * proc->g_plyr.movespd;
	if (!iMap[(int)(proc->g_plyr.loc_x)][(int)(proc->g_plyr.loc_y + \
	proc->g_plyr.dir_y * proc->g_plyr.movespd)])
		proc->g_plyr.loc_y += proc->g_plyr.dir_y * proc->g_plyr.movespd;
}

void	key_backward(t_proc *proc, int iMap[24][24])
{
	if (!iMap[(int)(proc->g_plyr.loc_x - proc->g_plyr.dir_x * \
	proc->g_plyr.movespd)][(int)(proc->g_plyr.loc_y)])
		proc->g_plyr.loc_x -= proc->g_plyr.dir_x * proc->g_plyr.movespd;
	if (!iMap[(int)(proc->g_plyr.loc_x)][(int)(proc->g_plyr.loc_y - \
	proc->g_plyr.dir_y * proc->g_plyr.movespd)])
		proc->g_plyr.loc_y -= proc->g_plyr.dir_y * proc->g_plyr.movespd;
}

void	key_right(t_proc *proc, int iMap[24][24])
{
	if (!iMap[(int)(proc->g_plyr.loc_x + proc->g_plyr.dir_y * \
	proc->g_plyr.movespd)][(int)(proc->g_plyr.loc_x)])
		proc->g_plyr.loc_x += proc->g_plyr.dir_y * proc->g_plyr.movespd;
	if (!iMap[(int)(proc->g_plyr.loc_x)][(int)(proc->g_plyr.loc_x + \
	proc->g_plyr.dir_y * proc->g_plyr.movespd)])
		proc->g_plyr.loc_y += proc->g_plyr.dir_x * proc->g_plyr.movespd;
}

void	key_left(t_proc *proc, int iMap[24][24])
{
	if (!iMap[(int)(proc->g_plyr.loc_x - proc->g_plyr.dir_y * \
	proc->g_plyr.movespd)][(int)(proc->g_plyr.loc_x)])
		proc->g_plyr.loc_x -= proc->g_plyr.dir_y * proc->g_plyr.movespd;
	if (!iMap[(int)(proc->g_plyr.loc_x)][(int)(proc->g_plyr.loc_x - \
	proc->g_plyr.dir_y * proc->g_plyr.movespd)])
		proc->g_plyr.loc_y -= proc->g_plyr.dir_x * proc->g_plyr.movespd;
}
