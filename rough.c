#include <stdio.h>
#include <string.h>
char input[10], label[10], ch1, ch2;
int addr, w = 0, start, ptaddr, l, length = 0, end, count = 0, k, taddr, address, i = 0;
FILE *fp1, *fp2;
void main()
{
	fp1 = fopen("input.txt", "r");
	fp2 = fopen("output.txt", "w");
	fscanf(fp1, "%s", input); 
	fprintf(fp2, "\n-------------------------------------------------------\n");
	fprintf(fp2, "MEMORY ADDRESS\t\t\tCONTENTS");
	fprintf(fp2, "\n-------------------------------------------------------\n");
	while (strcmp(input, "E") != 0)
	{
           
		// if (strcmp(input, "H") == 0) //reading header
		// {
		// 	fscanf(fp1, "%s %x %x %s", label, &start, &end, input);
		// 	address = start; //1000
		// 	// printf("address:%s",input);
		// }
		// else if (strcmp(input, "T") == 0) //reading text record
		// {
			// l = length;
			// ptaddr = addr;
			// fscanf(fp1, "%x %x %s", &taddr, &length, input);
			// addr = taddr;
			// printf("length:%x,ptaddr:%x,addr:%x,input:%s\n",l,ptaddr,addr,input);
			// if (w == 0)
			// {
			// 	ptaddr = address;
			// 	w = 1;
			// 	printf("ptaddr2:%x\n",ptaddr);
			// }
			// for (k = 0; k < (taddr - (ptaddr + l)); k++)
			// {
			// 	address = address + 1;
			// 	fprintf(fp2, "xx");
			// 	count++;
			// 	if (count == 4)
			// 	{
			// 		fprintf(fp2, "  ");
			// 		i++;
			// 		if (i == 4)
			// 		{
			// 			fprintf(fp2, "\n\n%x\t\t", address);
			// 			i = 0;
			// 		}
			// 		count = 0;
			// 	}
			// }
			// if (taddr == start)
			// 	fprintf(fp2, "\n\n%x\t\t", taddr);
			// fprintf(fp2, "%c%c", input[0], input[1]);
			// check();
			// fprintf(fp2, "%c%c", input[2], input[3]);
			// check();
			// fprintf(fp2, "%c%c", input[4], input[5]);
			// check();
			// fscanf(fp1, "%s", input);
		// }
		
	}
	fprintf(fp2, "\n-------------------------------------------------------\n");
	fclose(fp1);
	fclose(fp2);
	
	
}