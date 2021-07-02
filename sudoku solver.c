#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int result = 0;
int input(int a[][9])
{
    int i,j;
    FILE *f;
    f = fopen("test.txt","r");
    for(i = 0; i < 9; ++i)
    {
        for(j = 0; j < 9; ++j)
        {
            fscanf(f,"%d",&a[i][j]);
        }
    }
    fclose(f);
}
int output(int a[][9])
{
    int i,j;
    for(i = 0; i < 9; ++i)
    {
        for(j = 0; j < 9; ++j)
        {
            fprintf(stdout,"%2d ",a[i][j]);
        }
        fprintf(stdout,"\n");
    }
}
int can_fit(int a[][9], int value, int row, int column)
{
    int i, j, boxMaxRow, boxMaxColumn, boxMinRow, boxMinColumn;
    for(i = 0; i < 9; i++)
    {
        if(a[row][i] == value)
            return 0;
        if(a[i][column] == value)
            return 0;
    }
    boxMinRow = (row/3)*3;
    boxMaxRow = boxMinRow + 3;
    boxMinColumn = (column/3)*3;
    boxMaxColumn = boxMinColumn + 3;
    for(i = boxMinRow; i < boxMaxRow; ++i)
    {
        for(j = boxMinColumn; j < boxMaxColumn; ++j)
        {
            if(a[i][j] == value)
            {
                return 0;
            }
        }
    }
    return 1;
}
int is_complete(int a[][9])
{
    int i, j;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; ++j)
        {
            if(!a[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int solve(int b[][9], int row, int column)
{
    int i, j;
    int a[9][9];
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            a[i][j] = b[i][j];
        }
    }
    if(row == 9)
    {
        if(is_complete(a))
        {
            fprintf(stdout, "Solving\n");
            output(a);
            result = 1;
            return 1;
        }
    }
    if(column == 9)
    {
        return solve(a, row + 1, 0);
    }
    if(a[row][column] == 0)
    {
        for(i = 1; i <= 9; i++)
        {
            if(can_fit(a, i, row, column))
            {
                a[row][column] = i;
                if(!solve(a, row, column + 1))
                {
                    continue;
                }
            }
        }
    }
    else
    {
        return solve(a, row, column + 1);
    }
}
int main()
{
    int given[9][9];
    time_t startTime, endTime;
    input(given);
    startTime = clock();
    solve(given, 0, 0);
    printf("This is the final Solved Puzzle\n");
    endTime = clock();
    if(!result)
    {
        fprintf(stdout, "Couldn't solve this !!! May be something wrong !!! \n");
        output(given);
    }
    else
    {
        fprintf(stdout, "Total time taken is %f s\n",
                 (endTime-startTime)/(CLOCKS_PER_SEC * 1.0));
    }
    return 0;
}
