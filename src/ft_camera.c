/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:46:22 by emarin            #+#    #+#             */
/*   Updated: 2017/12/14 15:07:36 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	**ft_fillcam_matrix(t_fpoint *fru, t_param *p)
{
	float		**cam;

	if (!(cam = ft_newmatrix(4, 4)))
		return (NULL);
	cam[0][0] = fru[1].x;
	cam[0][1] = fru[2].x;
	cam[0][2] = fru[0].x;
	cam[0][3] = p->cam.pos.x;
	cam[1][0] = fru[1].y;
	cam[1][1] = fru[2].y;
	cam[1][2] = fru[0].y;
	cam[1][3] = p->cam.pos.y;
	cam[2][0] = fru[1].z;
	cam[2][1] = fru[2].z;
	cam[2][2] = fru[0].z;
	cam[2][3] = p->cam.pos.z;
	cam[3][0] = 0;
	cam[3][1] = 0;
	cam[3][2] = 0;
	cam[3][3] = 1;
	return (cam);
}

void	ft_cam_exeption(t_fpoint *fru)
{
	fru[1].x = 1;
	fru[1].y = 0;
	fru[1].z = 0;
	fru[2].x = 0;
	fru[2].y = 0;
	fru[2].z = fru[0].y;
}

void	ft_camera(t_param *p)
{
	float		**cam;
	float		**wtocam;
	t_fpoint	fru[3];
	t_fpoint	tmp;

	fru[0] = ft_normalize(ft_segmtovect(p->cam.targ, p->cam.pos));
	if (fru[0].x == 0 && fru[0].z == 0)
		ft_cam_exeption(fru);
	else
	{
		tmp.x = 0;
		tmp.y = 1;
		tmp.z = 0;
		fru[1] = ft_normalize(ft_cross(tmp, fru[0]));
		fru[2] = ft_normalize(ft_cross(fru[0], fru[1]));
	}
	if (!(cam = ft_fillcam_matrix(fru, p)))
		return ;
	p->cam.cam = cam;
	if (!(wtocam = ft_invertmatrix(cam, 4)))
	{
		ft_free_param(p, 2);
		exit(0);
	}
	p->cam.wtocam = wtocam;
}

void	ft_movecamera(t_param *p)
{
	ft_freematrix(p->cam.cam, 4);
	ft_freematrix(p->cam.wtocam, 4);
	ft_camera(p);
}
