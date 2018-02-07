/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:10:24 by emarin            #+#    #+#             */
/*   Updated: 2017/12/16 13:24:23 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/libft.h"
# include "get_next_line.h"

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# define C_S 200

typedef struct		s_point
{
	int	x;
	int	y;
	int	z;
}					t_point;

typedef struct		s_fpoint
{
	float	x;
	float	y;
	float	z;
}					t_fpoint;

typedef struct		s_pointcol
{
	t_point				pos;
	unsigned	int		col;
}					t_pointcol;

typedef struct		s_cam
{
	t_fpoint	p_screen;
	t_fpoint	pos;
	t_fpoint	targ;
	int			horiangle;
	int			vertangle;
	float		**cam;
	float		**wtocam;
}					t_cam;

typedef struct		s_img
{
	void	*img;
	char	*str;
	int		bpp;
	int		s_l;
	int		endian;
}					t_img;

typedef struct		s_mouse
{
	int	last_x;
	int	last_y;
	int pressed;
}					t_mouse;

typedef struct		s_param
{
	void		*mlx;
	void		*win;
	t_point		s;
	t_img		img;
	t_cam		cam;
	t_pointcol	***res;
	t_mouse		mouse;
}					t_param;

void				ft_lstpushback(t_list **alst, t_list *new);
int					ft_getcoord(const char *name, t_pointcol ***res, int *dist
	, int j);
t_img				draw_line(t_param p, t_point start, t_point end
	, unsigned int color[2]);
void				fill_pixel(t_param p, t_point c, unsigned int color);
void				ft_printmap(t_pointcol ***res, int dist, int w, int h);
void				ft_freematrix(float **m, int height);
float				**ft_newmatrix(int width, int height);
t_fpoint			ft_normalize(t_fpoint p);
t_fpoint			ft_cross(t_fpoint a, t_fpoint b);
t_fpoint			ft_segmtovect(t_fpoint a, t_fpoint b);
void				ft_camera(t_param *p);
size_t				ft_abs(size_t nb);
float				**ft_invertmatrix(float	**m, int n);
void				ft_printmatrix(float **m, int width, int height);
void				ft_swap(float *a, float *b);
float				**ft_mutmatrix(float **mt, float **mp, int width
	, int height);
void				ft_movecamera(t_param *p);
int					ft_projec(t_param p, t_point p3d, t_fpoint *p2d);
int					ft_atoi_base(const char *str, int str_base);
void				draw_3d(t_param p, t_pointcol **r);
float				ft_dot(t_fpoint a, t_fpoint b);
int					ft_tlen(char **s);
int					ft_verifmap(t_pointcol **res);
int					ft_centercoord(t_pointcol **res);
void				ft_free_param(t_param *p, int mode);
void				ft_free_res(t_pointcol ***res, int code);
void				ft_matrix_roty(float **mt, float rangle);
void				ft_matrix_rotx(float **mt, float rangle);
void				ft_rot_trslt(t_param *p, float **mt, char fromto);
void				ft_setmp(float **mp, float x, float y, float z);
int					key_funct(int keycode, void *param);
int					ft_rotate_target(t_param *p, int roll, int back, int coef);
int					ft_fly(t_param *p, int dir, int back);
int					ft_lookat(t_param *p, int forw, int back);

#endif
