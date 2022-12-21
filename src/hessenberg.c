#include "../include/givens.h"
#include "../include/hessenberg.h"

/**
 * Iterative algorithm that does not work because j does not decrement as seen in the proofs
**/
void	su_upper_hessenberg(double **A, int n)
{
	double	**G;
	double	**Gt;
	double	**GA;
	double	**GAGT;

	for (int j = n - 1; j >= 0; j--)
	{
		for (int i = n - 2; i >= 0; i--)
		{
			printf("i: %d, j: %d\n", i, j);
			G = su_init_mat(n, n);
			su_make_given(n, i, j, A, G);
			printf("G: ");
			su_print_matrice(G, n, n);

			GA = su_mul_mat(n, n, G, A);
			printf("GA: ");
			su_print_matrice(GA, n, n);
			Gt = su_transpose(n, n, G);
			printf("Gt: ");
			su_print_matrice(Gt, n, n);
			GAGT = su_mul_mat(n, n, GA, Gt);
			printf("GAGT: ");
			su_print_matrice(GAGT, n, n);

			su_copy_matrix(A, GAGT, n, n);
			printf("A: ");
			su_print_matrice(A, n, n);
			su_free_mat(n, G);
			su_free_mat(n, Gt);
			su_free_mat(n, GA);
			su_free_mat(n, GAGT);
		}
	}
}

/**
 * Check the threshold
**/
int	su_check_coef(double **A, int n, double threshold)
{
	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (A[i][j] > threshold)
				return (0);
		}
	}
	return (1);
}

/**
 * Multiplication of 3 matrices
**/
double	**su_mul_mat_3(int n, double **mat1, double **mat2, double **mat3)
{
	double	**res1;
	double	**res2;

	res1 = su_mul_mat(n, n, mat1, mat2);
	res2 = su_mul_mat(n, n, res1, mat3);

	su_free_mat(n, res1);
	su_free_mat(n, mat1);
	su_free_mat(n, mat3);
	return (res2);
}

/**
 * Recursive implementation of the algorithm in the report (does not give upper hessenberg) 
**/
double	**su_hessenberg_rec(double **A, int size, int n, double threshold)
{
	if (n <= 0 || su_check_coef(A, n, threshold))
		return A;
	
	double	**G;
	double	**Gt;

	G = su_init_mat(size, size);
	su_make_given(size, n - 1, n, A, G);
	printf("G: ");
	su_print_matrice(G, size, size);

	printf("A: ");
	su_print_matrice(A, size, size);

	Gt = su_transpose(size, size, G);
	printf("Gt: ");
	su_print_matrice(Gt, size, size);

	return su_hessenberg_rec(su_mul_mat_3(size, G, A, Gt), size, n - 1, threshold);
}

/** 
 * Hessenberg elimination
**/
void	su_hessenberg_elimination(double **A, int n)
{
	int m,j,i;
	double y,x;
	for (m = 1; m < n; m++)
	{
		x=0.0;
		i=m;
		// find the pivot (look for the maximal value in the mth column)
		for (j = m; j < n; j++)
		{
			if (fabs(A[j][m-1]) > fabs(x))
			{
				x = A[j][m-1];
				i = j;
			}
		}
		// change rows to columns
		if (i != m)
		{
			for (j = m - 1; j < n; j++) SWAP(A[i][j],A[m][j])
			for (j = 0; j < n; j++) SWAP(A[j][i],A[j][m])
		}
		// carry out the elimination
		if (x) 
		{
			for (i = m+1; i < n; i++)
			{
				if ((y=A[i][m-1]) != 0.0)
				{
					y /= x;
					A[i][m-1] = y;
					for (j = m; j < n; j++)
						A[i][j] -= y*A[m][j];
					for (j = 0; j < n; j++)
						A[j][m] += y*A[j][i];
				}
			}
		}
	}
}

/**
 * Call Hessenberg until a certain threshold is obtained
**/
void	su_hessenberg_rec_threshold(double **A, int n, double threshold)
{
	if (su_check_coef(A, n, threshold))
		return ;
	su_hessenberg_elimination(A, n);
	su_hessenberg_rec_threshold(A, n, threshold);
}
