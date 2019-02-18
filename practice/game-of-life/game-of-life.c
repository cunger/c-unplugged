#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "game-of-life.h"

int count_alive(Cell cells[], int size);

Cell evolve_cell(Cell neighbors[NUMBER_OF_NEIGHBORS]) {
    int number_of_alive_neighbors = count_alive(neighbors, NUMBER_OF_NEIGHBORS);
    if (number_of_alive_neighbors < LOWER_POPULATION_BOUND ||
        number_of_alive_neighbors > UPPER_POPULATION_BOUND) {
        return DEAD;
    } else {
        return ALIVE;
    }
}

Grid* init_generation(void) {
    srand(time(NULL));

    Grid* grid = malloc(sizeof(Grid));
    assert(grid);

    int i;
    int j;
    for (i = 0; i < GRID_HEIGHT; i++) {
        for (j = 0; j < GRID_WIDTH; j++) {
            *grid[i][j] = random_cell(PRIOR_PROBABILITY_TO_BE_ALIVE);
        }
    }

    return grid;
}

Cell random_cell(double prior_probability_to_be_alive) {
    if (prior_probability_to_be_alive == 0) return DEAD;
    if (prior_probability_to_be_alive == 1) return ALIVE;

    double random = (double) rand() / (double) ((unsigned) RAND_MAX + 1);
    return (random < prior_probability_to_be_alive ? ALIVE : DEAD);
}

int count_alive(Cell cells[], int size) {
    int count = 0;

    int i;
    for (i = 0; i < size; i++) {
        if (cells[i]) count++;
    }

    return count;
}
