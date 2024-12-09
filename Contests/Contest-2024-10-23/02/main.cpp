#include <iostream>
#include <tuple>

int** new_matrix(int rows, int cols, int value=0);
std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows=3, int ccols=3);
std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols);
std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value=1);
std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value=1);
void delete_matrix(int*** matrix, int rows);
void print(int** matrix, int rows, int cols);

int main(){
    int rows_first, cols_first, first_init_val,
        rows_core, cols_core;
        
    std::cin >> rows_first >> cols_first >> first_init_val;
    int** first = new_matrix(rows_first, cols_first, first_init_val);
    for(int i=0; i < rows_first; i++)
        for(int j=0; j < cols_first; j++)
            std::cin >> first[i][j];

    std::cin >> rows_core >> cols_core;
    int** core = new_matrix(rows_core, cols_core);
    for(int i=0; i < rows_core; i++)
        for(int j=0; j < cols_core; j++)
            std::cin >> core[i][j];
    
    auto [conv, rows_conv, cols_conv] = convolution(first, rows_first, cols_first, core);
    
    std::tie(rows_conv, cols_conv) = add_row(&conv, rows_conv, cols_conv);
    std::tie(rows_conv, cols_conv) = add_col(&conv, rows_conv, cols_conv);
    std::tie(rows_conv, cols_conv) = add_col(&conv, rows_conv, cols_conv);
    
    auto [mult, rows_mult, cols_mult] = multiplication(conv, rows_conv, cols_conv, first, rows_first, cols_first);
    
    print(mult, rows_mult, cols_mult);
    
    delete_matrix(&first, rows_first);
    delete_matrix(&conv, rows_conv);
    delete_matrix(&mult, rows_mult);
}


#include "functions.h"


