/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacopo <jacopo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:30:53 by jacopo            #+#    #+#             */
/*   Updated: 2023/02/23 21:35:46 by jacopo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

const char	*ft_get_info(int fd, const char *raw)
{
	int		byte;
	char	*buf;

	byte = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!(ft_strchr(buf, '\n') && byte > 0))
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[byte] = '\0';
		raw = ft_strjoin(raw, buf);
	}
	free(buf);
	return (raw);
}

char	*ft_clean(const char *raw)
{
	size_t	i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!raw_string[i])
		return (NULL);
	if (!ft_strchr(raw_string, '\n'))
		return (ft_strdup(raw_string));
	while (raw[i] && raw[i] != '\n')
		i++;
	i = i + 2;
	str = ft_substr(raw, j, i);
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	const char	*raw;
	char		*str_to_return;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	raw = ft_get_info(fd, raw);
	if (!raw)
		return (NULL);
	str_to_return = ft_clean(raw);
	return (str_to_return);

}
