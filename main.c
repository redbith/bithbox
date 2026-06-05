#include <stdio.h>
#include <string.h>
#include "bithbox.h"

/* Extracts the actual binary name by removing the path prefix (e.g., "/bin/ls" -> "ls") */
const char* get_applet_name(const char *path) {
    const char *token = strrchr(path, '/');
    return token ? token + 1 : path;
}

int main(int argc, char *argv[]) {
    if (argc < 1) return 1;

    const char *cmd = get_applet_name(argv[0]);

    /* If the binary is executed directly (e.g., ./bithbox echo hello) */
    if (strcmp(cmd, "bithbox") == 0) {
        if (argc < 2) {
            fprintf(stderr, "Usage: bithbox <command> [arguments]\n");
            fprintf(stderr, "Available commands: echo, cat, ls\n");
            return 1;
        }
        /* Shift arguments to the right to process the inner command */
        cmd = argv[1];
        argv++;
        argc--;
    }

    /* Command routing table (Lookup) */
    if (strcmp(cmd, "echo") == 0) {
        return applet_echo(argc, argv);
    } else if (strcmp(cmd, "cat") == 0) {
        return applet_cat(argc, argv);
    } else if (strcmp(cmd, "ls") == 0) {
        return applet_ls(argc, argv);
    }

    /* If the requested command is not supported */
    fprintf(stderr, "bithbox: '%s' command not found.\n", cmd);
    return 1;
}