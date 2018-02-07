/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lookat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:18:07 by emarin            #+#    #+#             */
/*   Updated: 2017/12/14 20:41:59 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_prepare_rott(t_param *p, float **mp, float **mt, int start)
{
	float **res;

	if (start)
	{
		ft_setmp(mp, p->cam.targ.x, p->cam.targ.y, p->cam.targ.z);
		ft_rot_trslt(p, mt, 1);
		res = ft_mutmatrix(mt, mp, 1, 4);
		ft_setmp(mp, res[0][0], res[1][0], res[2][0]);
		ft_freematrix(res, 4);
	}
	else
	{
		ft_rot_trslt(p, mt, 0);
		res = ft_mutmatrix(mt, mp, 1, 4);
		p->cam.targ.x = res[0][0];
		p->cam.targ.y = res[1][0];
		p->cam.targ.z = res[2][0];
		ft_freematrix(res, 4);
	}
}

void	ft_roll_targ(t_param *p, float **mp, float **mt, int coef)
{
	float	**res;
	float	rangle2;
	float	rangle;

	rangle = coef * (M_PI / 180);
	p->cam.vertangle = (p->cam.vertangle + coef) % 360;
	rangle2 = -p->cam.horiangle * (M_PI / 180);
	ft_matrix_roty(mt, rangle2);
	res = ft_mutmatrix(mt, mp, 1, 4);
	ft_setmp(mp, res[0][0], res[1][0], res[2][0]);
	ft_freematrix(res, 4);
	ft_matrix_rotx(mt, rangle);
	res = ft_mutmatrix(mt, mp, 1, 4);
	ft_setmp(mp, res[0][0], res[1][0], res[2][0]);
	ft_freematrix(res, 4);
	ft_matrix_roty(mt, -rangle2);
	res = ft_mutmatrix(mt, mp, 1, 4);
	ft_setmp(mp, res[0][0], res[1][0], res[2][0]);
	ft_freematrix(res, 4);
}

void	ft_tilt_targ(t_param *p, float **mp, float **mt, int coef)
{
	float	**res;
	float	rangle;

	rangle = coef * (M_PI / 180);
	p->cam.horiangle = (p->cam.horiangle + coef) % 360;
	ft_matrix_roty(mt, rangle);
	res = ft_mutmatrix(mt, mp, 1, 4);
	ft_setmp(mp, res[0][0], res[1][0], res[2][0]);
	ft_freematrix(res, 4);
}

int		ft_rotate_target(t_param *p, int roll, int back, int coef)
{
	float	**mp;
	float	**mt;

	if (!(mp = ft_newmatrix(1, 4)))
		return (0);
	if (!(mt = ft_newmatrix(4, 4)))
	{
		free(mp);
		return (0);
	}
	ft_prepare_rott(p, mp, mt, 1);
	if (roll)
		ft_roll_targ(p, mp, mt, ((back) ? -coef : coef));
	else
		ft_tilt_targ(p, mp, mt, ((back) ? -coef : coef));
	ft_prepare_rott(p, mp, mt, 0);
	ft_freematrix(mp, 4);
	ft_freematrix(mt, 4);
	ft_movecamera(p);
	return (0);
}

int		ft_lookat(t_param *p, int forw, int back)
{
	mlx_destroy_image(p->mlx, p->img.img);
	p->img.img = mlx_new_image(p->mlx, p->s.x, p->s.y);
	p->img.str = mlx_get_data_addr(p->img.img, &(p->img.bpp), &(p->img.s_l)
		, &(p->img.endian));
	if (forw)
	{
		if (back)
			ft_rotate_target(p, 1, 0, 3);
		else
			ft_rotate_target(p, 1, 1, 3);
	}
	else
	{
		if (back)
			ft_rotate_target(p, 0, 1, 3);
		else
			ft_rotate_target(p, 0, 0, 3);
	}
	ft_movecamera(p);
	draw_3d(*p, *(p->res));
	mlx_put_image_to_window(&p, p->win, p->img.img, 0, 0);
	return (0);
}
