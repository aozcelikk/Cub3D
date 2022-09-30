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

static void	set_plyr_zero(t_plyr *player)
{
	player->cam_x = 0;
	player->cam_y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->loc_x = 0;
	player->loc_y = 0;
	player->movespd = 0;
	player->rotspd = 0;
}

void	set_zero2(t_proc *proc)
{
	set_plyr_zero(&proc->g_plyr);
}
