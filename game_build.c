/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:45:01 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/30 11:45:02 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

void	game_pixel_put(t_proc *proc, int x, int y, int color)
{
	char	*offset;

	offset = proc->imgaddr + (y * (proc->line_size) + x * \
		(proc->bpp / 8));
	*(unsigned int *) offset = color;
}

void	f_rgb_up_color(t_proc *proc)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			game_pixel_put(proc, x, y, proc->f_rgb.rgb);
			y++;
		}
		x++;
	}
}

void	c_rgb_down_color(t_proc *proc)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	x = 0;
	while (x < WIDTH && y < HEIGHT)
	{
		game_pixel_put(proc, x, y, proc->c_rgb.rgb);
		x++;
		if (x == WIDTH)
		{
			y++;
			x = 0;
		}
	}
}

static void	color_floor_ceiling(t_proc *data)
{
	if (data->draw_end < 0)
		data->draw_end = HEIGHT;
	data->y = data->draw_end;
	while (data->y < HEIGHT)
	{
		game_pixel_put(data, data->x, data->y, data->f_rgb.rgb);
		game_pixel_put(data, data->x, HEIGHT - data->y - 1,
			data->c_rgb.rgb);
		data->y++;
	}
}

int	print_map(t_proc *proc)
{
	if (proc->kbd.w || proc->kbd.s || proc->kbd.a || proc->kbd.d \
		|| proc->kbd.l || proc->kbd.r || proc->t_cam.display)
	{
		proc->t_cam.display = 0;
		proc->x = 0;
		proc->y = 0;
		key_move(proc, &proc->t_cam);
		while (proc->x < WIDTH)
		{
			raycasting_all(proc);
			color_floor_ceiling(proc);
			//f_rgb_up_color(proc);
			//c_rgb_down_color(proc);
			proc->x++;
		}
	}
	mlx_put_image_to_window(proc->mlx, proc->mlx_win, proc->mlx_img, 0, 0);
	return (1);
}
