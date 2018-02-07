/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commonmatrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:36:43 by emarin            #+#    #+#             */
/*   Updated: 2017/12/14 20:42:06 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_matrix_roty(float **mt, float rangle)
{
	mt[0][0] = cos(rangle);
	mt[0][1] = 0;
	mt[0][2] = -sin(rangle);
	mt[0][3] = 0;
	mt[1][0] = 0;
	mt[1][1] = 1;
	mt[1][2] = 0;
	mt[1][3] = 0;
	mt[2][0] = sin(rangle);
	mt[2][1] = 0;
	mt[2][2] = cos(rangle);
	mt[2][3] = 0;
	mt[3][0] = 0;
	mt[3][1] = 0;
	mt[3][2] = 0;
	mt[3][3] = 1;
}

void	ft_matrix_rotx(float **mt, float rangle)
{
	mt[0][0] = 1;
	mt[0][1] = 0;
	mt[0][2] = 0;
	mt[0][3] = 0;
	mt[1][0] = 0;
	mt[1][1] = cos(rangle);
	mt[1][2] = sin(rangle);
	mt[1][3] = 0;
	mt[2][0] = 0;
	mt[2][1] = -sin(rangle);
	mt[2][2] = cos(rangle);
	mt[2][3] = 0;
	mt[3][0] = 0;
	mt[3][1] = 0;
	mt[3][2] = 0;
	mt[3][3] = 1;
}

void	ft_rot_trslt(t_param *p, float **mt, char fromto)
{
	mt[0][0] = 1;
	mt[0][1] = 0;
	mt[0][2] = 0;
	mt[0][3] = (fromto) ? -p->cam.pos.x : p->cam.pos.x;
	mt[1][0] = 0;
	mt[1][1] = 1;
	mt[1][2] = 0;
	mt[1][3] = (fromto) ? -p->cam.pos.y : p->cam.pos.y;
	mt[2][0] = 0;
	mt[2][1] = 0;
	mt[2][2] = 1;
	mt[2][3] = (fromto) ? -p->cam.pos.z : p->cam.pos.z;
	mt[3][0] = 0;
	mt[3][1] = 0;
	mt[3][2] = 1;
	mt[3][3] = 1;
}

void	ft_setmp(float **mp, float x, float y, float z)
{
	mp[0][0] = x;
	mp[1][0] = y;
	mp[2][0] = z;
	mp[3][0] = 1;
}
