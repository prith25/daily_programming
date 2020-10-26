/*Operation in a matrix
1. Matrix Addition.
2. Matrix Multiplication.
3. Transpose of a Matrix.
4. Finding singular or non-singular Matrix.
5. Finding orthongonal or non-orthogonal Matrix.*/
#include <stdio.h>
#include <windows.h>
#define N 4
void create(int a[5][5])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            scanf("%d",&a[i][j]);
    }
    return;
}
void display(int a[5][5])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
void add(int a[5][5], int b[5][5], int c[5][5])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            c[i][j] = a[i][j] + b[i][j];
    }
    return;
}
void multiply(int a[5][5], int b[5][5], int c[5][5])
{
    int i, j, k;
    for(k=0; k<N; k++)
    {
        for(i=0; i<N; i++)
        {
            c[k][i] = 0;
            for(j=0; j<N; j++)
                c[k][i] += a[k][j]*b[j][i];
        }
    }
}
void calc(int a[5][5], int temp[5][5], int p, int q, int n)
{
    int i=0, j=0, row, col;
    for(row=0; row<n; row++)
    {
        for(col=0; col<n; col++)
        {
            if(row!=p && col!=q)
            {
                temp[i][j++] = a[row][col];
                if(j == n-1)
                {
                    i++;
                    j=0;
                }
            }
        }
    }
}
int determinant(int a[5][5], int n)
{
    int p;
    if(n == 2)
        return a[0][0]*a[1][1] - a[1][0]*a[0][1];
    int sign = 1, temp[5][5], i, D=0;
    for(i=0; i<n; i++)
    {
        calc(a,temp,0,i,n);
        D += sign * a[0][i] * determinant(temp,n-1);
        sign *= -1;
    }
    return D;
}
void transpose(int a[5][5], int c[5][5])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            c[i][j] = a[j][i];
    }
    return;
}
int orthogonal(int a[5][5])
{
    int i, m1[5][5], m2[5][5];
    transpose(a,m1);
    multiply(a,m1,m2);
    for(i=0; i<N; i++)
    {
        if(m2[i] != 1)
            return 0;
    }
    return 1;
}
int main()
{
    system("cls");
    int a[5][5] = { {1, 2, 6, 6},
                    {4, 7, 3, 2},
                    {0, 0, 0, 0},
                    {1, 2, 2, 9},
                    {2, 1, 2, 3}};
    int b[5][5] = { {1, 2, 3, 4},
                    {2, 5, 7, 3},
                    {4, 10, 14, 6},
                    {3, 4, 2, 7},
                    {1, 2, 1, 4}};
    int c[5][5], d;
    /*printf("\nEnter the elements of matrix A: ");
    create(a);
    printf("\nEnter the elements of matrix B: ");
    create(b);*/
    printf("\nMatrix A\n");
    display(a);
    printf("\nMatrix B\n");
    display(b);
    printf("\nTranspose of A\n");
    transpose(a,c);
    display(c);
    printf("\nTranspose of B\n");
    transpose(b,c);
    display(c);
    printf("\nAddition of A and B");
    add(a,b,c);
    printf("\nResultant Matrix\n");
    display(c);
    printf("\nMultiplication of Matrix");
    multiply(a,b,c);
    printf("\nResultant Matrix\n");
    display(c);
    d = determinant(a,N);
    if(d == 0)
        printf("\nMatrix is a Singular Matrix");
    else
        printf("\nMatrix is Non-Singular Matrix. D = %d",d);
    d = orthogonal(a);
    if(d == 1)
        printf("\nMatrix is orthogonal");
    else
        printf("\nMatrix is not orthogonal");
    return 0;
}
