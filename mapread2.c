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
	else
		return (-1);
	if (ac <= 6)
		return (1);
	return (0);
}

static void	check_trans_frgb(char *Frgb, t_proc *proc)
{
	char	**rgbno;
	int		i;

	i = 0;
	rgbno = ft_split(Frgb + 1, ',', proc);
	while (rgbno[i])
		i++;
	if (i != 3)
	{
		printf("Error\nFrgb arguments is fail");
		exit (1);
	}
	proc->f_rgb.rgb_r = ft_atoi(rgbno[0]);
	proc->f_rgb.rgb_g = ft_atoi(rgbno[1]);
	proc->f_rgb.rgb_b = ft_atoi(rgbno[2]);
	if ((proc->f_rgb.rgb_r >= 0 && proc->f_rgb.rgb_r <= 255) \
		&& (proc->f_rgb.rgb_g >= 0 && proc->f_rgb.rgb_g <= 255) \
		&& (proc->f_rgb.rgb_b >= 0 && proc->f_rgb.rgb_b <= 255))
		proc->f_rgb.rgb = frgbtrans(rgbno);
	else
	{
		printf("Error\nFrgb not true");
		exit(1);
	}
}

static void	check_trans_crgb(char *Crgb, t_proc *proc)
{
	char	**rgbno;
	int		i;

	i = 0;
	rgbno = ft_split(Crgb + 1, ',', proc);
	while (rgbno[i])
		i++;
	if (i != 3)
	{
		printf("Error\nCrgb arguments is fail");
		exit (1);
	}
	proc->c_rgb.rgb_r = ft_atoi(rgbno[0]);
	proc->c_rgb.rgb_g = ft_atoi(rgbno[1]);
	proc->c_rgb.rgb_b = ft_atoi(rgbno[2]);
	if ((proc->c_rgb.rgb_r >= 0 && proc->c_rgb.rgb_r <= 255) \
		&& (proc->c_rgb.rgb_g >= 0 && proc->c_rgb.rgb_g <= 255) \
		&& (proc->c_rgb.rgb_b >= 0 && proc->c_rgb.rgb_b <= 255))
		proc->c_rgb.rgb = crgbtrans(rgbno);
	else
	{
		printf("Error\nCrgb not true");
		exit(1);
	}
}

static void	check_trans_img(char *map, t_proc *proc)
{
	if (ft_strcmp(map, "NO") || ft_strcmp(map, "SO") \
		|| ft_strcmp(map, "WE") || ft_strcmp(map, "EA"))
		check_img_two(map, proc);
	else if ((map[1] == ' ' ) && (map[0] == 'N' || map[0] == 'S' \
		|| map[0] == 'W' || map[0] == 'E'))
		check_img_one(map, proc);
	else
	{
		printf("Error\nMap Arguman is wrong\n");
		exit(1);
	}
}

void	map_trans_rpg_img_gmap(t_proc *proc)
{
	int		i;
	int		ac;

	i = 0;
	ac = 0;
	while (i < 6)
	{
		if (i < 4)
			check_trans_img(proc->map[i], proc);
		if (proc->map[i])
		{
			if (check_map_in(proc->map[i], ac) == 1)
				i++;
			else
			{
				printf("Error\nWrong map stil");
				exit (1);
			}
		}
	}
	proc->g_map.map = proc->map + 6;
	gmap_control(proc);
	check_trans_frgb(proc->map[4], proc);
	check_trans_crgb(proc->map[5], proc);
}
