// Function to read matrix data from a file
void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int &size, const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file >> size; // Read matrix size
    if (size <= 0 || size > MAX_SIZE) {
        std::cerr << "Invalid matrix size." << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (!(file >> matrix[i][j])) {
                std::cerr << "Error reading matrix element at position (" << i << ", " << j << ")" << std::endl;
                return;
            }
        }
    }

    file.close();
}