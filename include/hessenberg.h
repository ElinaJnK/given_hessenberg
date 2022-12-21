#ifndef HESSENBERG_H
# define HESSENBERG_H
#include "givens.h"
#define SWAP(g,h) {y=(g);(g)=(h);(h)=y;}

void	su_hessenberg_elimination(double **A, int n);
void	su_upper_hessenberg(double **A, int n);
double	**su_hessenberg_rec(double **A, int size, int n, double threshold);
double	**su_mul_mat_3(int n, double **mat1, double **mat2, double **mat3);
void	su_hessenberg_rec_threshold(double **A, int n, double threshold);
int	su_check_coef(double **A, int n, double threshold);
#endif