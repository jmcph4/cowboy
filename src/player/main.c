#include <stdio.h>
#include <stdlib.h>

#include <common/constants.h>
#include <common/game.h>
#include <common/player.h>

int main(int argc, char** argv) {
    if(argc != 5) { /* usage */
        fprintf(stderr, "usage: player id name balance position\n");
        return EXIT_FAILURE;
    }

    /* player info */
    PlayerId id = atol(argv[1]);
    char* name = argv[2];
    Balance balance = atol(argv[3]);
    size_t position = atol(argv[4]);

    /* bounds check */
    if(id == DEALER_ID) {
        fprintf(stderr, "Players cannot deal.\n");
        return EXIT_FAILURE;
    }

    /* bounds check */
    if(position == DEALER_POSITION || position > MAX_NUM_PLAYERS) {
        fprintf(stderr, "Invalid position.\n");
        return EXIT_FAILURE;
    }

    /* populate player state struct */
    Player me;
    me.id = id;
    me.name = name;
    me.bal = balance;
    me.pos = position;

    printf("Player #%zu (%s) online!\n", me.id, me.name);

    return EXIT_SUCCESS;
}

