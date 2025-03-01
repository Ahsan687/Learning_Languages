#include <stdio.h>
int main()
{
    int n;
    printf("Enter the dimestion of array");
    scanf("%d",&n);
    int array_1[n],array_2[n],prod_array[n];
    
    for (int i= 0 ; i< n ;i++)
    {
        printf("give the elements of array_1[%d]",i);
        scanf("%d", &array_1[i]);
    }
    for (int i= 0 ; i< n ;i++)
    {
        printf("give the elements of array_2[%d]",i);
        scanf("%d", &array_2[i]);
    }
    
    for (int i= 0 ; i< n ;i++)
    {
        prod_array[i] += array_1[i]*array_2[i];
        printf("prod =%d\n",prod_array[i]);
    }
//     int k,sum = 0;
//     for (k=0;k<n;k++)
//     {
//         sum = sum + prod_array[k];
//     }
//     printf("prod =%d\n",sum);
}