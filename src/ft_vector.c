/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:03:28 by emarin            #+#    #+#             */
/*   Updated: 2017/12/13 17:03:29 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_fpoint	ft_segmtovect(t_fpoint a, t_fpoint b)
{
	t_fpoint	res;

	res.x = b.x - a.x;
	res.y = b.y - a.y;
	res.z = b.z - a.z;
	return (res);
}

t_fpoint	ft_normalize(t_fpoint v)
{
	t_fpoint	res;
	float		len;
	float		inv_len;

	len = v.x * v.x + v.y * v.y + v.z * v.z;
	if (len > 0)
	{
		inv_len = 1.0 / sqrt(len);
		res.x = v.x * inv_len;
		res.y = v.y * inv_len;
		res.z = v.z * inv_len;
	}
	else
		return (v);
	return (res);
}

float		ft_dot(t_fpoint a, t_fpoint b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_fpoint	ft_cross(t_fpoint a, t_fpoint b)
{
	t_fpoint	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}
