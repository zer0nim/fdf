/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:07:03 by emarin            #+#    #+#             */
/*   Updated: 2017/12/15 15:48:44 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_freematrix(float **m, int height)
{
	int j;

	j = 0;
	while (j < height)
	{
		free(m[j]);
		++j;
	}
	free(m);
}

float		**ft_newmatrix(int width, int height)
{
	float	**res;
	int		j;
	int		i;

	if (!(res = (float **)malloc(sizeof(float *) * height)))
		return (NULL);
	j = 0;
	while (j < height)
	{
		if (!(res[j] = (float *)malloc(sizeof(float) * width)))
			return (NULL);
		i = 0;
		while (i < width)
			res[j][i++] = 0.0;
		j++;
	}
	return (res);
}

float		**ft_mutmatrix(float **mt, float **mp, int width, int height)
{
	t_point	p;
	t_point	t;
	float	**res;

	if (!(res = ft_newmatrix(width, height)))
		return (NULL);
	p.x = 0;
	while (p.x < width)
	{
		t.y = 0;
		while (t.y < height)
		{
			p.y = 0;
			t.x = 0;
			while (p.y < height)
			{
				res[t.y][p.x] += mt[t.y][t.x] * mp[p.y][p.x];
				++(p.y);
				++(t.x);
			}
			++(t.y);
		}
		++(p.x);
	}
	return (res);
}
