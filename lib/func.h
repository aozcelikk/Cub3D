/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:18:35 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/17 13:18:36 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

typedef struct s_gmap
{
	char	**map;
	int		c_arg;
	int		c_idx;
	int		char_cnt;
}	t_gmap;

typedef struct s_kbd
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	r;
	int	l;
}	t_kbd;

typedef struct s_rpg
{
	int		rgb_r;
	int		rgb_b;
	int		rgb_g;
}		t_rpg;

typedef struct s_img
{
	void	**no;
	void	**so;
	void	**we;
	void	**ea;
}		t_img;

typedef struct s_proc
{
	void	*mlx;
	void	*mlx_win;
	void	**img_path;
	char	**map;
	int		row_cnt;
	int		row_len;
	int		new_cnt;
	int		c_arg;
	int		c_idx;
	t_rpg	f_rgb;
	t_rpg	c_rgb;
	t_kbd	kbd;
	t_img	img;
	t_gmap	g_map;
}		t_proc;

#endif