/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:38:51 by emarin            #+#    #+#             */
/*   Updated: 2017/12/14 20:39:03 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_cam_forw(t_param *p, float coef)
{
	t_fpoint v;

	v = ft_normalize(ft_segmtovect(p->cam.pos, p->cam.targ));
	p->cam.pos.x += (v.x * coef);
	p->cam.pos.y += (v.y * coef);
	p->cam.pos.z += (v.z * coef);
	p->cam.targ.x += (v.x * coef);
	p->cam.targ.y += (v.y * coef);
	p->cam.targ.z += (v.z * coef);
}

void	ft_cam_up(t_param *p, float coef)
{
	t_fpoint v;

	v.x = p->cam.cam[0][1];
	v.y = p->cam.cam[1][1];
	v.z = p->cam.cam[2][1];
	p->cam.pos.x += (v.x * coef);
	p->cam.pos.y += (v.y * coef);
	p->cam.pos.z += (v.z * coef);
	p->cam.targ.x += (v.x * coef);
	p->cam.targ.y += (v.y * coef);
	p->cam.targ.z += (v.z * coef);
}

void	ft_cam_side(t_param *p, float coef)
{
	t_fpoint v;

	v.x = p->cam.cam[0][0];
	v.y = p->cam.cam[1][0];
	v.z = p->cam.cam[2][0];
	p->cam.pos.x += (v.x * coef);
	p->cam.pos.y += (v.y * coef);
	p->cam.pos.z += (v.z * coef);
	p->cam.targ.x += (v.x * coef);
	p->cam.targ.y += (v.y * coef);
	p->cam.targ.z += (v.z * coef);
}

int		ft_fly(t_param *p, int dir, int back)
{
	float	coef;

	if (back)
		coef = -600;
	else
		coef = 600;
	mlx_destroy_image(p->mlx, p->img.img);
	p->img.img = mlx_new_image(p->mlx, p->s.x, p->s.y);
	p->img.str = mlx_get_data_addr(p->img.img, &(p->img.bpp), &(p->img.s_l)
		, &(p->img.endian));
	if (dir == 1)
		ft_cam_forw(p, coef);
	else if (dir == 2)
		ft_cam_up(p, coef);
	else
		ft_cam_side(p, coef);
	ft_movecamera(p);
	draw_3d(*p, *(p->res));
	mlx_put_image_to_window(&p, p->win, p->img.img, 0, 0);
	return (0);
}
