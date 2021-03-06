/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:20:03 by emarin            #+#    #+#             */
/*   Updated: 2017/11/11 16:05:11 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (unsigned char)((char*)s)[i] != (unsigned char)c)
		i++;
	if (i < n && (unsigned char)((char*)s)[i] == (unsigned char)c)
		return (((char*)s) + i);
	return (NULL);
}
