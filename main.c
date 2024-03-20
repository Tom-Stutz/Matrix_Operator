/*******************************************************************************************
AUTHOR   : Tom Stutz
PROGRAM  : Matrix_Operator
FILE NAME: main.c
NOTES    : terminal script that is developed for operations of mxn matrices (current version supports entry and determinant)
LAST EDIT: WEDNESDAY MAR 20, 13:26
VERSION: 1.0.0
*******************************************************************************************/

#include "matrix.h"

int main(void) {

//Variables
int userInput = 0;
int rows = 0;
int columns = 0;
double userMatrix[ROWS][COLUMNS];

//initialize
welcome_screen();


menu_screen();

//wait for user input
userInput = wait_for_user();

//switch case for user inputs
switch(userInput) {
    case 1:
    
    enter_matrix(&rows, &columns);
    matrix_populate_mxn(userMatrix,&rows,&columns);

    break;

    default:
    printf("Logical ERROR\n");
    return -1;
    break;

}

    return 0;
}



