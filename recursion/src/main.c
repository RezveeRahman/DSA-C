/**
 * @author: Rezvee Rahman
 * @details: Creating a simple recursion function in C and understandig
 * the basic idea behind recursion.
 * 
 * VERY UNSAFE CODE, DO NOT ATTEMPT TO RUN UNLESS YOU KNOW WHAT YOU ARE
 * DOING!
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../headers/recursion.h"

int main(void) {
    int const CHAOS = 13;

    for (int i = 0; i < CHAOS; i++) {
        fork();
        printf("Regular Recursion: %d\n", fact(CHAOS));
        sleep(1);
    }

    printf("Using tail factorial instead.\n");

    for (int i = 0; i < CHAOS; i++) {
        fork();
        printf("Tail Recursion: %d\n", tail_fact(CHAOS, 1));
        sleep(1);
    }

    return EXIT_SUCCESS;
}


int fact(int n) {
    if (n < 0) {
        printf("We have reached below 0???\n");
        return (0);
    } else if (n == 0) {
        printf("Currently reached 0\n");
        return (1);
    } else if (n == 1) {
        printf("Currently reached 1\n");
        return (1);
    }
    else {
        return n * fact(n - 1);
    }
}

int tail_fact(int n, int a) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else if (n == 1) {
        return a;
    } else {
        return tail_fact(n - 1, n * a);
    }
}