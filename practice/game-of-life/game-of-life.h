#include "config.h"

typedef int Cell;
typedef int Grid[GRID_HEIGHT][GRID_WIDTH];

#define ALIVE 1
#define DEAD  0

#define NUMBER_OF_NEIGHBORS 8

Cell random_cell(double prior_probability_to_be_alive);

Cell get_cell(Grid* grid, int i, int j);

Cell evolve_cell(Cell neighbors[NUMBER_OF_NEIGHBORS]);
typedef Cell (*evolve) (Cell neighbors[NUMBER_OF_NEIGHBORS]);

Grid* init_generation(void);
Grid* next_generation(Grid* grid, evolve e);

void display(Grid* grid);
