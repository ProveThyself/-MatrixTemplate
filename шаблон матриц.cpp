#include <cstdio>

template <typename T>
void addMatrices(const T* matrix1, const T* matrix2, T* result, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            // Обращение к элементам через смещение
            size_t offset = i * cols + j;
            result[offset] = matrix1[offset] + matrix2[offset];
        }
    }
}

template <typename T>
void printMatrix(const T* matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            printf("%6.2f ", static_cast<double>(matrix[i * cols + j]));
        }
        printf("\n");
    }
}

int main() {
    const size_t rows = 2;
    const size_t cols = 3;
    
    double mat1[rows][cols] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}};
    double mat2[rows][cols] = {{0.1, 0.2, 0.3}, {0.4, 0.5, 0.6}};
    double result[rows][cols];
    
    addMatrices(&mat1[0][0], &mat2[0][0], &result[0][0], rows, cols);
    
    printf("Matrix 1:\n");
    printMatrix(&mat1[0][0], rows, cols);
    
    printf("\nMatrix 2:\n");
    printMatrix(&mat2[0][0], rows, cols);
    
    printf("\nResult:\n");
    printMatrix(&result[0][0], rows, cols);
    
    return 0;
}
