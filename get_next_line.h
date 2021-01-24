/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojikim <woojikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 10:13:16 by woojikim          #+#    #+#             */
/*   Updated: 2021/01/03 20:08:04 by woojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"
# include "stdio.h"
# include "limits.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

int			get_next_line(int fd, char **line);
char		*ft_strldup(const char *s1, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);

#endif
