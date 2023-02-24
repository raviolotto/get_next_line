/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacopo <jacopo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:09:15 by jacopo            #+#    #+#             */
/*   Updated: 2023/02/24 17:50:37 by jacopo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		segno;
	int		i = 0;
	char	*str;

	segno = open("test.txt", O_APPEND);
	while (i++ < 10)
	{
		str = get_next_line(segno);
		printf("%s", str);
	}
	return (close(segno));
}
