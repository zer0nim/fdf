/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invertmatrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:31:58 by emarin            #+#    #+#             */
/*   Updated: 2017/12/14 15:07:31 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_minor(float **src, float **dest, int row_col[2], int n)
{
	int	col_cnt;
	int	row_cnt;
	int ij[2];

	col_cnt = 0;
	row_cnt = 0;
	ij[0] = 0;
	while (ij[0] < n)
	{
		if (ij[0] != row_col[0])
		{
			col_cnt = 0;
			ij[1] = 0;
			while (ij[1] < n)
			{
				if (ij[1] != row_col[1])
					dest[row_cnt][col_cnt++] = src[ij[0]][ij[1]];
				(ij[1])++;
			}
			row_cnt++;
		}
		++(ij[0]);
	}
	return (1);
}

float	ft_determina(float **mat, int n, int *verif)
{
	int		i;
	float	**minor;
	float	det;
	int		row_col[2];

	*verif = 0;
	det = 0;
	if (n == 1)
		return (mat[0][0]);
	if (!(minor = ft_newmatrix(n - 1, n - 1))
		&& (*verif = -1) == -1)
		return (det);
	i = -1;
	while (++i < n)
	{
		row_col[0] = 0;
		row_col[1] = i;
		ft_minor(mat, minor, row_col, n);
		det += ((i % 2 == 1) ? -1.0 : 1.0) * mat[0][i]
			* ft_determina(minor, n - 1, verif);
		if (*verif == -1)
			return (det);
	}
	ft_freematrix(minor, n - 1);
	return (det);
}

float	**ft_invertmatrix(float **m, int n)
{
	float	det;
	float	**mat;
	float	**minor;
	int		ji[2];
	int		row_col_v[3];

	det = 1.0 / ft_determina(m, n, row_col_v + 2);
	if (row_col_v[2] == -1 || !(minor = ft_newmatrix(n - 1, n - 1))
		|| !(mat = ft_newmatrix(n, n)))
		return (NULL);
	ji[0] = -1;
	while (++(ji[0]) < n && (ji[1] = -1) == -1)
		while (++(ji[1]) < n)
		{
			row_col_v[0] = ji[0];
			row_col_v[1] = ji[1];
			ft_minor(m, minor, row_col_v, n);
			mat[ji[1]][ji[0]] = det * ft_determina(minor, n - 1, row_col_v + 2);
			if (row_col_v[2] == -1)
				return (NULL);
			if ((ji[1] + ji[0]) % 2 == 1)
				mat[ji[1]][ji[0]] = -mat[ji[1]][ji[0]];
		}
	ft_freematrix(minor, n - 1);
	return (mat);
}
