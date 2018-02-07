/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:42:35 by emarin            #+#    #+#             */
/*   Updated: 2017/12/14 18:25:20 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fill_pixel(t_param p, t_point t, unsigned int c)
{
	if (t.x > 0 && t.y > 0 && t.x < p.s.x && t.y < p.s.y)
	{
		p.img.str[(t.y * p.img.s_l) + (t.x * 4)] = ((c & 0xff000000) >> 24);
		p.img.str[(t.y * p.img.s_l) + (t.x * 4) + 1] = ((c & 0x00ff0000) >> 16);
		p.img.str[(t.y * p.img.s_l) + (t.x * 4) + 2] = ((c & 0x0000ff00) >> 8);
		p.img.str[(t.y * p.img.s_l) + (t.x * 4) + 3] = (c & 0x000000ff);
	}
}

t_img	draw_line_case1(t_param p, t_point strt, t_point end, unsigned int c[2])
{
	t_point			p1;
	int				x;
	int				i;
	int				pbgr[4];
	unsigned	int	res;

	i = 0;
	pbgr[3] = ((end.x - strt.x) > 0) ? (end.x - strt.x) : 1;
	pbgr[0] = (int)(((c[1] & 0xff000000) >> 24) - ((c[0] & 0xff000000) >> 24));
	pbgr[1] = (int)(((c[1] & 0x00ff0000) >> 16) - ((c[0] & 0x00ff0000) >> 16));
	pbgr[2] = (int)(((c[1] & 0x0000ff00) >> 8) - ((c[0] & 0x0000ff00) >> 8));
	x = strt.x - 1;
	while (++x <= end.x)
	{
		res = ((((c[0] & 0xff000000) >> 24) + (pbgr[0] * i / pbgr[3])) << 24)
			| ((((c[0] & 0x00ff0000) >> 16) + (pbgr[1] * i / pbgr[3])) << 16)
			| ((((c[0] & 0x0000ff00) >> 8) + (pbgr[2] * i / pbgr[3])) << 8);
		p1.x = x;
		p1.y = strt.y + (((end.y - strt.y) * (x - strt.x) != 0)
			? (end.y - strt.y) * (x - strt.x) : 1)
			/ (((end.x - strt.x) != 0) ? (end.x - strt.x) : 1);
		fill_pixel(p, p1, res);
		++i;
	}
	return (p.img);
}

t_img	draw_line_case2(t_param p, t_point strt, t_point end, unsigned int c[2])
{
	t_point			p1;
	int				y;
	int				i;
	int				pbgr[4];
	unsigned int	res;

	i = 0;
	pbgr[3] = ((end.y - strt.y) > 0) ? (end.y - strt.y) : 1;
	pbgr[0] = (int)(((c[1] & 0xff000000) >> 24) - ((c[0] & 0xff000000) >> 24));
	pbgr[1] = (int)(((c[1] & 0x00ff0000) >> 16) - ((c[0] & 0x00ff0000) >> 16));
	pbgr[2] = (int)(((c[1] & 0x0000ff00) >> 8) - ((c[0] & 0x0000ff00) >> 8));
	y = strt.y - 1;
	while (++y <= end.y)
	{
		res = ((((c[0] & 0xff000000) >> 24) + (pbgr[0] * i / pbgr[3])) << 24)
			| ((((c[0] & 0x00ff0000) >> 16) + (pbgr[1] * i / pbgr[3])) << 16)
			| ((((c[0] & 0x0000ff00) >> 8) + (pbgr[2] * i / pbgr[3])) << 8);
		p1.y = y;
		p1.x = strt.x + (((end.x - strt.x) * (y - strt.y) != 0)
			? (end.x - strt.x) * (y - strt.y) : 0)
			/ (((end.y - strt.y) != 0) ? (end.y - strt.y) : 1);
		fill_pixel(p, p1, (res));
		++i;
	}
	return (p.img);
}

int		ft_invertcol(unsigned int **c)
{
	unsigned int tmp;

	tmp = (*c)[0];
	(*c)[0] = (*c)[1];
	(*c)[1] = tmp;
	return (1);
}

t_img	draw_line(t_param p, t_point strt, t_point end, unsigned int c[2])
{
	if (strt.x <= end.x)
	{
		if ((end.x - strt.x) >= (int)ft_abs(end.y - strt.y))
			return (draw_line_case1(p, strt, end, c));
		else if (strt.y <= end.y)
			return (draw_line_case2(p, strt, end, c));
		else if (ft_invertcol(&c))
			return (draw_line_case2(p, end, strt, c));
	}
	else
	{
		if ((int)ft_abs(end.x - strt.x) >= (int)ft_abs(end.y - strt.y)
			&& ft_invertcol(&c))
			return (draw_line_case1(p, end, strt, c));
		else if (strt.y <= end.y)
			return (draw_line_case2(p, strt, end, c));
		else if (ft_invertcol(&c))
			return (draw_line_case2(p, end, strt, c));
	}
	return (p.img);
}
