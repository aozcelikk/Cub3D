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
			proc->screen_img_data[y * WIDTH + x] = proc->f_rgb.rgb;
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
		proc->screen_img_data[y * WIDTH + x] = proc->c_rgb.rgb;
		x++;
		if (x == WIDTH)
		{
			y++;
			x = 0;
		}
	}
}

int	print_map(t_proc *s_data)
{
	int	x;

	x = 0;
			if (s_data->g_plyr.cam_y == 0)
			{
		s_data->g_plyr.loc_x = 2;
		s_data->g_plyr.loc_y = 11;
		s_data->g_plyr.dir_x = 1;
		s_data->g_plyr.dir_y = 1;
		s_data->g_plyr.cam_x = 0.2;
		s_data->g_plyr.cam_y = 0.2;
			}

	while (x < WIDTH)
	{

		double sideDistX;
		double sideDistY;
		int stepX;
		int stepY;
		double cameraX = 2 * x / (double)WIDTH -1;
		double rayDirX = s_data->g_plyr.dir_x + s_data->g_plyr.cam_x * cameraX;
		double rayDirY = s_data->g_plyr.dir_y + s_data->g_plyr.cam_y * cameraX;
		int mapX = (int)s_data->g_plyr.loc_x;
		int mapY = (int)s_data->g_plyr.loc_y;
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (s_data->g_plyr.loc_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - s_data->g_plyr.loc_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (s_data->g_plyr.loc_x - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - s_data->g_plyr.loc_y) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (s_data->g_map.map[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - s_data->g_plyr.loc_x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - s_data->g_plyr.loc_y + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(HEIGHT / perpWallDist);
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;

		double wallX;
		if (side == 0)
			wallX = s_data->g_plyr.loc_y + perpWallDist * rayDirY;
		else
			wallX = s_data->g_plyr.loc_x + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		int texX = (int)(wallX * (double)IMG_WIDTH);
		if (side == 0 && rayDirX > 0)
			texX = IMG_WIDTH - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = IMG_WIDTH - texX - 1;

		double step = 1.0 * IMG_HEIGHT / lineHeight;

		double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (IMG_HEIGHT - 1);
			texPos += step;
			int color = s_data->img.img_data_clr[IMG_HEIGHT * texY + texX];
			s_data->screen_img_data[y * WIDTH + x] = color;
		}
		x++;
	}
	mlx_put_image_to_window(s_data->mlx, s_data->mlx_win, s_data->screen_img, 0, 0);
	return (0);
}



























int	game_render(t_proc *proc)
{
	character_rot(proc);
	char_lock_rot(proc);
	return (1);
}
