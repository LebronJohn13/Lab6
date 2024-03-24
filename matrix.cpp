#include <iostream> // For std::cout, std::cerr
#include <fstream> // For std::ifstream
#include <sstream> // For std::istringstream
#include <string> // For std::string
#include <vector> // For std::vector

const int MAX_SIZE = 10; // Maximum size of the matrix

// Add two matrices and store the result in 'result'
void addMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::vector<std::vector<int>>& result) {
    int size = matrix1.size();
    // Initialize result matrix with zeros
    result.assign(size, std::vector<int>(size, 0));

    // Add corresponding elements from both matrices
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Multiply two matrices and store the result in 'result'
void multiplyMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::vector<std::vector<int>>& result) {
    int size = matrix1.size();
    // Initialize result matrix with zeros
    result.assign(size, std::vector<int>(size, 0));

    // Perform matrix multiplication
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Find the maximum value in a matrix
int findMaxValueInMatrix(const std::vector<std::vector<int>>& matrix) {
    int maxVal = std::numeric_limits<int>::min();
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val > maxVal) {
                maxVal = val;
            }
        }
    }
    return maxVal;
}

// Subtract two matrices and store the result in 'result'
void subtractMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::vector<std::vector<int>>& result) {
    int size = matrix1.size();
    // Initialize result matrix with zeros
    result.assign(size, std::vector<int>(size, 0));

    // Subtract corresponding elements of matrix2 from matrix1
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Transpose a matrix and print the result
void transposeAndPrintMatrix(const std::vector<std::vector<int>>& matrix) {
    int size = matrix.size();
    std::vector<std::vector<int>> transposedMatrix(size, std::vector<int>(size));

    // Transpose the matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    // Print the transposed matrix
    std::cout << "Transposed Matrix:" << std::endl;
    for (const auto& row : transposedMatrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Update an element in the matrix at the specified row and column with the new value
void updateMatrixElement(std::vector<std::vector<int>>& matrix, int row, int col, int newValue) {
    int size = matrix.size();
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Invalid row or column." << std::endl;
    }
}

// Read two matrices from a file and store them in 'matrix1' and 'matrix2'
void readMatrices(const std::string& filename, int matrixSize, std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    int row = 0;
    int matrixCount = 0;
    std::vector<std::vector<int>> currentMatrix(matrixSize, std::vector<int>(matrixSize));
    while (std::getline(file, line) && matrixCount < 2) {
        std::istringstream iss(line);
        int val;
        int col = 0;
        while (iss >> val && col < matrixSize) {
            currentMatrix[row][col] = val;
            col++;
        }
        row++;
        if (row == matrixSize) {
            if (matrixCount == 0) {
                matrix1 = currentMatrix;
            } else {
                matrix2 = currentMatrix;
            }
            row = 0;
            matrixCount++;
        }
    }

    file.close();
}

// Print a matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int matrixSize = 3; // Size of each matrix
    std::vector<std::vector<int>> matrix1(matrixSize, std::vector<int>(matrixSize));
    std::vector<std::vector<int>> matrix2(matrixSize, std::vector<int>(matrixSize));

    // Read matrices from file
    readMatrices("matrix_input.txt", matrixSize, matrix1, matrix2);

    //Print the matrices
    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1);
    std::cout << "\nMatrix 2:" << std::endl;
    printMatrix(matrix2);

        std::vector<std::vector<int>> additionResult(matrixSize, std::vector<int>(matrixSize));
    addMatrices(matrix1, matrix2, additionResult);

    std::cout << "\nResult of Matrix Addition:" << std::endl;
    for (const auto& row : additionResult) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> multiplicationResult(matrixSize, std::vector<int>(matrixSize));
    multiplyMatrices(matrix1, matrix2, multiplicationResult);

    std::cout << "\nResult of Matrix Multiplication:" << std::endl;
    for (const auto& row : multiplicationResult) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> subtractionResult(matrixSize, std::vector<int>(matrixSize));
    subtractMatrices(matrix1, matrix2, subtractionResult);

    std::cout << "\nResult of Matrix Subtraction (Matrix 1 - Matrix 2):" << std::endl;
    for (const auto& row : subtractionResult) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Example of updating an element
    int rowToUpdate = 0;
    int colToUpdate = 0;
    int newValue = 72;
    updateMatrixElement(matrix1, rowToUpdate, colToUpdate, newValue);

    std::cout << "\nMatrix 1 after updating element at row " << rowToUpdate << ", column " << colToUpdate << " with value " << newValue << ":" << std::endl;
    printMatrix(matrix1);


    int maxValueMatrix1 = findMaxValueInMatrix(matrix1);
    std::cout << "\nMax value in Matrix 1: " << maxValueMatrix1 << std::endl;

    transposeAndPrintMatrix(matrix1);

    return 0;
}
