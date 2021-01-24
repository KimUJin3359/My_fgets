/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojikim <woojikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 10:15:27 by woojikim          #+#    #+#             */
/*   Updated: 2021/01/03 20:37:06 by woojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_line(char *file)
{
	int	i;

	i = 0;
	while (file && file[i])
	{
		if (file[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		ft_get_line(char **file, char **line, int i)
{
	char	*temp;

	*line = ft_strldup(*file, i + 1);
	temp = ft_strdup(*file + i + 1);
	free(*file);
	*file = temp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*file[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((i = ft_check_line(file[fd])) != -1)
		return (ft_get_line(&file[fd], line, i));
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = 0;
		file[fd] = ft_strjoin(file[fd], buf);
		if ((i = ft_check_line(file[fd])) != -1)
			return (ft_get_line(&file[fd], line, i));
	}
	if (ret < 0)
		return (-1);
	if (file[fd])
		*line = file[fd];
	else
		*line = ft_strdup("");
	file[fd] = NULL;
	return (0);
}
