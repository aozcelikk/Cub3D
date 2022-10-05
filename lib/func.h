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
	int		**mapi;
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
	int		rgb;
}		t_rpg;

typedef struct s_img
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		img_x;
	int		img_y;
	char	*imgadd;
	void	*img;
	int		bbp;
	int		*img_data_clr;
	int		per_pxl;
	int		size_line;
	int		endian;
}		t_img;

typedef struct s_plyr
{
	double	loc_x;
	double	loc_y;
	double	dir_x;
	double	dir_y;
	double	cam_x;
	double	cam_y;
	double	movespd;
	double	rotspd;
}		t_plyr;

typedef struct s_proc
{
	void	*mlx;
	void	*mlx_win;
	void	**img_path;
	char	**map;
	int		*screen_img_data;
	void	*screen_img;
	int		row_cnt;
	int		row_len;
	int		new_cnt;
	int		c_arg;
	int		c_idx;
	t_rpg	f_rgb;
	t_rpg	c_rgb;
	t_kbd	kbd;
	t_img	img;
	t_img	imgs[4];
	t_img	screen;
	t_gmap	g_map;
	t_plyr	g_plyr;
}		t_proc;

#endif