//
// Created by santas_molderras on 07.09.22.
//

#include "matrix.h"

Matrix::Matrix Matrix::createMatrix(int size) {
    Matrix matrix = {};
    matrix.size = size;
    matrix.capacity = size * 2;
    matrix.elements = new Element[matrix.capacity];
    matrix.raw_start_indices = new int[size];
    for (int i = 0; i < size; ++i) {
        matrix.raw_start_indices[i] = -1;
    }

    return matrix;
}

void Matrix::deleteMatrix(Matrix& matrix) {
    delete[] matrix.elements;
    delete[] matrix.raw_start_indices;
}

int Matrix::findPlace(Matrix& matrix, int i, int j) {

    int k = matrix.raw_start_indices[i];
    if (k == -1) {
        k = 0;
    }
//    for (; k < matrix.current_size && matrix.elements[k].i <= i; ++k) {
//        if(matrix.elements[k].j == j && matrix.elements[k].i == i) {
//            return k;
//        }
//    }

//    while (matrix.elements[k].i < i && matrix.elements[k].j < j && k < matrix.current_size) {
//        k++;
//    }
    while (k < matrix.current_size && matrix.elements[k].i < i) {
        k++;
    }
    return k;
}

Matrix::Element *Matrix::findElement(Matrix& matrix, int i, int j) {
    int k = findPlace(matrix, i, j);

    if (k >= matrix.current_size || k == -1 || matrix.elements[k].i != i || matrix.elements[k].j != j) {
        return nullptr;
    }
    return &(matrix.elements[k]);

}

void Matrix::addElement(Matrix& matrix, int i, int j, float num) {

    if ( i >= matrix.size || j >= matrix.size || i < 0 || j < 0) {
        return;
    }

    Element *element = findElement(matrix, i, j);

    if (element) {
        element->num = num;
        return;
    }

    Element newElement{i, j, num};

    int place = findPlace(matrix, i, j);

    for (int k = matrix.current_size; place < k; --k) {
        matrix.elements[k] = matrix.elements[k - 1];
    }
    matrix.elements[place] = newElement;
    matrix.current_size++;

    if (matrix.raw_start_indices[i] == -1) {
        matrix.raw_start_indices[i] = place;
    }

    for (int k = i + 1; k < matrix.size; ++k) {
        if (matrix.raw_start_indices[k] != -1) {
            matrix.raw_start_indices[k]++;
        }
    }
}

void Matrix::printMatrix(Matrix& matrix) {
    std::cout << std::setw(6) << "i" << std::setw(6) << "j" << std::setw(6) << "a_ij" << std::endl;
    for (int i = 0; i < matrix.current_size; ++i) {
        std::cout << std::setw(6) << matrix.elements[i].i << std::setw(6) << matrix.elements[i].j << std::setw(6) << matrix.elements[i].num << std::endl;
    }
}

float Matrix::number_at(Matrix& matrix, int i, int j) {
    int k = matrix.raw_start_indices[i];
    if (k == -1) {
        return 0;
    }
    for (; k < matrix.current_size && matrix.elements[k].i == i; ++k) {
        if(matrix.elements[k].j == j) {
            return matrix.elements[k].num;
        }
    }
    return 0;
}

int Matrix::maxElement(Matrix &matrix, int i) {
    float max_elem = 0;
    float cur;
    int index = 0;
    for (int j = 0; j < matrix.size; ++j) {
        cur = number_at(matrix, i, j);
        if (max_elem < cur) {
            max_elem = cur;
            index = j;
        }
    }
    return index;
}