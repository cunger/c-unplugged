#include "game-of-life.h"

int count_alive(Cell cells[], int size);

Cell evolve_cell(Cell neighbors[8]) {
    int number_of_alive_neighbors = count_alive(neighbors, 8);
    if (number_of_alive_neighbors < LOWER_POPULATION_BOUND ||
        number_of_alive_neighbors > UPPER_POPULATION_BOUND) {
        return DEAD;
    } else {
        return ALIVE;
    }
}

int count_alive(Cell cells[], int size) {
    int count = 0;

    int i;
    for (i = 0; i < size; i++) {
      if (cells[i]) count++;
    }

    return count;
}
