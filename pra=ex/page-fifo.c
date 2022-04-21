#include <stdio.h>
void main()
{
    printf("enter the number of pages \n");
    int n;
    scanf("%d", &n);
    printf("enter the page numbers");
    int i, a[10];
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("enter the number of frames\n");
    int no;
    scanf("%d", &no);
    int frame[10];
    for (i = 0; i < no; i++)
        frame[i] = -1;
    int j = 0;
    printf("ref string \t page frame \n";
    int k, count = 0;
    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t", a[i]);
        int avail = 0;
        for (k = 0; k < no; k++)
        {
            if (frame[k] == a[i])
                avail = 1;
            if (avail == 0)
            {
                frame[j] = a[i];
                j = (j + 1) % no;
                count++;
                for (k = 0; k < no; k++)
                {
                    printf("%d\t", frame[k]);
                }
            }
        }
        printf("\n");
    }
}