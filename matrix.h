/*******************************************************************************************
AUTHOR   : Tom Stutz
PROGRAM  : Matrix_Operator
FILE NAME: matrix.h
NOTES    : header file associated with matrix.c (contains function prototypes and definitions related to matrix operations
LAST EDIT: WEDNESDAY MAR 20, 13:26
VERSION: 1.0.0
*******************************************************************************************/

#ifndef __MATRIX_H__
#define __MATRIX_H__
//Libraries
#include <stdio.h>

//definitions
#define MAXCHAR 10
#define ROWS 15  // has a clear effect on segmentation fault
#define COLUMNS 15 // has a clear effect on segmentation fault

//function prototypes
void welcome_screen(void);
void menu_screen(void);
int wait_for_user(void);
void enter_matrix(int*,int*);
void prompt_for_size(int*, int*);
void matrix_populate_mxn(double userMatrix[][COLUMNS], int*, int*);
double determinant_mxm(double userMatrix[][COLUMNS],int*);
void parity(double userMatrix[][COLUMNS],int permutation_set[], int*, int*, double*);
int factorial(int);
void swap(int* , int* );
void permute(double userMatrix[][COLUMNS], double* det, int* term_array, int l, int f);



#endif