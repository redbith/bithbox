#include <stdio.h>
#include "../bithbox.h"

int applet_echo(int argc, char *argv[]) {
    /* Loop through arguments and print them with a space in between */
    for (int i = 1; i < argc; i++) {
        printf("%s%s", argv[i], (i == argc - 1) ? "" : " ");
    }
    printf("\n");
    return 0;
}