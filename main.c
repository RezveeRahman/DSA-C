#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\a : Hello world!\n");
    printf("Testing the C ANSI Ecape characters.\n"
            "In This will only work if the console supports\n"
            "ASNI Standards so there might be no colored outputs.\n");
    printf("\x1B[%dm""\rHELLO!\n", 32);
    /**
     * To create a  ANSI Escape sequence we start with following
     * \\x1B[<integer>m Characters after that. I recommend the following
     * "\x1B[%dm""\rHello!\n".
     * The usage of the return carriage can help reposition the cursor in
     * the initial position of the line.
     */
    return 0;
}
