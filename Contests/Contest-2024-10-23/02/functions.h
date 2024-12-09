#pragma once


int** new_matrix(int rows, int cols, int value) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value;
        }
    }
    return matrix;
}

std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows, int ccols) {
    int new_rows = mrows - crows + 1;
    int new_cols = mcols - ccols + 1;
    int** res = new_matrix(new_rows, new_cols);

    // Move core start pos
    for (int y1 = 0; y1 < new_rows; y1++) {
        for (int x1 = 0; x1 < new_cols; x1++) {
            int cur_sum = 0;
            // Move inside current core place
            for (int y2 = 0; y2 < crows; y2++) {
                for (int x2 = 0; x2 < ccols; x2++) {
                    cur_sum += matrix[y1 + y2][x1 + x2] * core[y2][x2];
                }
            }
            res[y1][x1] = cur_sum;
        }
    }
    return std::make_tuple(res, new_rows, new_cols);
}

std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols) {
    int new_rows = arows;
    int new_cols = bcols;
    int **res = new_matrix(new_rows, new_cols);

    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            for (int k = 0; k < brows; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return std::make_tuple(res, new_rows, new_cols);
}

std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value) {
    int** res = new_matrix(rows + 1, cols, value);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = (*matrix)[i][j];
        }
    }
    delete_matrix(matrix, rows);
    *matrix = res;
    return std::make_tuple(rows + 1, cols);
}

std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value) {
    int** res = new_matrix(rows, cols + 1, value);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = (*matrix)[i][j];
        }
    }
    delete_matrix(matrix, rows);
    *matrix = res;
    return std::make_tuple(rows, cols + 1);
}

void delete_matrix(int*** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] (*matrix)[i];
    }
    delete[] *matrix;
    *matrix = nullptr;
}

void print(int** matrix, int rows, int cols) {
    std::cout << "\n\n";
    for(int i=0; i < rows; i++) {
        for(int j=0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
