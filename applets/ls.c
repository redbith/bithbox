#include <stdio.h>
#include <dirent.h>
#include "../bithbox.h"

int applet_ls(int argc, char *argv[]) {
    /* Use the specified directory path, or fallback to the current directory "." */
    char *dir_path = (argc > 1) ? argv[1] : ".";
    DIR *dir = opendir(dir_path);

    if (!dir) {
        perror("ls error");
        return 1;
    }

    struct dirent *entry;
    /* Read all items inside the directory */
    while ((entry = readdir(dir)) != NULL) {
        /* Skip hidden files and directories starting with a dot (.) */
        if (entry->d_name[0] == '.') continue;
        
        printf("%s  ", entry->d_name);
    }
    printf("\n");

    closedir(dir);
    return 0;
}