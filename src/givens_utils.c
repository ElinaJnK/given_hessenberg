#include "../include/givens.h"

/**
 * Print the matrice
 **/
void su_print_matrice(double **mat, int m, int n)
{
	printf("{");
	for (int i = 0; i < m; i++)
	{
		printf("{");
		for (int j = 0; j < n; j++)
		{
			if (j == n - 1)
				printf("%lf", mat[i][j]);
			else
				printf("%lf,\t", mat[i][j]);
		}
		printf("}\n");
	}
	printf("}\n");
}

/**
 * Make the identity matrice
 **/
void	su_make_id(int m, int n, double **mat)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	}
}

void	su_free_mat(int m, double **mat)
{
	for(int i = 0; i < m; i++)
    	free(mat[i]);
	free(mat);
}

/**
 * Initialize a double matrice
 **/
double **su_init_mat(int m, int n)
{
	double	**r;

	r = malloc(sizeof(double *) * m);
	if (!r)
		return (NULL);
	for (int i = 0; i < m; i++)
	{
		r[i] = malloc(sizeof(double) * n);
		if (!r[i])
			return (NULL);
	}
	return (r);
}

void	su_copy_matrix(double **dst, double **src, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dst[i][j] = src[i][j];
		}
	}
}

/**
 * Multiply 2 matrices
 **/
double	**su_mul_mat(int m, int n, double **mat1, double **mat2)
{
	double	**res;
	res = su_init_mat(m, n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < m; k++)
				res[i][j] += mat1[i][k] * mat2[k][j];
			
		}
	}
	return (res);
}

/**
 * Make a random matrice
 **/
double **su_rand_mat(int m, int n)
{
	double **r;

	r = su_init_mat(n, m);
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			r[i][j] = (double)rand() / RAND_MAX * 50.0 - 1.0;
		}
	}
	return (r);
}