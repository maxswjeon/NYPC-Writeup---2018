#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
   int size;
   int** data;
}Matrix;
void turnMatrix(Matrix&);
void changeValue(Matrix&);
void initMatrix(Matrix&, int);
void destroyMatrix(Matrix&);
void printMatrix(Matrix);
int main()
{
   int size, count;
   Matrix matrix;
   scanf("%d", &size);
   scanf("%d", &count);
   initMatrix(matrix, size);
   for (int i = 0; i < size; ++i)
   {
      for (int j = 0; j < size; ++j)
      {
         scanf("%d", &matrix.data[i][j]);
      }
   }
   for (int i = 0; i < count; ++i)
   {
      changeValue(matrix);
      turnMatrix(matrix);
   }
   printMatrix(matrix);
   destroyMatrix(matrix);
}
void turnMatrix(Matrix& matrix)
{
   Matrix temp;
   initMatrix(temp, matrix.size);
   for (int i = 0; i < matrix.size; ++i)
   {
      for (int j = 0; j < matrix.size; ++j)
      {
         temp.data[i][j] = matrix.data[i][j];
         matrix.data[i][j] = 0;
      }
   }
   for (int i = 0; i < temp.size; ++i)
   {
      for (int j = 0; j < temp.size; ++j)
      {
         matrix.data[temp.size - 1 - j][i] = temp.data[i][j];
      }
   }
   destroyMatrix(temp);
}
void changeValue(Matrix& matrix)
{
   for (int i = 0; i < matrix.size; ++i)
   {
      for (int j = 0; j < matrix.size - 1; ++j)
      {
         if (matrix.data[i][j] > matrix.data[i][j + 1])
         {
            int temp = matrix.data[i][j + 1];
            matrix.data[i][j + 1] = matrix.data[i][j];
            matrix.data[i][j] = temp;
         }
      }
   }
}
void initMatrix(Matrix& matrix, int size)
{
   matrix.size = size;
   matrix.data = (int**)malloc(sizeof(int) * size * size);
   for (int i = 0; i < size; ++i)
   {
      matrix.data[i] = (int*)malloc(sizeof(int) * size);
      memset(matrix.data[i], 0, sizeof(int) * size);
   }
}
void destroyMatrix(Matrix& matrix)
{
   for (int i = 0; i < matrix.size; ++i)
   {
      free(matrix.data[i]);
   }
   free(matrix.data);
   matrix.size = 0;
}
void printMatrix(Matrix matrix)
{
   for (int i = 0; i < matrix.size; ++i)
   {
      for (int j = 0; j < matrix.size; ++j)
      {
         printf("%d ", matrix.data[i][j]);
      }
      printf("\n");
   }
}