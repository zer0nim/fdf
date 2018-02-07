/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:58:09 by emarin            #+#    #+#             */
/*   Updated: 2017/12/15 15:40:25 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_fpoint	**ft_initp2d(t_pointcol **res)
{
	t_fpoint	**p2d;
	int			i;
	int			j;

	j = 0;
	while (res[j] != NULL)
	{
		i = 0;
		while (res[j][i].pos.x != -1)
			++i;
		++j;
	}
	if (!(p2d = (t_fpoint **)malloc(sizeof(t_fpoint *) * (j))))
		return (NULL);
	while (--j >= 0)
		if (!(p2d[j] = (t_fpoint *)malloc(sizeof(t_fpoint) * (i))))
			return (NULL);
	return (p2d);
}

void		freep2d(t_pointcol **res, t_fpoint **p2d)
{
	int			i;
	int			j;

	j = -1;
	while (res[++j] != NULL)
	{
		i = 0;
		while (res[j][i].pos.x != -1)
			++i;
	}
	--j;
	while (j >= 0)
	{
		free(p2d[j]);
		--j;
	}
	free(p2d);
}

int			p_dr(t_point *p, t_fpoint v, unsigned int *cl
	, unsigned int c)
{
	(*p).x = v.x;
	(*p).y = v.y;
	*cl = c;
	return (1);
}

void		draw_3d(t_param p, t_pointcol **r)
{
	t_fpoint		**p2;
	t_point			p1[2];
	int				i;
	int				j;
	unsigned	int	cl[2];

	p2 = ft_initp2d(r);
	j = -1;
	while (r[++j] != NULL && (i = -1) == -1)
		while (r[j][++i].pos.x != -1)
			if (ft_projec(p, r[j][i].pos, p2[j] + i) && (p2[j][i].x = -1) == -1)
				p2[j][i].y = -1;
			else
			{
				p_dr(p1, p2[j][i], cl, r[j][i].col);
				fill_pixel(p, p1[0], cl[0]);
				if (i > 0 && p_dr(p1 + 1, p2[j][i - 1], cl + 1, r[j][i - 1].col)
				&& p1[1].x != -1)
					draw_line(p, p1[0], p1[1], cl);
				if (j > 0 && p_dr(p1 + 1, p2[j - 1][i], cl + 1, r[j - 1][i].col)
				&& p1[1].x != -1)
					draw_line(p, p1[0], p1[1], cl);
			}
	freep2d(r, p2);
}

void		ft_printmap(t_pointcol ***res, int dist, int w, int h)
{
	t_param	p;

	p.s.x = w;
	p.s.y = h;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, p.s.x, p.s.y, "fdf");
	p.img.img = mlx_new_image(p.mlx, p.s.x, p.s.y);
	p.img.str = mlx_get_data_addr(p.img.img, &(p.img.bpp)
		, &(p.img.s_l), &(p.img.endian));
	p.res = res;
	p.cam.horiangle = 0;
	p.cam.vertangle = 0;
	p.cam.pos.x = 0;
	p.cam.pos.y = dist;
	p.cam.pos.z = dist;
	p.cam.targ.x = 0;
	p.cam.targ.y = 0;
	p.cam.targ.z = 0;
	p.cam.p_screen.x = (h > w) ? 2 * (float)w / h : 2;
	p.cam.p_screen.y = (h > w) ? 2 : 2 * (float)h / w;
	ft_camera(&p);
	draw_3d(p, *(p.res));
	mlx_put_image_to_window(&p, p.win, p.img.img, 0, 0);
	mlx_hook(p.win, 2, 0, key_funct, &p);
	mlx_loop(p.mlx);
}
