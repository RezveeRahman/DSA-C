/**
 * @author: Rezvee Rahman
 * @date: 09/02/2024
 * 
 * @description: We are doing some pointer practice. This is to
 * understand and program pointers.
 */

#include <stdio.h>
#include <stdlib.h>

int f(int **iptr);
void pointing_to_array(void);

/**
 * Main entry of the pogram
 */
int main(void) {

    pointing_to_array();

    return EXIT_SUCCESS;
}

/**
 * This is to understand automatic variables.
 */
int f(int **iptr) {

    /**
     * Automatic variables - a varaible that automatically get's
     * assigned and also allocates memory (based on the type).The
     * variable is deallocated automatically when we leave the scope
     * of the function.
     */
    int a = 100;

    *iptr = &a;

    return (0);
}

void pointing_to_array(void) {
    /**
     * We are going to have a pointer and an array. The pointer will set
     * the 0th index of the array to 21
     */
    int intArr[10];
    int *iptr;

    iptr = intArr;

    for (int j = 0; j < 10; j++) {
        *iptr = (102 + j);
        printf("Pointing to: [%0x] with a value of: [%d]\n", iptr, *iptr);
        iptr++;
    }
}
