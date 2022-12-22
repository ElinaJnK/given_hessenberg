# README - Given's and Hessenberg's algorithm #
## _Supervised by Mr. Vincent Neiger and Mr. Jeremy Berthomieu_

This project was carried out by El Bouhali Mouataz, Jankovskaja Elina and Sadykova Karima in the context of the EU MODEL: Numerical and Symbolic Algorithms Modeling. It was supervised by Mr. Jeremy Berthomieu in lectures and Vincent Neiger in tutorials.

## Global variables you can change at compilation

- M : the number of rows
- N : the number of colums

To change these variables change in either givens.h as such

```c
# define N <the number of columns of your matrice>
# define M <the number of rows of your matrice>
```

or directly in the makefile change the line

```sh
CFLAGS		= -Wall -Wextra -Werror -lm
```
to

```sh
CFLAGS		= -Wall -Wextra -Werror -lm -D N=<the number of columns of your matrice> M=<the number of rows of your matrice> 
```

## Files and implemented functions

- givens.c : implements a QR decomposition using Given's method
- givens_utils.c : useful functions used in givens.c
- hessenberg.c : implements upper Hessenberg
- main.c : tester, to test with known matrices uncomment the two versions of matrice A and change the macros M and N accordingly
- *.h : header files

## Run the program

Run:

```sh
make && gcc givens.a -lm && ./a.out 
```

after making the correct changes in the main according to what you want to test.

You can also run:

```sh
make re # delete and make the project again
make clean # delete all the compiled files
make fclean # delete everything
```

## TO DO
OHH a toi qui souhaite reprendre le projet, voila ce qu'il faut faire: 
- multiplication de matrice pour pouvoir faire R = Gi,jR et Q = QGi,jT
- transposition de matrice
