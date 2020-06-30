#include <stdio.h>
#include <stdlib.h>

#include <common/constants.h>

int main(int argc, char** argv) {
    if(argc != 2) { /* usage */
        fprintf(stderr, "usage: hub num_players\n");
        return EXIT_FAILURE;
    }

    size_t num_players = atol(argv[1]);

    if(num_players > MAX_NUM_PLAYERS) { /* bounds check */
        fprintf(stderr, "Too many players\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

