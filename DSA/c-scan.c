#include <stdio.h>

void cscan(int arr[], int head, int size, int seek_sequence[]) {
    int seek_count = 0;
    int distance, cur_track;
    
    // Appending end values to the end and start of the array
    arr[size] = head;
    arr[size+1] = 0;

    // Sorting the array
    for(int i = 0; i <= size; i++) {
        for(int j = i+1; j <= size+1; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int index;
    for(int i = 0; i <= size+1; i++) {
        if(head == arr[i]) {
            index = i;
            break;
        }
    }

    // Moving the disk arm to the end
    for(int i = index; i <= size+1; i++) {
        cur_track = arr[i];
        seek_sequence[seek_count++] = cur_track;
    }

    // Moving the disk arm back to the start
    for(int i = 0; i < index; i++) {
        cur_track = arr[i];
        seek_sequence[seek_count++] = cur_track;
    }

    printf("Seek Sequence is: ");
    for(int i = 0; i < seek_count; i++) {
        printf("%d ", seek_sequence[i]);
    }

    printf("\nTotal seek time: %d\n", seek_count-1);
}

int main() {
    int size, head;
    printf("Enter the size of request queue: ");
    scanf("%d", &size);

    int arr[size];
    int seek_sequence[size+2]; // To store seek sequence

    printf("Enter the request queue: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    cscan(arr, head, size, seek_sequence);

    return 0;
}
