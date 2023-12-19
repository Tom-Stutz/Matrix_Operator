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
#define ROWS 100
#define COLUMNS 100

//function prototypes
void welcome_screen(void);
void menu_screen(void);
int wait_for_user(void);
void enter_matrix(int*,int*);
void prompt_for_size(int*, int*);
void matrix_populate_3x3(int userMatrix[][COLUMNS]);
void matrix_populate_2x2(int userMatrix[][COLUMNS]);

#endif