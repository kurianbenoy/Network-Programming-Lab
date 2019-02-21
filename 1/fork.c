#include<stdio.h>
#include<unistd.h>

void main()
{
  int n,i;
  printf("Enter the no of forks");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    fork();
    printf("Forked\n");
   }
}
