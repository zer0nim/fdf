/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:49:40 by emarin            #+#    #+#             */
/*   Updated: 2017/11/13 16:08:12 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;
	char	*dest;

	if (NULL == (new_list = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	else
	{
		dest = ft_memalloc(content_size);
		ft_memcpy(dest, content, content_size);
		new_list->content = dest;
		new_list->content_size = content_size;
	}
	new_list->next = NULL;
	return (new_list);
}
