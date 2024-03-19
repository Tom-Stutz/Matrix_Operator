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

    printf("Enter a matrix size in the following format: _x_ (e.g. 2x2 up to 100x100)\n");
    fflush(stdin);
    fscanf(stdin, "%dx%d", rows, columns);
    

}

/************
 * FUNCTION
 * NAME: matrix_populate_3x3
 * INPUTS: 
 * OUTPUTS: 
 * DESCRIPTION: 
*************/
void matrix_populate_3x3(double userMatrix[][COLUMNS]) {
int i = 0;
int j = 0;
int flag = 0;
int det = 0;
//populate matrix
for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
        printf("Enter a value for A%d%d: ", i+1, j+1);
        //error check
        flag = scanf("%lf", &userMatrix[i][j]);
        while(flag == 0) {
            printf("INPUT ERROR. Enter a valid integer number");
            fflush(stdin);
            flag = scanf("%lf", &userMatrix[i][j]);
        }
    }
}
//print full matrix
printf("---------------------\n");
for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
        printf("[%lf]\t", userMatrix[i][j]);
    }
    printf("\n");
}
printf("---------------------\n");

//find determinant
det = ((userMatrix[0][0])*((userMatrix[1][1] * userMatrix[2][2]) - (userMatrix[1][2] * userMatrix[2][1])));
det = det - (userMatrix[0][1])*((userMatrix[1][0] * userMatrix[2][2]) - (userMatrix[1][2] * userMatrix[2][0]));
det = det + (userMatrix[0][2])*((userMatrix[1][0] * userMatrix[2][1]) - (userMatrix[1][1] * userMatrix[2][0]));

printf("Determinant: %d\n", det);


    
}

/************
 * FUNCTION
 * NAME: matrix_populate_2x2
 * INPUTS: 
 * OUTPUTS: 
 * DESCRIPTION: 
*************/
void matrix_populate_2x2(double userMatrix[][COLUMNS]) {

int i = 0;
int j = 0;
int flag = 0;
int det = 0;
//populate matrix
for(i = 0; i < 2; i++) {
    for(j = 0; j < 2; j++) {
        printf("Enter a value for A%d%d: ", i+1, j+1);
        //error check
        flag = scanf("%lf", &userMatrix[i][j]);
        while(flag == 0) {
            printf("INPUT ERROR. Enter a valid integer number");
            fflush(stdin);
            flag = scanf("%lf", &userMatrix[i][j]);
        }
    }
}
//print full matrix
printf("----------\n");
for(i = 0; i < 2; i++) {
    for(j = 0; j < 2; j++) {
        printf("[%lf]\t", userMatrix[i][j]);
    }
    printf("\n");
}
printf("----------\n");

//find determinant
det = userMatrix[0][0] * userMatrix[1][1] - userMatrix[0][1] * userMatrix[1][0];
printf("Determinant: %d\n", det);

}

/************
 * FUNCTION
 * NAME: matrix_populate_mxn
 * INPUTS: 
 * OUTPUTS: 
 * DESCRIPTION: 
*************/
void matrix_populate_mxn(double userMatrix[][COLUMNS],int* m, int* n) {

//Variables
int i = 0;  //loop for rows
int j = 0;  //loop for columns
int flag = 0;

    //Double for loop (populate matrix)
    for(i = 0; i < *m; i++) {

        for(j = 0; j < *n; j++) {
            printf("Enter a value for A%d%d: ", i+1, j+1);
            //error check
            flag = scanf("%lf", &userMatrix[i][j]);
            while(flag == 0) {
                printf("INPUT ERROR. Input a valid entry (all real numbers.)\n");
                fflush(stdin);
                flag = scanf("%lf", &userMatrix[i][j]);
            }
        }
    }

    //print to screen 
    printf("User entered: \n");
    for(i = 0; i < *m; i++) {

        for(j = 0; j < *n; j++) {
            printf("%g\t", userMatrix[i][j]);
        }
        printf("\n");
    }

}

/************
 * FUNCTION
 * NAME: matrix_populate_mxn
 * INPUTS: 
 * OUTPUTS: 
 * DESCRIPTION: 
*************/
double determinant_mxn(double userMatrix[][COLUMNS],int* m,int* n) {
//variables
int i = 0; //i operates as looping through the first value in the permutation
double det = 0; //determinant (will sum together)

//loop through all permutatoins of: a(0)_ _a(1)_ _a(2)...a(m)_ _ finding the sum of products using parity
for(i = 0; i < *m; i++) {

    
}

return det;

}

/************
 * FUNCTION
 * NAME: matrix_populate_mxn
 * INPUTS: 
 * OUTPUTS: 
 * DESCRIPTION: 
*************/
void parity(double userMatrix[][COLUMNS], int* m, int* n, int* parity, double* product) {



}

int factorial(int input) {
int i = 0;
int output = 0;
for(i = input; i > 0; i--) {


    output =  (i * (input - 1));
    input--; //decrease input
    printf("%d\n",output);
    
    
    
}

return output;

}