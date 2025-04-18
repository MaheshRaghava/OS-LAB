#include <stdio.h>

int main() {
    int frames, pages[50], temp[50];
    int i, j, k, pageFaults = 0, frameIndex = 0, n, found;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++) {
        temp[i] = -1;
    }

    printf("\nPage Replacement Process (FIFO):\n");

    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < frames; j++) {
            if(temp[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            temp[frameIndex] = pages[i];
            frameIndex = (frameIndex + 1) % frames;
            pageFaults++;

            for(k = 0; k < frames; k++) {
                if(temp[k] != -1)
                    printf("%d ", temp[k]);
                else
                    printf("- ");
            }
            printf(" (Page Fault)\n");
        } else {
            for(k = 0; k < frames; k++) {
                if(temp[k] != -1)
                    printf("%d ", temp[k]);
                else
                    printf("- ");
            }
            printf(" (No Page Fault)\n");
        }
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
