#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    int sc = 0;

    fp = fopen(argv[1], "r");  // Open the source file in read mode.
    if (fp == NULL) {
        printf("Unable to open the file: %s\n", argv[1]);
    } else {
        // Read the file character by character and count spaces.
        while (!feof(fp)) {
            ch = fgetc(fp);
            if (ch == ' ')
                sc++;
        }
        printf("Number of spaces: %d\n", sc);
        fclose(fp);
    }
    return 0;
}
