#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fp;
    int i, l, j, staddr1;
    char name[10], line[50], name1[10], staddr[10];
    printf("enter program name for verify:\n");
    scanf("%s", name);
    fp = fopen("input.txt", "r");
    fscanf(fp, "%s", line);
    for (i = 2, j = 0; i < 8, j < 6; i++, j++)
    {
        name1[j] = line[i];
    }
    name1[j] = '\0';
    if (strcmp(name, name1) == 0) {
    printf("verification success \n");

}
