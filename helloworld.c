//helloworld.c
/*
 * This program prints "Hello World" a specified number of times.
 * 
 * Command Line Arguments:
 *   - An integer specifying how many times to print "Hello World".
 * 
 * Example Usage:
 *   ./helloworld 3
 *   Output:
 *   Hello World
 *   Hello World
 *   Hello World
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./helloworld <number>\n");
        return 1;
    }

    int count = atoi(argv[1]);
    for (int i = 0; i < count; i++) {
        printf("Hello World\n");
    }

    return 0;
}
