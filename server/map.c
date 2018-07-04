/*
** game.c for bomberman in /home/coquel-l/C/bomberman
** 
** Made by Coquelet Loïc
** Login   <coquel_l@etna-alternance.net>
** 
** Started on  Mon Jul  2 14:10:58 2018 Coquelet Loïc
** Last update Mon Jul  2 14:11:04 2018 Coquelet Loïc
*/

#include "game.h"
#include "stdlib.h"
#include "stdio.h"

int	init_map(t_game *game) {

	t_map *game_map;
	int x, y = 0;

	printf("Initializing Map\n");
	if ((game_map = malloc(sizeof(game_map))) == NULL) {
		printf("Error allocating memory for map\n");
		return (0);
	}

	while (x++ < MAP_COLS) {
		while (y++ < MAP_ROWS) {
			if (x % 2 == 1 && y % 2 == 1) {
				game_map->obj[x][y].type = StaticBlock;
			} else {
				int rng = rand() % 100 + 1;
				if (rng > 33) {
					game_map->obj[x][y].type = Block;
				} else {
					game_map->obj[x][y].type = Empty;
				}
			}
		}
	}
	
	game_map->obj[0][0].type = Empty;
	game_map->obj[0][1].type = Empty;
	game_map->obj[1][0].type = Empty;
	game_map->obj[12][0].type = Empty;
	game_map->obj[11][0].type = Empty;
	game_map->obj[12][1].type = Empty;
	game_map->obj[0][10].type = Empty;
	game_map->obj[0][9].type = Empty;
	game_map->obj[1][10].type = Empty;
	game_map->obj[12][10].type = Empty;
	game_map->obj[11][10].type = Empty;
	game_map->obj[12][9].type = Empty;
	game->map = game_map;
	return(1);
}

int	init_players(t_game *game) {
	t_players_infos *players;

	printf("Initializing players\n");
	if ((players = malloc(sizeof(t_players_infos) * 4)) == NULL){
		printf("Memory allocation for players failed\n");
		return (0);
	}
	players[0].player_id = 0;
	players[0].alive = 1;
	players[1].player_id = 1;
	players[1].alive = 1;
	players[2].player_id = 2;
	players[2].alive = 1;
	players[3].player_id = 3;
	players[3].alive = 1;
	game->players = &players;
	return (1);
}
