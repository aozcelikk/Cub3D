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
	if (cmap == 'E')
		player_loc(proc, j, i, cmap);
	else if (cmap == 'W')
		player_loc(proc, j, i, cmap);
	else if (cmap == 'N')
		player_loc(proc, j, i, cmap);
	else if (cmap == 'S')
		player_loc(proc, j, i, cmap);
	else
		cmap = '1';
	return (cmap);
}
