#include<stdio.h>
int main ()
{
    int a,b,count_sum;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    for (int i=a; i<=b; i++)
    {
        for(int j=a; j<=b; j++)
        {
            count_sum = i +j ;
            printf("sum of %d %d is %d\n ",i,j,count_sum);
        }
        
    }
}