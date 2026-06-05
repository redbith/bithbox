#include <stdio.h>
#include <stdlib.h>
#include "../bithbox.h"

int applet_cat(int argc, char *argv[]) {
    /* Check if the user provided a filename argument */
    if (argc < 2) {
        fprintf(stderr, "Usage: cat <filename>\n");
        return 1;
    }

    /* Open the specified file in read-only mode */
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("cat error");
        return 1;
    }

    /* Read the file character by character and print it to the screen */
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
    return 0;
}
