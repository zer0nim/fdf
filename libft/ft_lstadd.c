/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:19:01 by emarin            #+#    #+#             */
/*   Updated: 2017/11/25 14:04:08 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new != NULL)
	{
		if (alst != NULL)
			new->next = *alst;
		*alst = new;
	}
}
