#include "matrix.h"

int main() {
    std::cout << "Enter 'n':" << std::endl;
    int n;
    std::cin >> n;
    while(!std::cin) {
        std::cout << "Error, please, try again" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin >> n;
    }
    Matrix::Matrix matrix = Matrix::createMatrix(n);

    std::cout << "Enter 'i', 'j', 'a_ij'(enter '.' to stop):" << std::endl;
    int i, j;
    float num;

    while (true) {
        std::cin.clear();
        std::string str = " ";
        std::getline(std::cin, str);
        std::istringstream stream = std::istringstream(str);
        stream >> i >> j >> num;
        if(!stream) {
            if (str == ".") {
                break;
            }
            if (!str.empty()) {
            std::cout << "Error, please, try again" << std::endl;
            }
            continue;
        }
        Matrix::addElement(matrix, i, j, num);
    }
    Matrix::printMatrix(matrix);

    auto *vector = new float[matrix.size];

    for (int I = 0; I < matrix.size; ++I) {
        float sum = 0;
        for (int J = 0; J < matrix.size; ++J) {
            sum += Matrix::number_at(matrix, I, J) * Matrix::number_at(matrix, J, Matrix::maxElement(matrix, J));
        }
        vector[I] = sum;
    }

    for (int k = 0; k < matrix.size; ++k) {
        std::cout << vector[k] << std::endl;
    }

    delete[] vector;
    Matrix::deleteMatrix(matrix);

    return 0;
}
