#include<stdio.h>
void towers(int, char, char, char);
void main()
{
     int num;
    printf("ENTER THE NUMBER OF DISKS\n");
    scanf("%d",&num);
    printf("THE SEQUENCE INVOLVED ARE:\n");
    towers(num,'A','C','B');
}

void towers(int num, char A, char C, char B)
{
if(num==1)
{printf("MOVE DISK 1 FROM %c TO %c\n",A,C);
return;
}
towers(num-1,A,B,C);
printf("MOVE DISK %d FROM %c TO %c\n",num,A,C);
towers(num-1,B,C,A);
}

