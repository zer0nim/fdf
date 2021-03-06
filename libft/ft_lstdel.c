/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:07:17 by emarin            #+#    #+#             */
/*   Updated: 2017/11/13 15:28:05 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *to_free;

	if (alst != NULL)
	{
		while (*alst != NULL)
		{
			to_free = *alst;
			*alst = (*alst)->next;
			del(to_free->content, to_free->content_size);
			free(to_free);
		}
	}
}
