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
 * INPUTS: 
 * OUTPUTS: 
 * DESCRIPTION: 
*************/
double determinant_mxm(double userMatrix[][COLUMNS],int* m) {
//variables
int i = 0; //i operates as looping through the first value in the permutation
int j = 0; //j operates as looping through all permutations of the set {1,2,3...m}
double det = 0; //determinant (will sum together)
int ordered_set[*m];
int permutation_set[*m];
int value = 0;
int parity_sign = 0;
double product = 0;    
int perm_index = 0;
int permutated_array[factorial(*m)][COLUMNS];
//create a set that is {1,2,3,...m}
for(i = 0; i < *m; i++) {
    ordered_set[i] = value;
    //printf("%d\n", ordered_set[i]);
    value++;
}
//create an array that is all permutations of the ordered_set

permute(&perm_index,permutated_array,ordered_set,perm_index,*m - 1);
/*
for(i = 0; i < factorial(*m);i++) {
    for(j = 0; j < *m; j++) {
        printf("%d", permutated_array[i][j]);
    }
    printf("\n");
}
*/

//supply the permuted sets to the parity function one at a time
for(i = 0; i < factorial(*m);i++) {
    parity(userMatrix,permutated_array[i],m,m,&parity_sign,&product);
    parity_sign = 0;
}
det = product;
return det;

}

/************
 * FUNCTION
 * NAME: matrix_populate_mxn
 * INPUTS: 
 * OUTPUTS: 
 * DESCRIPTION: 
*************/
void parity(double userMatrix[][COLUMNS],int permutation_set[], int* m, int* n, int* parity_value, double* product) {
int i = 0; 
int j = 0; 
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
            printf("%d is < %d\n", permutation_set[j],permutation_set[i]);
            *parity_value = *parity_value + 1;
        }
    }

}



if(*parity_value == 0) {
    *parity_value = 1;
}
else if((*parity_value % 2) == 0) {
    printf("%d mod 2 == 0\n", *parity_value);
    *parity_value = 1;
}
else {
    *parity_value = -1;
}
printf("set: %d%d%d\n", permutation_set[0],permutation_set[1],permutation_set[2]);
printf("parity: %d\n", *parity_value);

/*loop structure
a1_a2_a3_...am_
ai(permutation_set[i])*a(i+1)(permutation_set[i+1])
*/
double parity_product = 1;
for(i = 0; i < *m; i++) {
    parity_product = (parity_product)*userMatrix[i][permutation_set[i]];
    
}
parity_product = parity_product*(*parity_value);
*product = *product + parity_product;
printf("prod: %g\n",*product);
printf("parity prod: %g\n", parity_product);
printf("\n");
}

int factorial(int input) {
int i = 0;
int output = input;
if(input < 0) {
    printf("ERROR, factorial input must be >= 0\n");
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

void swap(int* x, int* y) { 
    int temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void permute(int* perm_index, int permutation_array[][COLUMNS], int* term_array, int l, int f) {
    int i = 0;
    int j = 0;

    if(l == f) {
        for(j = 0;j <= f; j++) {
            permutation_array[*perm_index][j] = term_array[j];
        }
        *perm_index = *perm_index + 1;
    }
    else {
        for(i = l;i <= f; i++) {
            swap(&term_array[l],&term_array[i]);
            permute(perm_index, permutation_array, term_array,l+1,f);
            swap(&term_array[l],&term_array[i]);
        }


    }
}
