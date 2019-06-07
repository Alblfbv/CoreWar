/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_utils_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:26:30 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/07 02:25:01 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int						main(int ac, char **av)
{
	int					fd;
	unsigned int		magic;
	unsigned char		name[128];
	unsigned int		prog_size;
	unsigned char		comment[2048];
	//unsigned int		instr;
	unsigned int		magicNum;

	fd = open(av[1], O_RDONLY);
	if ((read(fd, &magic, sizeof(unsigned int)) < 0))
		return (1);
	magic = vm_endian_conversion(magic);
	if ((read(fd, name, sizeof(unsigned char) * 128)) < 0)
		return (1);
	if ((lseek(fd, 136, SEEK_SET)) < 0)
		return (1);
	if ((read(fd, &prog_size, sizeof(unsigned int))) < 0)
		return (1);
	prog_size = vm_endian_conversion(prog_size);
	unsigned char	inst[prog_size];
	if ((read(fd, comment, sizeof(unsigned char) * 2048)) < 0)
		return (1);
	//printf("%s\n", comment);
	if ((lseek(fd, 2192, SEEK_SET) < 0))
		return (1);
	if ((read(fd, inst, sizeof(unsigned char) * prog_size)) < 0)
		return (1);
	printf("Magic number %#0x\nProgram Name: %s\nProgram Size: %x\n", magic, name, prog_size);
	printf("Comment: %s\nInstruction\n", comment);
	int		i;
	i = -1;
	while (++i < prog_size)
		printf("%02x ",inst[i]);
	//magicNum = 0xea83f3;
	//printf("%d\n", vm_is_little_endian(magic));
	return (0);


