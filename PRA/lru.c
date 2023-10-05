// Least Recently Used (LRU) page replacement algorithm

#include <stdio.h>

#define MAX_FRAMES 3

int frames[MAX_FRAMES];
int counter[MAX_FRAMES];
int page_faults = 0;

void initialize() {
    for(int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;  // Initialize frames with -1 (indicating empty frame)
        counter[i] = 0;  // Initialize counter for each frame
    }
}

void displayFrames() {
    for(int i = 0; i < MAX_FRAMES; i++) {
        if(frames[i] != -1) {
            printf("%d ", frames[i]);
        }
        else {
            printf("_ ");  // Display _ for empty frames
        }
    }
    printf("\n");
}

int findLRU() {
    int min = counter[0], lru_index = 0;

    for(int i = 1; i < MAX_FRAMES; i++) {
        if(counter[i] < min) {
            min = counter[i];
            lru_index = i;
        }
    }

    return lru_index;
}

void pageReplacement(int page) {
    int isPageFault = 1;

    for(int i = 0; i < MAX_FRAMES; i++) {
        if(frames[i] == page) {
            isPageFault = 0;
            counter[i] = 0; // Reset counter for the used page
        } else if (frames[i] != -1) {
            counter[i]++;
        }
    }

    if(isPageFault) {
        int lru_index = findLRU();
        frames[lru_index] = page;
        counter[lru_index] = 0; // Reset counter for the new page
        page_faults++;
    }
}

int main() {
    initialize();

    int page_sequence[] = {1, 3, 0, 3, 5, 6, 3, 1, 0, 3, 6};
    int n = sizeof(page_sequence) / sizeof(page_sequence[0]);

    for(int i = 0; i < n; i++) {
        pageReplacement(page_sequence[i]);
        displayFrames();
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}