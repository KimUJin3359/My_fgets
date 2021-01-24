/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojikim <woojikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 10:16:57 by woojikim          #+#    #+#             */
/*   Updated: 2021/01/03 20:43:30 by woojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strldup(const char *s1, size_t size)
{
	char	*dst;
	size_t	i;

	if (!(dst = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	if (size)
	{
		while ((i < size - 1) && s1 && s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	if (!(dst = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	if (s1 != NULL)
		free(s1);
	j = 0;
	while (s2 && s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
