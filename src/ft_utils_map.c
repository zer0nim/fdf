/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:54:03 by emarin            #+#    #+#             */
/*   Updated: 2017/12/13 16:54:55 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int				ft_tlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int				ft_verifmap(t_pointcol **res)
{
	int	i;
	int	j;
	int	len;

	len = -1;
	j = 0;
	while (res[j] != NULL)
	{
		i = 0;
		while (res[j][i].pos.x != -1)
			++i;
		if (len != -1 && len != i)
			return (1);
		len = i;
		++j;
	}
	return (0);
}

void			ft_size_res(t_pointcol **res, int **mnx, int *w, int *h)
{
	(*mnx)[0] = 0;
	(*mnx)[1] = 0;
	*h = 0;
	while (res[*h] != NULL)
	{
		*w = 0;
		while (res[*h][*w].pos.x != -1)
		{
			(*mnx)[0] = (res[*h][*w].pos.y
				< (*mnx)[0]) ? res[*h][*w].pos.y : (*mnx)[0];
			(*mnx)[1] = (res[*h][*w].pos.y
				> (*mnx)[1]) ? res[*h][*w].pos.y : (*mnx)[1];
			++(*w);
		}
		++(*h);
	}
}

int				ft_centercoord(t_pointcol **res)
{
	int	i;
	int	j;
	int	w;
	int	h;
	int	*mnx;

	if (!(mnx = (int*)malloc(sizeof(int) * 2)))
		return (-1);
	ft_size_res(res, &mnx, &w, &h);
	mnx[0] = (ft_abs(mnx[0]) + ft_abs(mnx[1])) / 2;
	j = -1;
	while (res[++j] != NULL)
	{
		i = 0;
		while (res[j][i].pos.x != -1)
		{
			res[j][i].pos.x = res[j][i].pos.x - (((w - 1) * C_S) / 2);
			res[j][i].pos.y = res[j][i].pos.y - mnx[0];
			res[j][i].pos.z = -((((h - 1) * C_S)
				- res[j][i].pos.z) - (((h - 1) * C_S) / 2));
			++i;
		}
	}
	free(mnx);
	return (fmax(mnx[0], fmax((((w - 1) * C_S) / 2), (((h - 1) * C_S) / 2))));
}
