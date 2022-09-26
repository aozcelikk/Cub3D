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

//mapcheck.c

int		mapcheck(char *map);
void	check_img(char *av, t_proc *proc);
void	map_character_check(t_gmap *g_map);

//function.c

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c, t_proc *proc);

//function2.c
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		ft_strcmpc(const char *s1, const char s2);

//mapread.c

void	map_read(t_proc *proc, char *av);
void	*get_map_free(void *f);
char	*get_map(int fd, char *av);
int		map_len(char *av);

//set_zero.c
int		set_zero(t_proc *proc);

//mapread2.c
void	map_trans_rpg_img_gmap(t_proc *proc);

#endif
