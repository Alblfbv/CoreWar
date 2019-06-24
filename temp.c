/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 06:36:16 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 06:51:08 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int				main(int ac, char **av)
{
	int 		fd;
	char		*str;

	str = strcat(av[1], ".s");
	if ((fd = open(str, O_CREAT | O_RDWR)) < 0)
		return (0);
	write(fd, av[1], strlen(av[1]));
	if ((fchmod(fd, S_IRWXU)) < 0)
		return (0);
	close(fd);
	return (0);
}
