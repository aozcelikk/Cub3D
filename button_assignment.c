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

int	button_value(int key, t_proc *proc)
{
	if (key == 0)
		proc->kbd.a = 0;
	else if (key == 53)
		exit(0);
	return (0);
}

void	button_assignment(t_proc *proc)
{
	mlx_hook(proc->mlx_win, 2, 0, button_value, proc);
	mlx_hook(proc->mlx_win, 17, 0, ft_exit, 0);
}
