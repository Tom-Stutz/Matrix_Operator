/*************************************
 * Header
 * 
*************************************/

#include  "matrix.h"

/************
 * FUNCTION
 * NAME: welcome_screen
 * INPUTS:
 * OUTPUTS:
 * DESCRIPTION:
*************/
void welcome_screen(void) {
printf("\nMATRIX CALCULATOR\n");
printf("--------------------\n");
}

/************
 * FUNCTION
 * NAME: menu_screen
 * INPUTS:
 * OUTPUTS:
 * DESCRIPTION:
*************/
void menu_screen(void) {
//Menu
printf("Select an option:\n");
printf("1: Enter a matrix\n");

}

/************
 * FUNCTION
 * NAME: wait_for_user
 * INPUTS: void
 * OUTPUTS: userInput
 * DESCRIPTION: returns the user input from the terminal (integer input corresponding to option)
*************/
int wait_for_user(void) {
//variables
int userInput = 0;
int flag = 0;

//take input
flag = scanf("%d", &userInput);
//error check
while(flag == 0 || userInput != 1) {
printf("INPUT ERROR, please select a valid option.\n");
fflush(stdin);
flag = scanf("%d", &userInput);
}

return userInput;
}

/************
 * FUNCTION
 * NAME: enter_matrix
 * INPUTS: void
 * OUTPUTS: 
 * DESCRIPTION: 
*************/
void enter_matrix(int* rows, int* columns) {
    //variables
    int error = 0;


    prompt_for_size(rows, columns);
    printf("User entered: %dx%d\n", *rows, *columns);


}

/************
 * FUNCTION
 * NAME: prompt_for_size
 * INPUTS: int* rows, int* columns
 * OUTPUTS: 
 * DESCRIPTION: 
*************/
void prompt_for_size(int* rows, int* columns) {

    printf("Enter a matrix size in the following format: _x_ (e.g. 2x2)\n");
    fflush(stdin);
    fscanf(stdin, "%dx%d", rows, columns);
    

}

/************
 * FUNCTION
 * NAME: 3x3 matrix entrance
 * INPUTS: 
 * OUTPUTS: 
 * DESCRIPTION: 
*************/
void matrix_populate_3x3(int userMatrix[][COLUMNS]) {
int i = 0;
int j = 0;
int flag = 0;
int det = 0;
//populate matrix
for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
        printf("Enter a value for A%d%d: ", i+1, j+1);
        //error check
        flag = scanf("%d", &userMatrix[i][j]);
        while(flag == 0) {
            printf("INPUT ERROR. Enter a valid integer number");
            fflush(stdin);
            flag = scanf("%d", &userMatrix[i][j]);
        }
    }
}
//print full matrix
for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
        printf("%d\t", userMatrix[i][j]);
    }
    printf("\n");
}
//find determinant
det = ((userMatrix[0][0])*((userMatrix[1][1] * userMatrix[2][2]) - (userMatrix[1][2] * userMatrix[2][1]))) - (userMatrix[0][1])*((userMatrix[1][0] * userMatrix[2][2]) - (userMatrix[1][2] * userMatrix[2][0])) + (userMatrix[0][2])*((userMatrix[1][0] * userMatrix[2][1]) - (userMatrix[1][1] * userMatrix[2][0]));
printf("Determinant: %d\n", det);


    
}