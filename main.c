/*************************************
 * Header
 * 
*************************************/

#include "matrix.h"

int main(void) {

//Variables
int userInput = 0;
int rows = 0;
int columns = 0;
double userMatrix[ROWS][COLUMNS];

//initialize
welcome_screen();
printf("%d\n",factorial(4));
menu_screen();

//wait for user input
userInput = wait_for_user();

//switch case for user inputs
switch(userInput) {
    case 1:
    
    enter_matrix(&rows, &columns);
    matrix_populate_mxn(userMatrix,&rows,&columns);

    /*
    
    if(rows == 3 && columns == 3) {
        matrix_populate_3x3(userMatrix);
    }
    else if(rows == 2 && columns == 2) {
        matrix_populate_2x2(userMatrix);
    }
    */

    break;

    default:
    printf("LOGICAL ERROR.\n");
    return -1;
    break;

}

    return 0;
}



