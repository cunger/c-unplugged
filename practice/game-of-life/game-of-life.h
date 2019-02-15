/* Cells and their states */

typedef int Cell;

#define ALIVE 1
#define DEAD  0

Cell evolve_cell(Cell neighbors[8]);

/* Grid */

#define GRID_WIDTH  40
#define GRID_HEIGHT 40

typedef int Grid[GRID_HEIGHT][GRID_WIDTH];

typedef Cell (*evolve) (Cell neighbors[8]);

Grid *init_generation(void);
Grid *next_generation(Grid grid, evolve e);

void display(Grid grid);

/* Game parameters */

#define NUMBER_OF_GENERATIONS 10

#define LOWER_POPULATION_BOUND 2
#define UPPER_POPULATION_BOUND 4
