/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacopo <jacopo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:44:13 by jacopo            #+#    #+#             */
/*   Updated: 2023/02/24 17:09:28 by jacopo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	int		i;
	size_t	j;
	char	*str;

	size = (ft_strlen(s1)) + (ft_strlen(s2)) + 1;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[j++] = s1[i];
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	return (str);
}

/*char	*ft_strjoin(char *raw_string, char *second)
{
	char		*str;
	long long	i;
	long long	j;

	if (!raw_string)
	{
		raw_string = (char *)malloc(1);
		raw_string[0] = 0;
	}
	if (!raw_string || !second)
		return (NULL);
	i = -1;
	j = 0;
	str = malloc((ft_strlen(raw_string)+ft_strlen(second)+1) * sizeof(char));
	if (!str)
		return (NULL);
	while (raw_string[++i])
		str[i] = raw_string[i];
	while (second[j])
		str[i++] = second[j++];
	str[i] = '\0';
	free(raw_string);
	return (str);
}*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*subs;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len == ft_strlen(s))
		subs = malloc(sizeof(*s) * (len - start + 1));
	else
		subs = malloc(sizeof(*s) * len + 1);
	if (!subs)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (i < len && s[i])
		{
			subs[i] = s[start + i];
			i++;
		}
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	i;

	i = 0;
	new_s = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_s)
		return (NULL);
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
