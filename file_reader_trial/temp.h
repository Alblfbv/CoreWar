#ifndef TEMP_H
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define TEMP_H
#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 2048
#define MAX_PLAYERS 4

typedef struct	s_champ
{
	char		name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
	unsigned char	*instr;
	unsigned int	prog_size;
	int		id; // this should be created in init and copied in r0
	int		prcs_c;
	int		live_c;
}				t_champ;

typedef struct	s_game
{
	t_champ	champs[MAX_PLAYERS + 1]; // the last ptr is NULL //-s option
    int         pv_number;
	int			nbr_champs;
}				t_game;


#endif
