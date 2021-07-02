#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int total = 0;
int difficultyLevel = 0;
int outputSCR(int a[][9])
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
int output(int a[][9])
{
    int i,j;
    FILE *fp;
    fp = fopen("test.txt","w");
    for(i = 0; i < 9; ++i)
    {
        for(j = 0; j < 9; ++j)
        {
            fprintf(fp,"%d ",a[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
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
int has_one_solution(int b[][9], int row, int column)
{
    int i, j;
    int a[9][9];
    if(total)
    {
        return 1;
    }
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
            total = 1;
            return 1;
        }
    }
    if(column == 9)
    {
        return has_one_solution(a, row + 1, 0);
    }
    if(a[row][column] == 0)
    {
        for(i = 1; i <= 9; i++)
        {
            if(can_fit(a, i, row, column))
            {
                a[row][column] = i;
                if(total)
                {
                    return 1;
                }
                has_one_solution(a, row, column + 1);
            }
        }
    }
    else
    {
        return has_one_solution(a, row, column + 1);
    }
}
int get(int a[][9])
{
    int row, column, number;
    srand(time(NULL));
    has_one_solution(a, 0, 0);
    while(total && difficultyLevel < 30)
    {
        total = 0;
        row = rand() % 9;
        column = rand() % 9;
        number = (rand() % 9) + 1;
        if(!a[row][column])
        {
            while(!can_fit(a, number, row, column))
            {
                number = (rand() % 9) + 1;
            }
            a[row][column] = number;
            has_one_solution(a, 0, 0);
            if(!total)
            {
                a[row][column] = 0;
                total = 1;
                continue;
            }
            difficultyLevel++;
            fprintf(stdout, "..",difficultyLevel);
        }
        total = 1;
    }
    fprintf(stdout,"\nDone Question is now created !!! Solve it -->\n");
    output(a);
    outputSCR(a);
}
int main()
{
    int toGive[9][9];
    int i, j;
    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            toGive[i][j] = 0;
    fprintf(stdout,"Creating Question ..");
    get(toGive);
    return 0;
}

