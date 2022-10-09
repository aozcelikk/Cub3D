/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:01:13 by aozcelik          #+#    #+#             */
/*   Updated: 2022/10/03 16:01:14 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

int	frgbtrans(char **rgbno)
{
	char	*frgb;
	int		rgbnu;

	frgb = ft_strjoin(rgbno[0], rgbno[1], rgbno[2]);
	rgbnu = ft_atoi(frgb);
	return (rgbnu);
}

int	crgbtrans(char **rgbno)
{
	char	*crgb;
	int		rgbnu;

	crgb = ft_strjoin(rgbno[0], rgbno[1], rgbno[2]);
	rgbnu = ft_atoi(crgb);
	return (rgbnu);
}

static int	g_maptointmap(t_proc *proc)
{
	int	i;
	int	j;
	int	idx;
	int	tab;

	i = 0;
	j = 0;
	idx = 0;
	tab = 0;
	while (proc->g_map.map[i])
	{
		if (j > idx)
			idx = j;
		if (i > j)
			idx = i;
		j = 0;
		while (proc->g_map.map[i][j])
		{
			if (proc->g_map.map[i][j] == '\t')
				tab += 8;
			j++;
		}
		i++;
	}
	return (idx + tab);
}

void	g_mapexportintmap(t_proc *proc)
{
	int		idx;
	int		i;
	int		j;
	int		**imap;
	char	**cmap;

	i = 0;
	j = 0;
	cmap = proc->g_map.map;
	idx = g_maptointmap(proc);
	imap = (int **)malloc(sizeof(int *) * (idx + 1));
	while (j < idx)
	{
		imap[j] = malloc(sizeof(int) * (idx + 1));
		j++;
	}
	while (cmap[i])
	{
		j = 0;
		while (cmap[i][j])
		{
			if ((cmap[i][j] == 'N' || cmap[i][j] == 'S' || \
			cmap[i][j] == 'W' || cmap[i][j] == 'E' || cmap[i][j] == ' '))
				cmap[i][j] = poles_casting(cmap[i][j], i, j, proc);
			idx = ft_atoic(cmap[i][j]);
			imap[i][j] = idx;
			j++;
		}
		i++;
	}
	proc->g_map.mapi = imap;
}
