#include "../include/givens.h"
#include "../include/hessenberg.h"
#include <time.h>

int main(void)
{
	/*
	clock_t temps_initial;
	clock_t temps_final;
	double	temps_cpu1, temps_cpu2;
	FILE *fd = fopen("givens_hessenberg_times.txt", "w");
	double	**A;
	double	**Q;
	double	**R;
	for (int i = 5; i <= 50; i += 5){
		A = su_rand_mat(i, i);
		Q = su_init_mat(i, i);
		R = su_init_mat(i, i);
		// time for Given's algorithm
		temps_initial = clock () ;
		su_given(A, Q, R, i, i);
		temps_final = clock () ;
		temps_cpu1 = ((double)(temps_final - temps_initial)) /CLOCKS_PER_SEC;
		su_free_mat(i, Q);
		su_free_mat(i, R);
		su_free_mat(i, A);

		A = su_rand_mat(i, i);
		// time for Hessenberg's algorithm
		temps_initial = clock () ;
		su_hessenberg_rec_threshold(A, i, 0);
		temps_final = clock () ;
		temps_cpu2 = ((double)(temps_final - temps_initial)) /CLOCKS_PER_SEC;
		su_free_mat(i, A);

		fprintf(fd, "%d %lf %lf\n", i, temps_cpu1, temps_cpu2);
	}
	fclose(fd);
	*/
	// Supplementary tests on smaller matrices

	/* test pour Given's
	double	**A;
	double	**Q;
	double	**R;

	A = su_init_mat(M, N);
	A[0][0] = 3, A[0][1] = -3, A[0][2] = -2;
	A[1][0] = 4, A[1][1] = -4, A[1][2] = 14;
	A[2][0] = 12, A[2][1] = -12, A[2][2] = 24;
	A[3][0] = 0, A[3][1] = 3, A[3][2] = -5;
	
	// A[0][0] = 0, A[0][1] = -1, A[0][2] = 1;
	// A[1][0] = 4, A[1][1] = 2, A[1][2] = 0;
	// A[2][0] = 3, A[2][1] = 4, A[2][2] = 0;

	Q = su_init_mat(M, M);
	R = su_init_mat(M, N);

	su_given(A, Q, R, M, N);
	printf("final Q : \n");
	su_print_matrice(Q, M, M);
	printf("final R : \n");
	su_print_matrice(R, M, N);
	su_free_mat(M, M, Q);
	su_free_mat(M, N, R);
	*/

	/* test pour Hessenberg */
	/*
	double	**A;
	A = su_rand_mat(N, N);
	printf("A init : \n");
	su_print_matrice(A, N, N);
	A[0][0] = 3, A[0][1] = -3, A[0][2] = -2;
	A[1][0] = 4, A[1][1] = -4, A[1][2] = 14;
	A[2][0] = 12, A[2][1] = -12, A[2][2] = 24;
	A[3][0] = 0, A[3][1] = 3, A[3][2] = -5;


	A[0][0] = 0, A[0][1] = -1, A[0][2] = 1;
	A[1][0] = 4, A[1][1] = 2, A[1][2] = 0;
	A[2][0] = 3, A[2][1] = 4, A[2][2] = 0;

	//su_hessenberg_rec(A, N, N - 1, 0);
	su_hessenberg_rec_threshold(A, N, 0);
	printf("A1 : \n");
	su_print_matrice(A, N, N);
	//su_hessenberg_elimination(A, N );
	//printf("A2 : \n");
	//su_print_matrice(A, N, N);
	su_free_mat(N, A);
	*/
	double	**A;
	A = su_init_mat(N, N);
	A[0][0] = 3, A[0][1] = -3, A[0][2] = -2,A[0][3] = -2;
	A[1][0] = 4, A[1][1] = -4, A[1][2] = 14,A[1][3] = -2;
	A[2][0] = 12, A[2][1] = -12, A[2][2] = 24,A[2][3] = -2;
	A[3][0] = 0, A[3][1] = 3, A[3][2] = -5,A[3][3] = -2;
	
	printf("A init : \n");
	su_print_matrice(A, N, N);
	su_gen_threshold_mat(A, N, 0);
	printf("A pas init : \n");
	su_print_matrice(A, N, N);
	return (0);
}