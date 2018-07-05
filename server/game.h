/*
** bomberman.c for bomberman in /home/coquel-l/C/bomberman
** 
** Made by Coquelet Loïc
** Login   <coquel_l@etna-alternance.net>
** 
** Started on  Mon Jul  2 13:35:02 2018 Coquelet Loïc
** Last update Mon Jul  2 13:36:28 2018 Coquelet Loïc
*/

#ifndef GAME_H
#define GAME_H

#define MAX_PLAYERS 4
#define MAP_COLS 11
#define MAP_ROWS 13
#define MS_PER_UPDATE 30


typedef enum	s_object_type {
	Player,
	Block,
	StaticBlock,
	Empty,
	Bonus
}				t_object_type;

typedef struct	s_object {
	t_object_type	type;
	int				value;
	int				bombRange;
}				t_object;

typedef struct	s_client_request {
	int				player_id;
	int				x_dir;
	int				y_dir;
	int				launchingBomb;
}				t_client_request;

typedef struct	s_player_infos{
	char	connected;
	int		alive;
	int		player_id;
	int		x_pos;
	int		y_pos;
	int		current_dir;
	int		current_speed;
	int		bombs_left;
	int		bombs_capacity;
	int		frags;
}				t_players_infos;

typedef struct	s_map {
	t_object	obj[MAP_COLS][MAP_ROWS];
}				t_map;

typedef struct	s_game {
	t_players_infos		**players;
	t_map				*map;
//	t_other				infos;
}				t_game;


char	*my_strcpy(char *dest, char *src);
int		init_map(t_game *game);
int		init_players(t_game *game);
void	gameloop();

#endif
