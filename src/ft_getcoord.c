/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcoord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:09:58 by emarin            #+#    #+#             */
/*   Updated: 2017/12/15 17:52:48 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int				ft_realloc(t_pointcol ***res, int len)
{
	int			i;
	t_pointcol	**ret;

	if (len > 2)
	{
		if (!(ret = (t_pointcol **)malloc(sizeof(t_pointcol *) * (len))))
			return (-1);
		i = 0;
		while ((*res)[i] != NULL)
		{
			ret[i] = (*res)[i];
			i++;
		}
		free(*res);
		*res = ret;
	}
	return (0);
}

void			ft_freesplit(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
}

int				ft_storecoord(char **s, t_pointcol **res, int j)
{
	int				i;
	unsigned	int	col;

	if (!(res[j] = (t_pointcol *)malloc(sizeof(t_pointcol) * (ft_tlen(s) + 1))))
		return (-1);
	i = 0;
	while (s[i])
	{
		res[j][i].pos.x = i * C_S;
		res[j][i].pos.y = ft_atoi(s[i]) * C_S;
		res[j][i].pos.z = (j) * C_S;
		res[j][i].col = 0xffffff00;
		if (ft_strchr(s[i], ',') != NULL)
		{
			col = ft_atoi_base(ft_strchr(s[i], ',') + 3, 16) << 8;
			col = ((col & 0x0000ff00) << 16) | ((col & 0xff000000) >> 16)
				| (col & 0x00ff0000);
			res[j][i].col = col;
		}
		++i;
	}
	res[j][i].pos.x = -1;
	res[j + 1] = NULL;
	return (0);
}

int				ft_err(char *er, int code)
{
	ft_putstr(er);
	return (code);
}

int				ft_getcoord(const char *name, t_pointcol ***res, int *dist
	, int j)
{
	int		fd;
	char	*ln;
	char	**split;
	int		gnlr;

	if (!((*res) = (t_pointcol **)malloc(sizeof(t_pointcol *) * 2))
		|| (fd = open(name, O_RDONLY)) == -1)
		return (ft_err("error\n", -1));
	(*res)[0] = NULL;
	while ((gnlr = get_next_line(fd, &ln)))
	{
		if (ln == NULL)
			return (ft_err("error\n", -2));
		ft_realloc(res, ++j + 2);
		split = ft_strsplit(ln, ' ');
		if (ft_storecoord(split, *res, j) == -1)
			return (ft_err("error\n", -2));
		ft_freesplit(split);
		free(ln);
	}
	free(ln);
	if (gnlr == -1 || close(fd) == -1 || ft_verifmap(*res)
		|| (*dist = ft_centercoord(*res)) == -1)
		return (ft_err("error\n", -2));
	return (0);
}
