#ifndef PLAYER_H_
#define PLAYER_H_

#include "game.h"

typedef size_t PlayerId;

typedef struct {
    PlayerId id;
    char* name;
    Balance bal;
    size_t pos;
} Player;

#endif /* PLAYER_H_ */

