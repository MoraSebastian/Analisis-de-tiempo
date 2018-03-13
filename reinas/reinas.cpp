#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static int nQueens = 0;		// Number of queens
static int *positions = 0;	// Positions in the chess (starting at 0)

/*
 * Solve problem for "nQueens" queens and store on "positions"
 *
 * iQueen: Number of the first queen to place (deep of the graph)
 *
 * Returns 1 if a valid combination from "index" to the end has been found,
 * else returns 0.
 */
int solve(int iQueen);

/*
 * Check if the queen in the "bound" position is well placed respect the
 * prevoius queens.
 *
 * bound: Index of the queen we are placing (deep of the graph).
 *
 * Returns 1 if the queen in the "bound" position is well-placed, 
 * else returns 0.
 */
int check(int bound);

/*******************************************************************************
 * Main function
 ******************************************************************************/

int main(int argc, char **argv) {
	int result = 1, i;
	clock_t t0, t1;

	// If we haven't a valid calling argument, we ask for it from stdin.

	if (argc >= 2)
		nQueens = atoi(argv[1]);

	while (nQueens <= 0 || result == 0) {
		printf("Indique dimension del problema: ");
		result = scanf("%d", &nQueens);
		fflush(stdin);
	}

	// Reserve memory and solve problem

	positions = (int*)malloc(sizeof(int) * nQueens);
	t0 = clock();
	result = solve(0);
	t1 = clock();

	// If a valid combination has been found (result=1), we show it.

	if (result) {
		printf("Se resolvio el problema en %lf segundos.\n",
			    (double)(t1 - t0) / CLOCKS_PER_SEC);

		for (i = 0; i < nQueens; i++)
			printf("Reina %d: %d\n", i + 1, positions[i] + 1);
	} else
		printf("No se pudo resolver el problema.\n");

	free(positions);
	return EXIT_SUCCESS;
}

/*******************************************************************************
 * Solve problem
 ******************************************************************************/

int solve(int iQueen) {
	int k;

	for (k = 0; k < nQueens; k++) {
	
		/* 
		 * Place the queen in a position.
		 * If it's OK, go down through the graph (index+1),
		 * until reach the bottom, else try another position or return 0.
		 */
		 
		positions[iQueen] = k;

		if (check(iQueen)) {
			if (iQueen == nQueens - 1)
				return 1;
			else if (solve(iQueen + 1))
				return 1;
		}
	}

	return 0;
}

/*******************************************************************************
 * Check partial solution
 ******************************************************************************/

int check(int bound) {
	int i;

	for (i = 0; i < bound; i++)

		// If exists a queen in the same column or diagonal, return 0.
		
		if (positions[i] == positions[bound])
			return 0;
		else if (abs(positions[bound] - positions[i]) == bound - i)
			return 0;

	return 1;
}
