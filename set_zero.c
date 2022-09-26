/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:46:59 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/22 14:47:01 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

static	void	proc_zero(t_proc *proc)
{
	proc->row_cnt = 0;
	proc->row_len = 0;
	proc->new_cnt = 0;
	proc->c_arg = 0;
	proc->c_idx = 0;
}

static	void	gmap_zero(t_gmap *g_map)
{
	g_map->c_arg = 0;
	g_map->c_idx = 0;
	g_map->char_cnt = 0;
}

static	void	kbd_zero(t_kbd *kbd)
{
	kbd->a = 0;
	kbd->d = 2;
	kbd->l = 123;
	kbd->r = 124;
	kbd->s = 1;
	kbd->w = 13;
}

static	void	rgp_zero(t_rpg *rpg)
{
	rpg->rpg_g = 0;
	rpg->rpg_p = 0;
	rpg->rpg_r = 0;
}

int	set_zero(t_proc *proc)
{
	rgp_zero(&proc->f_rpg);
	rgp_zero(&proc->c_rpg);
	kbd_zero(&proc->kbd);
	gmap_zero(&proc->g_map);
	proc_zero(proc);
	return (1);
}
