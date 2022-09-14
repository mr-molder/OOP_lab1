//
// Created by santas_molderras on 07.09.22.
//

#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>

namespace Matrix {

    struct Element {
        int i, j;
        float num;
    };


    struct Matrix {
        int size;
        int capacity;
        int current_size;
        Element *elements;
        int *raw_start_indices;
    };


    Matrix createMatrix(int size);
    void deleteMatrix(Matrix& matrix);

    int findPlace(Matrix& matrix, int i, int j);
    Element *findElement(Matrix& matrix, int i, int j);


    void addElement(Matrix& matrix, int i, int j, float num);

    void printMatrix(Matrix& matrix);

    float number_at(Matrix& matrix, int i, int j);

    int maxElement(Matrix& matrix, int i);

}

#endif //LAB1_MATRIX_H
