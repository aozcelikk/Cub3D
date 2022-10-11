/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:01:24 by aozcelik          #+#    #+#             */
/*   Updated: 2022/10/11 20:01:26 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

char	**skip_space_enter(t_proc *proc)
{
	char	**maps;
	int		i;
	int		j;

	i = 0;
	maps = proc->map;
	while (maps[i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i][j] == ' ' || maps[i][j] == '\t' || maps[i][j] == '\n')
				j++;
			else
				return (maps + i);
		}
		i++;
	}
	return (proc->map);
}

int	check_spaces(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == ' ' || map[i] == '\t' || map[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

void	map_enter_check(char *map, t_proc *proc)
{
	char	**maps;
	int		i;
	int		j;

	i = 1;
	j = 0;
	maps = ft_split(map, '\n', proc);

	while (maps[i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i + 1][j] == '\0' || (maps[i + 1][j] >= 'A' && maps[i + 1][j] <= 'Z') \
					|| (maps[i + 1][j] >= 'a' && maps[i + 1][j] <= 'z') || (maps[i + 1][j] == ' ') \
					|| (maps[i + 1][j] == '\t') || (maps[i + 1][j] == '.') || (maps[i + 1][j] == ',') \
					|| (maps[i + 1][j] == '/') || (maps[i + 1][j] >= '0' && maps[i + 1][j] <= '9'))
			{
				printf("buealada %s\n", maps[i]);
				i++;
			}
			else if (maps[i][j] == ' ' || maps[i][j] == '\t')
			{
				printf("IM HERE\n");
				j++;	
			}
			else
			{
				printf("BURADA\n%s\nBITTI\n", maps[i]);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
