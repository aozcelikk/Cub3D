/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_assignment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:08:17 by aozcelik          #+#    #+#             */
/*   Updated: 2022/10/01 14:08:19 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

int	ft_exit(void *tmp)
{
	(void)tmp;
	exit(0);
}

int	button_up(int key, t_proc *proc)
{
	if (key == 13)
		proc->kbd.w = 1;
	else if (key == 1)
		proc->kbd.s = 1;
	else if (key == 0)
		proc->kbd.a = 1;
	else if (key == 2)
		proc->kbd.d = 1;
	else if (key == 123)
		proc->kbd.l = 1;
	else if (key == 124)
		proc->kbd.r = 1;
	else if (key == 53)
		exit(0);
	return (0);
}

int	button_down(int key, t_proc *proc)
{
	if (key == 13)
		proc->kbd.w = 0;
	else if (key == 1)
		proc->kbd.s = 0;
	else if (key == 0)
		proc->kbd.a = 0;
	else if (key == 2)
		proc->kbd.d = 0;
	else if (key == 123)
		proc->kbd.l = 0;
	else if (key == 124)
		proc->kbd.r = 0;
	return (0);
}

void	button_assignment(t_proc *proc)
{
	mlx_hook(proc->mlx_win, 2, 0, button_up, proc);
	mlx_hook(proc->mlx_win, 3, 0, button_down, proc);
	mlx_loop_hook(proc->mlx, key_press, proc);
	mlx_hook(proc->mlx_win, 17, 0, ft_exit, 0);
}









int	key_press(t_proc *proc)
{
		if (proc->kbd.w == 1) // ileri tuşu locx->posX   planeX->cam_x
	{
		proc->g_plyr.loc_x += 0.01;
		



		/*
		if (!proc->g_map.map[(int)(proc->g_plyr.loc_x + proc->g_plyr.dir_x * proc->g_plyr.movespd)][(int)(proc->g_plyr.loc_y)])
			proc->g_plyr.loc_x += proc->g_plyr.dir_x * proc->g_plyr.movespd;
		if (!proc->g_map.map[(int)(proc->g_plyr.loc_x)][(int)(proc->g_plyr.loc_y + proc->g_plyr.dir_y * proc->g_plyr.movespd)])
			proc->g_plyr.loc_y += proc->g_plyr.dir_y * proc->g_plyr.movespd;
			*/
	}
		if (proc->kbd.a == 1) // geri tuşu
	{
		proc->g_plyr.loc_y -= 0.01;
		
		
		/*
		proc->g_plyr.loc_y -= 1;
		proc->g_plyr.loc_x -= 2;
		if (!proc->g_map.map[(int)(proc->g_plyr.loc_x - proc->g_plyr.dir_x * proc->g_plyr.movespd)][(int)(proc->g_plyr.loc_y)])
			proc->g_plyr.loc_x -= proc->g_plyr.dir_x * proc->g_plyr.movespd;
		if (!proc->g_map.map[(int)(proc->g_plyr.loc_x)][(int)(proc->g_plyr.loc_y - proc->g_plyr.dir_y * proc->g_plyr.movespd)])
			proc->g_plyr.loc_y -= proc->g_plyr.dir_y * proc->g_plyr.movespd;
		*/
	}
		if (proc->kbd.d == 1) // geri tuşu
	{
		proc->g_plyr.loc_y += 0.01;
	}
		if (proc->kbd.s == 1) // geri tuşu
	{
		proc->g_plyr.loc_x -= 0.01;
	}
		if (proc->kbd.l == 1) // geri tuşu
	{
		proc->g_plyr.cam_x -= 0.01;
	}
			if (proc->kbd.r == 1) // geri tuşu
	{
		proc->g_plyr.cam_x += 0.01;
	}
	mlx_clear_window(proc->mlx, proc->mlx_win);
	f_rgb_up_color(proc);
	c_rgb_down_color(proc);
	print_map(proc);
	return (0);
}
