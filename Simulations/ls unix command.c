#include <stdio.h>
#include <dirent.h>

void main(int argc, char **argv) {
    DIR *dp;
    struct dirent *link;

    dp = opendir(argv[1]);  // Open the specified directory.
    if (dp == NULL) {
        printf("Unable to open directory: %s\n", argv[1]);
        return;
    }

    printf("Contents of the directory %s are:\n", argv[1]);
    while ((link = readdir(dp)) != NULL) {
        printf("%s\n", link->d_name);  // Print each file or folder name.
    }
    closedir(dp);  // Close the directory.
}
