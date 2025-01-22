#include <stdio.h>
#include <string.h>
#define MAX 1024

void usage() {
    printf("Usage: ./a.out <filename> <word>\n");
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char fline[MAX];
    char *newline;
    int count = 0;
    int occurrences = 0;

    if (argc != 3) {
        usage();
        return 1;
    }

    fp = fopen(argv[1], "r");  // Open the file in read mode.
    if (fp == NULL) {
        printf("grep: Could not open file: %s\n", argv[1]);
        return 1;
    }

    // Read the file line by line.
    while (fgets(fline, MAX, fp) != NULL) {
        count++;  // Line number.

        // Remove the newline character from the line.
        if ((newline = strchr(fline, '\n')) != NULL) {
            *newline = '\0';
        }

        // Check if the specified word exists in the line.
        if (strstr(fline, argv[2]) != NULL) {
            printf("%s: %d %s\n", argv[1], count, fline);
            occurrences++;
        }
    }

    fclose(fp);  // Close the file.
    return 0;
}
