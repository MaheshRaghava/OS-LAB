#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main()
{
    char buff[100];
    DIR *dirp;
    struct dirent *dptr;
    printf("\n\nEnter directory name: ");
    scanf("%s", buff);
    // Try opening the directory
    dirp = opendir(buff);
    if (dirp == NULL)
    {
        printf("The given directory does not exist.\n");
        exit(1);
    }

    // Read and print directory contents
    printf("Contents of directory %s:\n", buff);
    while ((dptr = readdir(dirp)) != NULL) 
    {
        printf("%s\n", dptr->d_name);
    }
    // Close the directory stream
    closedir(dirp);
    return 0;
}
