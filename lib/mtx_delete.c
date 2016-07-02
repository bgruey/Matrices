/*
		Matrix Library! 

// Delete all the data of a matrix
// Does not delete the pointer though, m still exists
void mtx_delete(struct matrix* m); 

	Started as a C library to solve a generalized eigenvalue problem,
	numerical approximations to quantum systems:

		[H] * [C] = E * [S] * [C]

	where brackets indicate matrices:
		H is the Mamiltonian
		C is the basis function coefficient matrix
		S is the generalized "______" matrix for non-orthogonal basis functions
			it would be the identity matrix if they were orthogonal
			this matrix should be symmetric

	The work started with the infinite square well approximation defined
	on page 29 of Jos Thijssen's second edition of Computational Physics


*/


#include "matrix.h"


// Delete all the data of a matrix
// Does not delete the pointer though,
// that's your job.
void 
mtx_delete(struct matrix* m) 
{
	int i = 0;
	for ( i = 0; i < m->rows; i++) 
		free(m->data[i]); // arrays of column entries

	free(m->data); // array of rows
	free(m); // rows, cols and data
}
