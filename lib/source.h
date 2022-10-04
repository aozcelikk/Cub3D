/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:57:35 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/17 14:57:37 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

//sort code
# define WIDTH 1920
# define HEIGHT 1080
# define IMG_WIDTH 600
# define IMG_HEIGHT 300

//mapcheck.c

int		mapcheck(char *map);
void	check_img_one(char *av, t_proc *proc);
void	check_img_two(char *av, t_proc *proc);
void	map_character_check(t_gmap *g_map);

//function.c

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c, t_proc *proc);

//function2.c
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(char *str);
int		ft_strcmpc(const char *s1, const char s2);
char	*ft_strchr(const char *str, int c);

//function3.c
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2, char const *s3);
int		ft_atoic(char str);

//set_zero.c
int		set_zero(t_proc *proc);

//set_zero2.c
void	set_zero2(t_proc *proc);

//mapread.c

void	map_read(t_proc *proc, char *av);
void	*get_map_free(void *f);
char	*get_map(int fd, char *av);
int		map_len(char *av);

//mapread2.c
void	map_trans_rpg_img_gmap(t_proc *proc);

//mapread3.c
void	gmap_control(t_proc *proc);	
void	gmap_wall_oc_check(t_proc *proc);

//mapread4.c
int		frgbtrans(char **rgbno);
int		crgbtrans(char **rgbno);
t_proc	*g_mapexportintmap(t_proc *proc);

//game_build.c
int		game_render(t_proc *proc);
void	f_rgb_up_color(t_proc *proc);
void	c_rgb_down_color(t_proc *proc);

//game_build2.c
void	character_rot(t_proc *proc);

//game_build3.c
void	char_lock_rot(t_proc *proc);

//button_assignment.c
int		ft_exit(void *tmp);
int		button_up(int key, t_proc *proc);
int		button_down(int key, t_proc *proc);
void	button_assignment(t_proc *proc);




// kontorl edilecek
int		key_press(t_proc *proc);
int		print_map(t_proc *s_data);

#endif
