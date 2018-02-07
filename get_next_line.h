/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:01:25 by emarin            #+#    #+#             */
/*   Updated: 2017/11/24 15:27:24 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 9999

typedef struct		s_line
{
	int		fd;
	int		i;
	char	*buff;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
