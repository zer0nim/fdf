/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:33:13 by emarin            #+#    #+#             */
/*   Updated: 2017/12/14 11:46:28 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_free_param(t_param *p, int mode)
{
	ft_free_res(p->res, -2);
	ft_freematrix(p->cam.cam, 4);
	if (mode == 1)
		ft_freematrix(p->cam.wtocam, 4);
}
