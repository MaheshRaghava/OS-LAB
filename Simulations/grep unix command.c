#include <stdio.h>
#include <string.h>
#define MAX 1024

void usage()
{
    printf("Usage: ./a.out <filename> <word>\n");
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char fline[MAX];
    char *newline;
    int count = 0;
    int occurrences = 0;

    if (argc != 3)
    {
        usage();
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("grep: Could not open file: %s\n", argv[1]);
        exit(1);
    }
    
    while (fgets(fline, MAX, fp) != NULL)
    {
        count++;
        if ((newline = strchr(fline, '\n')) != NULL)
        {
            *newline = '\0';
        }
        if (strstr(fline, argv[2]) != NULL)
        {
            printf("%s: %d %s\n", argv[1], count, fline);
            occurrences++;
        }
    }

    fclose(fp);
    return 0;
}
