/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:04:23 by emarin            #+#    #+#             */
/*   Updated: 2017/11/11 12:06:44 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, \
size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (unsigned char)((char*)src)[i] != (unsigned char)c)
	{
		((char*)dst)[i] = (unsigned char)((char*)src)[i];
		i++;
	}
	if (i < n && (unsigned char)((char*)src)[i] == (unsigned char)c)
	{
		((char*)dst)[i] = (unsigned char)((char*)src)[i];
		return (dst + i + 1);
	}
	return (NULL);
}
