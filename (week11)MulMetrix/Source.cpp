#include <stdio.h>

#define ROW 3
#define column 3

void matrixInput(int mat[ROW][column]);
void matrixPrint(int mat[ROW][column]);
void matrixMultiply(int mat1[ROW][column], int mat2[ROW][column], int result[ROW][column]);

int main()
{
    int mat1[ROW][column];
    int mat2[ROW][column];
    int product[ROW][column];

    printf("Matrix 1 (size %dx%d) :\n", ROW, column);
    matrixInput(mat1);

    printf("Matrix 2 (size %dx%d) :\n", ROW, column);
    matrixInput(mat2);

    matrixMultiply(mat1, mat2, product);

    printf("Result is : \n");
    matrixPrint(product);

    return 0;
}


void matrixInput(int mat[ROW][column])
{
    int row, col;

    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < column; col++)
        {
            scanf_s("%d", (*(mat + row) + col));
        }
    }
}


void matrixPrint(int mat[ROW][column])
{
    int row, col;

    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < column; col++)
        {
            printf("%d ", *(*(mat + row) + col));
        }

        printf("\n");
    }
}


void matrixMultiply(int mat1[ROW][column], int mat2[ROW][column], int result[ROW][column])
{
    int row, col, i;
    int sum;


    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < column; col++)
        {
            sum = 0;
            for (i = 0; i < column; i++)
            {
                sum += (*(*(mat1 + row) + i)) * (*(*(mat2 + i) + col));
            }
            *(*(result + row) + col) = sum;
        }
    }
}