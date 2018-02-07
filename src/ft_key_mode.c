/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:45:16 by emarin            #+#    #+#             */
/*   Updated: 2017/12/14 20:46:08 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	flymode(int keycode, t_param *p)
{
	if (keycode == 126)
		ft_lookat(p, 1, 0);
	if (keycode == 125)
		ft_lookat(p, 1, 1);
	if (keycode == 123)
		ft_lookat(p, 0, 1);
	if (keycode == 124)
		ft_lookat(p, 0, 0);
	if (keycode == 13)
		ft_fly(p, 1, 0);
	if (keycode == 1)
		ft_fly(p, 1, 1);
	if (keycode == 0)
		ft_fly(p, 0, 1);
	if (keycode == 2)
		ft_fly(p, 0, 0);
	if (keycode == 12)
		ft_fly(p, 2, 1);
	if (keycode == 14)
		ft_fly(p, 2, 0);
}

void	fov(int keycode, t_param *p)
{
	if (keycode == 69)
	{
		mlx_destroy_image(p->mlx, p->img.img);
		p->img.img = mlx_new_image(p->mlx, p->s.x, p->s.y);
		p->img.str = mlx_get_data_addr(p->img.img, &(p->img.bpp), &(p->img.s_l)
			, &(p->img.endian));
		p->cam.p_screen.x = p->cam.p_screen.x * 0.9;
		p->cam.p_screen.y = p->cam.p_screen.y * 0.9;
		draw_3d(*p, *(p->res));
		mlx_put_image_to_window(&p, p->win, p->img.img, 0, 0);
	}
	if (keycode == 78)
	{
		mlx_destroy_image(p->mlx, p->img.img);
		p->img.img = mlx_new_image(p->mlx, p->s.x, p->s.y);
		p->img.str = mlx_get_data_addr(p->img.img, &(p->img.bpp), &(p->img.s_l)
			, &(p->img.endian));
		p->cam.p_screen.x = p->cam.p_screen.x * 1.1;
		p->cam.p_screen.y = p->cam.p_screen.y * 1.1;
		draw_3d(*p, *(p->res));
		mlx_put_image_to_window(&p, p->win, p->img.img, 0, 0);
	}
}

int		key_funct(int keycode, void *param)
{
	t_param	*p;

	p = ((t_param*)param);
	if (keycode == 53)
	{
		ft_free_param(p, 1);
		exit(0);
	}
	fov(keycode, p);
	flymode(keycode, p);
	return (0);
}
