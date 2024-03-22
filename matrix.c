/*******************************************************************************************
AUTHOR   : Tom Stutz
PROGRAM  : Matrix_Operator
FILE NAME: matrix.c
NOTES    : function file associated with matrix.h (contains functions related to matrix operations)
LAST EDIT: WEDNESDAY MAR 20, 13:26
VERSION: 1.0.0
*******************************************************************************************/

#include  "matrix.h"

/************
 * FUNCTION
 * NAME: welcome_screen
 * INPUTS: n/a
 * OUTPUTS: n/a
 * DESCRIPTION: Print title
*************/
void welcome_screen(void) {
printf("\nMATRIX CALCULATOR\n");
printf("--------------------\n");
}

/************
 * FUNCTION
 * NAME: menu_screen
 * INPUTS: n/a
 * OUTPUTS: n/a
 * DESCRIPTION: print menu options
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
 * INPUTS: rows(ptr), columns (ptr)
 * OUTPUTS: rows (ptr), columns (ptr)
 * DESCRIPTION: calls the promt_for_size function, has user enter a matrix
*************/
void enter_matrix(int* rows, int* columns) {
    //variables

    prompt_for_size(rows, columns);
    printf("User entered: %dx%d\n", *rows, *columns);


}

/************
 * FUNCTION
 * NAME: prompt_for_size
 * INPUTS: int* rows, int* columns
 * OUTPUTS: int* rows, int* columns
 * DESCRIPTION: asks the user for matrix size, checks for valid entry
*************/
void prompt_for_size(int* rows, int* columns) {

    //variables
    int flag = 0;

    //error check
    printf("Enter a matrix size in the following format: _x_ (e.g. 2x2 up to %dx%d)\n",ROWS,COLUMNS);
    fflush(stdin);
    flag = fscanf(stdin, "%dx%d", rows, columns);
    while(flag == 0 || (*rows > ROWS) || (*columns > COLUMNS)) {
        printf("ERROR. Input a valid dimension");
        fflush(stdin);
        flag = 0;
        flag = fscanf(stdin, "%dx%d", rows, columns);
    }
    

}

/************
 * FUNCTION
 * NAME: matrix_populate_mxn
 * INPUTS: userMatrix[][], int* m, int* n
 * OUTPUTS: int* m, int* n
 * DESCRIPTION: populate the user matrix elemnet at a time, if determinant is possible call the determinant function
*************/
void matrix_populate_mxn(double userMatrix[][COLUMNS],int* m, int* n) {

//Variables
int i = 0;  //loop for rows
int j = 0;  //loop for columns
int flag = 0;
double det = 0;

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
    if(*m == *n) {
       det = determinant_mxm(userMatrix,m);
        printf("The determinant of the %dx%d matrix is %g\n", *m,*n,det);
    }

}

/************
 * FUNCTION
 * NAME: matrix_populate_mxn
 * INPUTS: userMatrix, int* m
 * OUTPUTS: double det (determinant)
 * DESCRIPTION: finds the determinant of the nxn matrix
*************/
double determinant_mxm(double userMatrix[][COLUMNS],int* m) {
//variables
int i = 0; //i operates as looping through the first value in the permutation
int j = 0; //j operates as looping through all permutations of the set {1,2,3...m}
double det = 0; //determinant (will sum together)
int ordered_set[*m];
int value = 0;
//create a set that is {1,2,3,...m}
for(i = 0; i < *m; i++) {
    ordered_set[i] = value;
    //printf("%d\n", ordered_set[i]);
    value++;
}
//create an array that is all permutations of the ordered_set (call permute function)
permute(userMatrix,&det,ordered_set,0,*m-1);


//supply the permuted sets to the parity function one at a time
return det;

}

/************
 * FUNCTION
 * NAME: parity
 * INPUTS: userMatrix, permutation_set[], int* m, int* n, int* parity_value, double* product
 * OUTPUTS: int* m, int* n, int* parity_value (unused in its current form outside of this function), double* product
 * DESCRIPTION: finds parity of each permutated set 1 by 1 and finds the product of given matrix combination. returns determinant to determinant function
*************/
void parity(double userMatrix[][COLUMNS],int permutation_set[], int* m, int* n, double* product) {
int i = 0; 
int j = 0; 
int parity_value = 0;
/*loop structure
check if j < i, if so parity + 1
{i,j,3,4,...m}
{i,2,j,4,...m}
{i,2,3,j....m}
...
{1,i,j,4...m}
*/
//Find parity of permutation set
for(i = 0; i < *m - 1; i++) {

    for(j = i + 1; j < *m; j++) {
        if((permutation_set[j] < permutation_set[i])) {
            
            parity_value = parity_value + 1;
        }
    }

}



if(parity_value == 0) {
    parity_value = 1;
}
else if((parity_value % 2) == 0) {
   
    parity_value = 1;
}
else {
    parity_value = -1;
}


/*loop structure
a1_a2_a3_...am_
ai(permutation_set[i])*a(i+1)(permutation_set[i+1])
*/
double parity_product = 1;
for(i = 0; i < *m; i++) {
    parity_product = (parity_product)*userMatrix[i][permutation_set[i]];
    
}
parity_product = parity_product*(parity_value);
*product = *product + parity_product;

}

/************
 * FUNCTION
 * NAME: factorial
 * INPUTS: int input
 * OUTPUTS: int output
 * DESCRIPTION: finds factorial of input value
*************/
int factorial(int input) {
int i = 0;
int output = input;
if(input < 0) {
    printf("ERROR, factorial input must be >= 0, otherwise the answer is undefined\n");
    return -1;
}
else if(input == 0) {
    return 1;
}
else {
    for(i = 1; input - i > 0; i++) {

            output =  output*(input-i);
        
    }
}

return output;

}

/************
 * FUNCTION
 * NAME: swap
 * INPUTS: int* input1, int* input2
 * OUTPUTS: int* input1, int* input2
 * DESCRIPTION: swaps input1 with input2
*************/
void swap(int* input1, int* input2) { 
    int temp; 
    temp = *input1; 
    *input1 = *input2; 
    *input2 = temp; 
} 

/************
 * FUNCTION
 * NAME: permute
 * INPUTS: int* perm_index, int permutation_array[][COLUMNS], int* term_array, int l, int f
 * OUTPUTS: int* m, int* n, int* parity_value (unused in its current form outside of this function), double* product
 * DESCRIPTION: finds all possible permutation of the given "term_array" and returns the permutatoin through the array "permutation_array"
 * CITATIONS: function is built off of the following article https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*************/
void permute(double userMatrix[][COLUMNS], double* det, int* term_array, int l, int f) {
    int i = 0;
    int j = 0;
    int m = f + 1;

    if(l == f) {
        parity(userMatrix,term_array,&m,&m,det);
    }
    else {
        for(i = l;i <= f; i++) {
            swap(&term_array[l],&term_array[i]);
            permute(userMatrix,det,term_array,l+1,f);
            swap(&term_array[l],&term_array[i]);
        }


    }
}
