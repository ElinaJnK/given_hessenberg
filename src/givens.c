#include "../include/givens.h"

/**
 * Make the Given coefficients
 **/
void su_coeff_given(int i, int j, double *c, double *s, double **r)
{
	double norm;
	norm = sqrt((r[j][j] * r[j][j]) + (r[i][j] * r[i][j]));
	if (norm == 0.0)
	{
		*c = 1.0;
		*s = 0.0;
	}
	else
	{
		*c = r[j][j] / norm;
		*s = r[i][j] / norm;
	}
}

/**
 * Make the Given matrice
 **/
void	su_make_given(int m, int i, int j, double **R, double **G)
{
	double c;
	double s;

	c = 1.0;
	s = 0.0;
	su_make_id(m, m, G);
	su_coeff_given(i, j, &c, &s, R);
	G[i][i] = G[j][j] = c;
	G[j][i] = s;
	G[i][j] = -s;
}

/**
 * Implements the transpose of the matrix
 **/
double	**su_transpose(int m, int n, double **mat)
{
	double **t; // peut etre allouer mat_temp a la taille de mat ?
	int 	i, j;

	t = su_init_mat(n, m);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			t[j][i] = mat[i][j];
	return (t);
}

/**
 * Implement the QR decomposition using Given's method
 * The matrix mat must be previously allocated
 **/

void	su_given(double **A, double **Q, double **R, int m, int n)
{
	double	**G;
	double	**Gt;
	double 	**tmp;

	su_make_id(m, m, Q);
	su_copy_matrix(R, A, m, n);

	for (int j = 0; j < n; j++)
	{
		for (int i = j + 1; i < m; i++)
		{
			G = su_init_mat(m, m);
			su_make_given(m, i, j, R, G);
			tmp = su_mul_mat(m, n, G, R);
			su_copy_matrix(R, tmp, m, n);
			su_free_mat(m, tmp);

			Gt = su_transpose(m, m, G);
			tmp = su_mul_mat(m, m, Q, Gt);
			su_copy_matrix(Q, tmp, m, m);

			su_free_mat(m, tmp);
			su_free_mat(m, G);
			su_free_mat(m, Gt);
		}
	}
}

void	su_gen_threshold_mat(double **A, int n, double threshold)
{
	if (su_check_coef(A, n, threshold))
		return ;

	double **Q = su_init_mat(n, n);
	double **R = su_init_mat(n, n);
	su_given(A, Q, R, n, n);

	double	**Qt = su_transpose(n, n, Q);

	double	**Ai = su_mul_mat_3(n, Q, A, Qt);
	su_copy_matrix(A, Ai, n, n);
	su_free_mat(n, Ai);
	su_free_mat(n, R);
	printf("A :\n");
	su_print_matrice(A,n,n);
	su_gen_threshold_mat(A, n, threshold);
}