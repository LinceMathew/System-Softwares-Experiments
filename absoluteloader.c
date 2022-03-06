#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main() {
  FILE * fp;
  int i, addr1, l, j, staddr1;
  char name[10], line[50], name1[10], addr[10], rec[10], ch, staddr[10];
  printf("enter program name for verify:\n");
  scanf("%s", name);
  fp = fopen("input.txt", "r");
  fscanf(fp, "%s", line);
  for (i = 2, j = 0; i < 8, j < 6; i++, j++)
    name1[j] = line[i];
    name1[j] = '\0';
  printf("program name is: %s\n", name1);
  if (strcmp(name, name1) == 0) {
    printf("verification success \n");
    do {
      fscanf(fp, "%s", line);
      if (line[0] == 'T') {
        for (i = 2, j = 0; i < 8, j < 6; i++, j++)
          staddr[j] = line[i];
        staddr[j] = '\0';
        staddr1 = atoi(staddr);
        i = 12;
        while (line[i] != '$') {
          if (line[i] != '^') {
            printf("00%d \t %c%c\n", staddr1, line[i], line[i + 1]);
            staddr1++;
            i = i + 2;
          } else i++;
        }
      } else if (line[0] = 'E')
        fclose(fp);
    } while (!feof(fp));
  }
  else 
    printf("prgram  name is different verification failed\n");

}

// begin
//     read header record
//     verify program name and length
//     read first Text record
//     while record type != 'E' do
//         begin 
//             (if object code is in character form,convert into 
//             internal representation)
//             move object code to specified location in memory
//             read next object program record
//         end
//     jump to address specified in End record
// end
