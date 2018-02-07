/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:22:04 by emarin            #+#    #+#             */
/*   Updated: 2017/11/27 20:24:57 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list *start;

	if (alst != NULL)
	{
		if (*alst == NULL)
		{
			*alst = new;
			return ;
		}
		start = *alst;
		while ((*alst)->next != 0)
			(*alst) = (*alst)->next;
		(*alst)->next = new;
		(*alst) = start;
	}
}
