/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:15:02 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/16 18:15:04 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

static int	start_proc(t_proc *proc)
{
	proc->mlx = mlx_init();
	proc->mlx_win = mlx_new_window(proc->mlx, 1920, 1080, "Cub3D");
	mlx_loop(proc->mlx);
	return (0);
}

static int	checker(char **av, t_proc *proc)
{
	if (!mapcheck(av[1]))
	{
		printf("Error\nWrong Map\n");
		return (0);
	}
	map_read(proc, av[1]);
	map_trans_rpg_img_gmap(proc);
	map_character_check(&proc->g_map);
	if (!start_proc(proc))
		printf("Error\nGame is not start");
	return (0);
}

int	main(int ac, char **av)
{
	t_proc	proc;

	if (ac == 2)
	{
		set_zero(&proc);
		checker(av, &proc);
	}
	else
		printf("Error\nMissing argument or picture extension!!\n");
	return (0);
}
