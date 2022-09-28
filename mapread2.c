/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:08:23 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/22 15:08:24 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

static int	check_map_in(char *map, int ac)
{
	if (ft_strcmp(map, "NO") || ft_strcmpc(map, 'N'))
		ac += 1;
	else if (ft_strcmp(map, "SO") || ft_strcmpc(map, 'S'))
		ac += 1;
	else if (ft_strcmp(map, "WE") || ft_strcmpc(map, 'W'))
		ac += 1;
	else if (ft_strcmp(map, "EA") || ft_strcmpc(map, 'E'))
		ac += 1;
	else if (ft_strcmpc(map, 'F'))
		ac += 1;
	else if (ft_strcmpc(map, 'C'))
		ac += 1;
	if (ac <= 6)
		return (1);
	return (0);
}

static void	check_trans_frgb(char *Frgb, t_proc *proc)
{
	char	**rgbno;

	rgbno = ft_split(Frgb + 1, ',', proc);
	proc->f_rgb.rgb_r = ft_atoi(rgbno[0]);
	proc->f_rgb.rgb_g = ft_atoi(rgbno[1]);
	proc->f_rgb.rgb_b = ft_atoi(rgbno[2]);
	if ((proc->f_rgb.rgb_r >= 0 && proc->f_rgb.rgb_r <= 255) \
		&& (proc->f_rgb.rgb_g >= 0 && proc->f_rgb.rgb_g <= 255) \
		&& (proc->f_rgb.rgb_b >= 0 && proc->f_rgb.rgb_b <= 255))
		;
	else
	{
		printf("Error\nFrgb not true");
		exit(1);
	}
}

static void	check_trans_crgb(char *Crgb, t_proc *proc)
{
	char	**rgbno;

	rgbno = ft_split(Crgb + 1, ',', proc);
	proc->c_rgb.rgb_r = ft_atoi(rgbno[0]);
	proc->c_rgb.rgb_g = ft_atoi(rgbno[1]);
	proc->c_rgb.rgb_b = ft_atoi(rgbno[2]);
	if ((proc->c_rgb.rgb_r >= 0 && proc->c_rgb.rgb_r <= 255) \
		&& (proc->c_rgb.rgb_g >= 0 && proc->c_rgb.rgb_g <= 255) \
		&& (proc->c_rgb.rgb_b >= 0 && proc->c_rgb.rgb_b <= 255))
		;
	else
	{
		printf("Error\nCrgb not true");
		exit(1);
	}
}

static void	check_trans_img(char **map, t_proc *proc)
{
	if (ft_strcmp(*map, "NO") || ft_strcmp(*map, "SO") \
		|| ft_strcmp(*map, "WE") || ft_strcmp(*map, "EA"))
		check_img(*map + 3, proc);
	else if ((map[0][1] == ' ' ) && (*map[0] == 'N' || *map[0] == 'S' \
		|| *map[0] == 'W' || *map[0] == 'E'))
		check_img(*map + 2, proc);
	else
	{
		printf("Error\nMap Arguman is wrong\n");
		exit(1);
	}
}

void	map_trans_rpg_img_gmap(t_proc *proc)
{
	char	**maps;
	int		i;
	int		ac;

	maps = proc->map;
	i = 0;
	ac = 0;
	while (i < 6)
	{
		if (maps[i])
		{
			if (check_map_in(maps[i], ac))
				i++;
		}
		else
		{
			printf("Error\nWrong map stil");
			exit (1);
		}
	}
	proc->g_map.map = maps + 6;
	gmap_control(proc);
	check_trans_img(maps, proc);
	check_trans_frgb(maps[4], proc);
	check_trans_crgb(maps[5], proc);
}