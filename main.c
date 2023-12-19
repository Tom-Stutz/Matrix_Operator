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
int userMatrix[ROWS][COLUMNS];

//initialize
welcome_screen();
menu_screen();

//wait for user input
userInput = wait_for_user();

//switch case for user inputs
switch(userInput) {
    case 1:
    enter_matrix(&rows, &columns);
    
    break;

    default:
    printf("LOGICAL ERROR.\n");
    return -1;
    break;

}

    return 0;
}



