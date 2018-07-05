/*
** bomberman.c for bomberman in /home/coquel-l/C/bomberman
** 
** Made by Coquelet Loïc
** Login   <coquel_l@etna-alternance.net>
** 
** Started on  Mon Jul  2 13:35:02 2018 Coquelet Loïc
** Last update Mon Jul  2 13:36:28 2018 Coquelet Loïc
*/

#include "game.h"
#include "sys/timeb.h"
#include "stdio.h"
#include "stdlib.h"

void	move	(t_client_request req, t_map **gamemap, t_players_infos **player){
	int x, y, old_x, old_y;
	
	old_x = (*player)->x_pos;
	old_y = (*player)->y_pos;
	x = old_x + req.x_dir;
	y = old_y + req.y_dir;
	t_object nextPos = (*gamemap)->obj[x][y];
	if (x >= 0 && x <= MAP_COLS && y >= 0 && y <= MAP_ROWS) {
		if (nextPos.type == Empty && nextPos.bombRange == 0) {
			(*gamemap)->obj[x][y].type = Player;
			(*gamemap)->obj[old_x][old_y].type = Empty;
			printf("Moved player to new position\n");
		}
		printf("New position is occupied\n");
	}
	printf("New position is out map borders\n");
}

void	spawn_bomb(t_client_request req, t_players_infos **player, t_map **gamemap) {
	if (req.launchingBomb == 1 && (*player)->bombs_left > 0) {
		(*gamemap)->obj[(*player)->x_pos][(*player)->y_pos].bombRange = 2;
		printf("Player %d dropped a bomb\n", (*player)->player_id);
	}
}

void	handle_client_request (t_client_request req, t_players_infos **player,
		t_map **gamemap) {
	move(req, gamemap, player);
	spawn_bomb(req, player, gamemap);
}

int		victoryCheck(t_players_infos *players) {
	int deadPlayers = 0;
	int endOfGame = 1;
	int i = 0;

	printf("checking victory\n");
	while (i++ < 4) {
		if (players[i].alive == 0) {
			printf("Player %d is dead\n", players[i].player_id);
			deadPlayers++;
		}
	}
	if (deadPlayers == 3)
		endOfGame = 0;
	return (endOfGame);
}

void	kill_a_player_TEST(t_players_infos **players) {
	int i = 0;

	while (i < 4) {
		if (players[i]->player_id == 1) {
			players[i]->player_id = 0;
			i = 4;
		}
	}
}

void gameloop() {

	struct timeb tmb;
	t_game *game;

	if ((game = malloc(sizeof(t_game))) == NULL) {
		printf("Problem initializing game\n");
		return;
	}

	ftime(&tmb);
	unsigned short previous = tmb.millitm;
	unsigned short lag = 0.0;
	int playing = 1;

	if (init_map(game) == 0) {
		printf("Map Initialization failed\n");
		return;
	}
	if (init_players(game) == 0) {
		printf("Player Initialization failed\n");
		return;
	}
	printf("test : player id %d", game->players[0]->player_id);
	while (playing == 1) {
		ftime(&tmb);
		unsigned short current = tmb.millitm;
		unsigned short elapsed = current - previous;
		previous = current;
		lag += elapsed;
	//	receive input
//		printf("receiving input\n");
		while (lag >= MS_PER_UPDATE) {
			//handle game state
			kill_a_player_TEST(game->players);
			lag -= MS_PER_UPDATE;
//			printf("handling game state\n");
		}
//		playing = victoryCheck(players);
//		printf("sending info\n");
		//	send info
	}
}
