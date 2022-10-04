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

//gelen haritanın x ve y sını zunlugu bul hangısı buyukse o kadar bır ınt map ac (tam kare olacak sekılde) 
//içini doldururken tab gorursen 8 atla

#include "./lib/cub3D.h"

static int	start_proc(t_proc *proc)
{
	proc->mlx = mlx_init();
	proc->mlx_win = mlx_new_window(proc->mlx, WIDTH, HEIGHT, "Cub3D");


		void *img_ptr = mlx_xpm_file_to_image(proc->mlx, proc->img.so , &proc->img.img_x, &proc->img.img_y);
		proc->img.img_data_clr = (int *)mlx_get_data_addr(img_ptr, &proc->img.per_pxl, &proc->img.size_line, &proc->img.endian);

		proc->screen_img = mlx_new_image(proc->mlx, WIDTH, HEIGHT);
		proc->screen_img_data = (int *)mlx_get_data_addr(proc->screen_img, &proc->img.per_pxl, &proc->img.size_line, &proc->img.endian);
		f_rgb_up_color(proc);
		c_rgb_down_color(proc);
		print_map(proc);




	button_assignment(proc);
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
	g_mapexportintmap(proc);
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
		game_render(&proc);
	}
	else
		printf("Error\nMissing argument or picture extension!!\n");
	return (0);
}
