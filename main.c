/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacopo <jacopo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:09:15 by jacopo            #+#    #+#             */
/*   Updated: 2023/02/23 13:09:17 by jacopo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		segno;
	int		i;
	char	*str;

	i = 0;
	segno = open("test.txt", O_RDONLY);
	/*while (i++ < 10)
	{
		str = get_next_line(segno);
		printf("%s", str);
	}*/
	str = get_next_line(segno);
	printf("%s", str);
	return (close(segno));
}
