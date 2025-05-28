#include<stdio.h>
int main()
{
int val;
scanf("%d",&val);
__asm__ __volatile__(
"add:\n"
"ADD x1,x1,x0\n"
"SUB x0,x0,#1\n"
"CMP x0,#0\n"
"BNE add\n"
"MOV x0,x1\n"
:"=r"(val)
:"0"(val)
:
);
printf("sum is %d\n",val);
return 0;
}
