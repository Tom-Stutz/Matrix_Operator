/*************************************
 * Header
 * 
*************************************/

#ifndef __MATRIX_H__
#define __MATRIX_H__
//Libraries
#include <stdio.h>

//definitions
#define MAXCHAR 10
#define ROWS 8
#define COLUMNS 8

//function prototypes
void welcome_screen(void);
void menu_screen(void);
int wait_for_user(void);
void enter_matrix(int*,int*);
void prompt_for_size(int*, int*);
void matrix_populate_3x3(double userMatrix[][COLUMNS]);
void matrix_populate_2x2(double userMatrix[][COLUMNS]);
void matrix_populate_mxn(double userMatrix[][COLUMNS], int*, int*);
double determinant_mxm(double userMatrix[][COLUMNS],int*);
void parity(double userMatrix[][COLUMNS],int permutation_set[], int*, int*, int*, double*);
int factorial(int);
void swap(int* , int* );
void permute(int* perm_index, int permutation_array[][COLUMNS], int* term_array, int l, int f);



#endif