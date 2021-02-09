#include <stdio.h>

int main (void)
{
	int i, j, rows, cols;
	int nRows, nCols;

	// Ask for matrix dimensions
	printf("Number of rows: ");
	scanf("%i", &rows);
	printf("Number of cols: ");
	scanf("%i", &cols);

	int matrix[rows][cols];

	// Function declarations
	void displayMatrix (int nRows, int nCols, int matrix[nRows][nCols]);
	void transposeMatrix(int nRows, int nCols, int matrix[nRows][nCols]);


	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < cols; ++j)
		{
			printf("M[%i][%i] = ", i, j);
			scanf("%i", &matrix[i][j]);
		}
	}

	printf("\n");

	displayMatrix(rows, cols, matrix);
	transposeMatrix(rows,cols, matrix);

	return 0;
}


void displayMatrix (int nRows, int nCols, int matrix[nRows][nCols])
{
	int row, column;

	for (row = 0; row < nRows; row++){
		for (column = 0; column < nCols; column++){
			printf("%2i ", matrix[row][column]);	
		}
		printf("\n");
	}
}	


void transposeMatrix (int nRows, int nCols, int matrix[nRows][nCols])
{
	int N[nCols][nRows];
	int i, j;
	
	for (i = 0; i < nCols; ++i){
		for (j = 0; j < nRows; ++j){
			N[i][j] = matrix[j][i];
		}
	}
	
	for (i = 0; i < nCols; i++){
		printf("\n");
		for (j = 0; j < nRows; j++){
			printf("%2i ", N[i][j]);	
		}
	}	
}

