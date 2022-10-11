/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:01:13 by aozcelik          #+#    #+#             */
/*   Updated: 2022/10/03 16:01:14 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

char	poles_casting(char cmap, int i, int j, t_proc *proc)
{
	if (cmap == 'E' && player_loc2(proc, j, i, cmap))
		cmap = '0';
	else if (cmap == 'W' && player_loc2(proc, j, i, cmap))
		cmap = '0';
	else if (cmap == 'N' && player_loc(proc, j, i, cmap))
		cmap = '0';
	else if (cmap == 'S' && player_loc(proc, j, i, cmap))
		cmap = '0';
	else
		cmap = '1';
	return (cmap);
}

void	map_check_all(t_proc *proc, int i)
{
	if (ft_strcmp(proc->map[i], "NO") || ft_strcmpc(proc->map[i], 'N') \
		|| ft_strcmp(proc->map[i], "SO") || ft_strcmpc(proc->map[i], 'S') \
		|| ft_strcmp(proc->map[i], "WE") || ft_strcmpc(proc->map[i], 'W') \
		|| ft_strcmp(proc->map[i], "EA") || ft_strcmpc(proc->map[i], 'E'))
		check_trans_img(proc->map[i], proc);
	else if (ft_strcmpc(proc->map[i], 'F'))
		check_trans_crgb(proc->map[i], proc);
	else if (ft_strcmpc(proc->map[i], 'C'))
		check_trans_frgb(proc->map[i], proc);
}

void	check_trans_crgb2(char	**rgbno, t_proc *proc)
{
	proc->c_rgb.rgb_r = ft_atoi(rgbno[0]);
	proc->c_rgb.rgb_g = ft_atoi(rgbno[1]);
	proc->c_rgb.rgb_b = ft_atoi(rgbno[2]);
}

void	check_trans_frgb2(char	**rgbno, t_proc *proc)
{
	proc->f_rgb.rgb_r = ft_atoi(rgbno[0]);
	proc->f_rgb.rgb_g = ft_atoi(rgbno[1]);
	proc->f_rgb.rgb_b = ft_atoi(rgbno[2]);
}

void	map_enter_check(char *map, char **pmap)
{
	(void)map;
	(void)pmap;/*
	char	**cmap;
	int		i;
	int	j;

	i = 1;
	cmap = pmap + 6;
	while (map[i] && map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c && ((!j || map[i][j - 1] == ' ' || \
			!map[i][j + 1] || map[i][j] == ' ') || \
			(j + 1 > ft_strlen(map[i - 1]) || map[i - 1][j] == ' ') || \
			(j + 1 > ft_strlen(map[i + 1]) || map[i + 1][j] == ' ')))
				return (-1);
			j++;
		}
		i++;
	}
	if (ft_strchr(map[i], c) || ft_strchr(map[0], c))
		return (-1);*/
	/*while (cmap)
	{
		while (*map)
		{
			if (*map == '1' && (*map + 1 == '0' || *map + 1 == '1'))
			{
				if (*map == *cmap[i])
				{
					printf("map %c\tcmap %c\n", *map, *cmap[i]);
					map++;
					i++;
				}
				else
				{
					printf("Error\nMap is not close\n");
					exit(1);
				}
			}
		}
		cmap++;
	}*/
}
