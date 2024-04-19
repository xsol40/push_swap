/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:26:21 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/03/22 21:55:03 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include "../src/push_swap.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strncmp(char *s1, char *s2, int size);

#endif
