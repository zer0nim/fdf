/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:19:48 by emarin            #+#    #+#             */
/*   Updated: 2017/12/15 17:52:54 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			ft_free_res(t_pointcol ***res, int code)
{
	int j;

	j = 0;
	if (code == -2)
	{
		while ((*res)[j] != NULL)
		{
			free((*res)[j]);
			++j;
		}
		free((*res));
	}
	free(res);
}

void			call_render(int argc, char **argv, t_pointcol ***res, int dist)
{
	int	w;
	int	h;

	if (argc == 4)
	{
		w = ft_atoi(argv[2]);
		h = ft_atoi(argv[3]);
	}
	if (argc == 4 && !(w > 2560 || w < 1 || h > 1440 || h < 1))
		ft_printmap(res, dist, w, h);
	else
		ft_printmap(res, dist, 640, 360);
}

int				main(int argc, char **argv)
{
	int			code;
	int			dist;
	t_pointcol	***res;

	if (!(res = (t_pointcol ***)malloc(sizeof(t_pointcol **))))
		return (1);
	if (argc == 2 || argc == 4)
	{
		if ((code = ft_getcoord(argv[1], res, &dist, -1)) != 0)
		{
			ft_free_res(res, code);
			return (1);
		}
		call_render(argc, argv, res, dist);
	}
	else
	{
		ft_putstr("usage: fdf source_file [width height]\n");
		ft_free_res(res, -1);
	}
	return (0);
}
