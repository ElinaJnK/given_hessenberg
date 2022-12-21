#ifndef GIVENS_H
# define GIVENS_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hessenberg.h"
#define N 4
#define M 4

/* Given */
void	su_given(double **A, double **Q, double **R, int m, int n);
double	**su_transpose(int m, int n, double **mat);
void	su_make_given(int m, int i, int j, double **R, double **G);
void 	su_coeff_given(int i, int j, double *c, double *s, double **r);
double	**su_transpose(int m, int n, double **mat);
/* QAQ algorithm */
void	su_gen_threshold_mat(double **A, int n, double threshold);
/* Given's utils */
void 	su_print_matrice(double **mat, int m, int n);
void	su_free_mat(int m, double **mat);
double 	**su_init_mat(int m, int n);
void	su_make_id(int m, int n, double **mat);
void	su_copy_matrix(double **dst, double **src, int m, int n);
double	**su_mul_mat(int m, int n, double **mat1, double **mat2);
double	**su_rand_mat(int m, int n);
#endif