/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacopo <jacopo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:30:53 by jacopo            #+#    #+#             */
/*   Updated: 2023/02/24 17:52:50 by jacopo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_info(int fd, char *raw)
{
	ssize_t		byte;
	char		*buf;

	byte = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (byte != 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[byte] = '\0';
		if (!raw)
			raw = ft_strdup("");
		raw = ft_strjoin(raw, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (raw);
}

char	*ft_clean(const char *raw, int *i)
{
	int		j;
	int		pos;
	char	*str;

	pos = *i;
	j = 0;
	if (!raw[pos])
		return (NULL);
	if (!ft_strchr(raw, '\n'))
		return (ft_strdup(raw));
	while (raw[pos] && raw[pos] != '\n')
		pos++;
	str = ft_substr(raw, j, ++pos);
	str[pos] = '\0';
	*i = pos;
	return (str);
}

char	*ft_memory(char *raw, int *i)
{
	char	*tmp;
	int		j;

	j = *i;
	tmp = ft_substr(raw, j, (ft_strlen(raw) - j));
	free(raw);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*raw;
	char		*str_to_return;
	int			i;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	raw = ft_get_info(fd, raw);
	if (!raw)
		return (NULL);
	i = 0;
	str_to_return = ft_clean(raw, &i);
	raw = ft_memory(raw, &i);
	return (str_to_return);
}
