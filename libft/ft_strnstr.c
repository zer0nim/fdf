/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:45:05 by emarin            #+#    #+#             */
/*   Updated: 2017/11/10 14:42:10 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t lenhay;
	size_t lenneedle;

	lenhay = ft_strlen((char *)haystack);
	lenneedle = ft_strlen((char *)needle);
	if (lenneedle <= 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len && lenneedle <= (lenhay - i))
	{
		j = 0;
		while (needle[j] != '\0' && i < len && haystack[i] == needle[j])
		{
			j++;
			i++;
		}
		i = i - j;
		if (needle[j] == '\0')
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
