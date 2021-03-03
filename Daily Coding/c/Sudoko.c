/* Solving sudoko using backtracking */
#include <stdio.h>
int solve_sudoko(int grid[9][9]);
int find_unassigned(int grid[9][9], int *, int *);
int is_safe(int grid[9][9], int, int, int);
int in_row(int grid[9][9], int, int);
int in_col(int grid[9][9], int, int);
int in_square(int grid[9][9], int, int, int);
void print(int grid[9][9]);

int solve_sudoko(int grid[9][9])
{
    int row, col, num;
    if(!find_unassigned(grid,&row,&col))
        return 1;
    for(num=1; num<=9; num++)
    {
        if(is_safe(grid,row,col,num))
        {
            grid[row][col] = num;
            if(solve_sudoko(grid))
                return 1;
            grid[row][col] = 0;
        }
    }
    return 0;
}

int find_unassigned(int grid[9][9], int *row, int *col)
{
    for(*row=0; *row<9; (*row)++)
    {
        for(*col=0; *col<9; (*col)++)
        {
            if(grid[*row][*col] == 0)
                return 1;
        }
    }
    return 0;
}

int is_safe(int grid[9][9], int row, int col, int num)
{
    if(!in_row(grid,row,num) && 
       !in_col(grid,col,num) &&
       !in_square(grid,row-row%3,col-col%3,num) &&
       grid[row][col] == 0)
        return 1;
    return 0;
}

int in_row(int grid[9][9], int row, int num)
{
    for(int col=0; col<9; col++)
    {
        if(grid[row][col] == num)
            return 1;
    }
    return 0;
}

int in_col(int grid[9][9], int col, int num)
{
    for(int row=0; row<9; row++)
    {
        if(grid[row][col] == num)
            return 1;
    }
    return 0;
}

int in_square(int grid[9][9], int row, int col, int num)
{
    for(int r=0; r<3; r++)
    {
        for(int c=0; c<3; c++)
        {
            if(grid[r+row][c+col] == num)
                return 1;
        }
    }
    return 0;
}

void print(int grid[9][9])
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            printf("%d ",grid[i][j]);
        printf("\n");
    }
    return;
}

int main()
{
    int grid[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                       {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                       {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                       {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                       {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                       {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                       {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                       {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                       {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    if(solve_sudoko(grid))
        print(grid);
    else    
        printf("Invalid sudoko");
    return 0;
}
