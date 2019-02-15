#include <stdio.h>
#include <assert.h>
#include "game-of-life.h"

void print_cells(Cell cells[8]);
void test_evolve_cell(void);

int main(void) {
    test_evolve_cell();
}

void test_evolve_cell(void) {
    int n;
    for (n = 0; n <= 8; n++) {
        /* Create an array of eight neighbors,
           where n are alive and the rest is dead. */

        Cell neighbors[8];
        int i;
        for (i = 0; i < 8; i++) {
            neighbors[i] = i < n ? ALIVE : DEAD;
        }

        print_cells(neighbors);

        /* Check whether the cell is now alive or dead. */

        if (n < LOWER_POPULATION_BOUND ||
            n > UPPER_POPULATION_BOUND) {
            printf("%d neighbors are alive, cell should be DEAD\n", n);
            assert(evolve_cell(neighbors) == DEAD);
        } else {
            printf("%d neighbors are alive, cell should be ALIVE\n", n);
            assert(evolve_cell(neighbors) == ALIVE);
        }
    }

}

void print_cells(Cell cells[8]) {
    int i;
    for (i = 0; i < 8; i++) {
        printf("%d ", cells[i]);
    }
    printf("\n");
}
