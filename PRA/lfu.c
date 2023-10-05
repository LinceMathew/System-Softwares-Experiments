// Least Frequently Used (LFU) page replacement algorithm

#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 50

int frames[MAX_FRAMES];
int pages[MAX_PAGES];
int frequency[MAX_FRAMES];
int page_count, frame_count;

void initialize() {
    for (int i = 0; i < frame_count; i++) {
        frames[i] = -1;
        frequency[i] = 0;
    }
}

int isPagePresent(int page) {
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == page)
            return i;
    }
    return -1;
}

int getLFUIndex() {
    int min = frequency[0];
    int index = 0;

    for (int i = 1; i < frame_count; i++) {
        if (frequency[i] < min) {
            min = frequency[i];
            index = i;
        }
    }

    return index;
}

void LFU() {
    int page_faults = 0;

    for (int i = 0; i < page_count; i++) {
        int page = pages[i];
        int index = isPagePresent(page);

        if (index == -1) {
            int lfu_index = getLFUIndex();
            frames[lfu_index] = page;
            frequency[lfu_index] = 1;
            page_faults++;
        } else {
            frequency[index]++;
        }
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);

    printf("Enter the number of pages: ");
    scanf("%d", &page_count);

    printf("Enter the page references: ");
    for (int i = 0; i < page_count; i++) {
        scanf("%d", &pages[i]);
    }

    initialize();
    LFU();

    return 0;
}
