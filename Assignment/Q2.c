#include <stdio.h>
#include <stdlib.h>

// 2D Dynamic Int array library provided earlier
typedef struct {
    int** data;
    int rows;
    int cols;
} IntMatrix;

IntMatrix createIntMatrix(int rows, int cols) {
    IntMatrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        mat.data[i] = (int*)malloc(cols * sizeof(int));
    }
    return mat;
}

void freeIntMatrix(IntMatrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
}

// Function to calculate the product of two matrices
IntMatrix matrixProduct(const IntMatrix* mat1, const IntMatrix* mat2) {
    IntMatrix result;
    if (mat1->cols != mat2->rows) {
        printf("Error: Number of columns of matrix 1 should be equal to number of rows of matrix 2.\n");
        result.rows = result.cols = 0;
        result.data = NULL;
        return result;
    }

    result = createIntMatrix(mat1->rows, mat2->cols);

    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < mat1->cols; k++) {
                result.data[i][j] += mat1->data[i][k] * mat2->data[k][j];
            }
        }
    }

    return result;
}

int main() {
    // Example matrices
    IntMatrix mat1 = createIntMatrix(2, 3);
    IntMatrix mat2 = createIntMatrix(3, 2);

    // Fill matrices with example values
    // (for simplicity, let's assume matrices are filled)

    // Calculate product
    IntMatrix product = matrixProduct(&mat1, &mat2);

    // Display result
    if (product.data != NULL) {
        printf("Product of matrices is:\n");
        for (int i = 0; i < product.rows; i++) {
            for (int j = 0; j < product.cols; j++) {
                printf("%d ", product.data[i][j]);
            }
            printf("\n");
        }
        // Free memory allocated for result
        freeIntMatrix(&product);
    }

    // Free memory allocated for matrices
    freeIntMatrix(&mat1);
    freeIntMatrix(&mat2);

    return 0;
}