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


int parity_val = 0;
int m = 3;
int n = 3;
int temp_set[3] = {0,1,2};
double temp_matrix[ROWS][COLUMNS] = {{1,2,3},{1,2,3},{1,2,3}};
double temp_product = 1;
parity(temp_matrix,temp_set, &m,&n,&parity_val, &temp_product);
printf("parity is: %d\n\n", parity_val);
printf("Product was %g\n", temp_product);




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
    printf("Logical ERROR\n");
    return -1;
    break;

}

    return 0;
}



