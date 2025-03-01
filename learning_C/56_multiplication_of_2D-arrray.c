/* programe_54 */ 
/* author Ahsan ul haq */
/* roll number 22069120033 */
//multiplication of two 2D array

#include <stdio.h>

int main()
{
    // defining integers for rows and columns
    int r1, r2, c1, c2,sum;

    // defining array1 dimensions
    printf("Enter the dimensions of array1: ");
    scanf("%d %d", &r1, &c1);

    // defining array2 dimensions
    printf("Enter the dimensions of array2: ");
    scanf("%d %d", &r2, &c2);

    // condition to check whether multiplication is possible or not
    if (c1 != r2)
    {
        printf("Oops! Multiplication is not possible as dimensions didn't match.\n");
        return 1;
    }

    // defining matrices
    float m1[r1][c1], m2[r2][c2], m12[r1][c2];

    // initialize the product matrix
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            m12[i][j] = 0;
        }
    }

    // input elements of matrix 1
    printf("Enter the elements of m1:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("Enter value of m1[%d][%d]: ,m2[%d][%d]: ", i, j,i, j);
            scanf("%f %f", &m1[i][j],&m2[i][j]);
        }
    }

    // // input elements of matrix 2
    // printf("Enter the elements of m2:\n");
    // for (int i = 0; i < r2; i++)
    // {
    //     for (int j = 0; j < c2; j++)
    //     {
    //         printf("Enter value of m2[%d][%d]: ", i, j);
    //         scanf("%f", &m2[i][j]);
    //     }
    // }

    // product block
    sum = 0 ;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                m12[i][j] += m1[i][k]*m2[k][j];
                // sum = sum + m1[i][k] * m2[k][j];
                // m12[i][j] = sum;
            }
        }
    }
    // printing the product matrix
    printf("Product of m1 and m2 is:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%.2f ", m12[i][j]);
        }
        printf("\n");
    }

    return 0;
}
