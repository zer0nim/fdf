/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:55:30 by emarin            #+#    #+#             */
/*   Updated: 2017/12/14 18:30:57 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_behind_camera(t_param p, t_point p3d)
{
	t_fpoint	fp3d;
	float		res;

	fp3d.x = p3d.x;
	fp3d.y = p3d.y;
	fp3d.z = p3d.z;
	res = ft_dot(ft_normalize(ft_segmtovect(p.cam.pos, p.cam.targ))
		, ft_normalize(ft_segmtovect(p.cam.pos, fp3d)));
	return (res < 0);
}

int		ft_p_err(float **mp)
{
	ft_freematrix(mp, 4);
	return (1);
}

int		ft_projec(t_param p, t_point p3d, t_fpoint *p2d)
{
	float	**res;
	float	**mp;

	if (!(mp = ft_newmatrix(1, 4)))
		return (1);
	if (ft_behind_camera(p, p3d))
		return (ft_p_err(mp));
	mp[0][0] = p3d.x;
	mp[1][0] = p3d.y;
	mp[2][0] = p3d.z;
	mp[3][0] = 1;
	res = ft_mutmatrix(p.cam.wtocam, mp, 1, 4);
	p2d->x = res[0][0] / ((res[2][0] != 0) ? -res[2][0] : -1);
	p2d->y = res[1][0] / ((res[2][0] != 0) ? -res[2][0] : -1);
	ft_freematrix(res, 4);
	if (p2d->x > (p.cam.p_screen.x / 2) || p2d->x < -(p.cam.p_screen.x / 2)
		|| p2d->y > (p.cam.p_screen.y / 2) || p2d->y < -(p.cam.p_screen.y / 2))
		return (ft_p_err(mp));
	p2d->x = (p2d->x + p.cam.p_screen.x / 2) / p.cam.p_screen.x;
	p2d->y = (p2d->y + p.cam.p_screen.y / 2) / p.cam.p_screen.y;
	p2d->x = floor(p2d->x * p.s.x);
	p2d->y = floor((1 - p2d->y) * p.s.y);
	ft_freematrix(mp, 4);
	return (0);
}
