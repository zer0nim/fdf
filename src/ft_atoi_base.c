/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:48:47 by emarin            #+#    #+#             */
/*   Updated: 2017/12/09 17:42:44 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static	int	ft_corec_v(char c, int str_base)
{
	char	cbase[17];
	int		i;

	ft_strcpy(cbase, "0123456789abcdef");
	i = -1;
	while (++i < str_base)
		if (ft_tolower(c) == cbase[i])
			return (1);
	return (0);
}

static	int	ft_getnb(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (c - 'a' + 10);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int		sign;
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		++i;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		sign = (str[i] == '-') ? -1 : 1;
		++i;
	}
	while (str[i] && ft_corec_v(str[i], str_base))
	{
		nb *= str_base;
		nb += ft_getnb(ft_tolower(str[i]));
		++i;
	}
	return (nb * sign);
}
