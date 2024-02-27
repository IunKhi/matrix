#include <iostream>
#include <cstdlib>
#include <ctime>

class matrix {
private:
    int** data; // двумерный массив
    unsigned int m; // количество строк
    unsigned int n; // количество столбцов

public:
    // Конструктор
    matrix(unsigned int m, unsigned int n) : m(m), n(n) {
        data = new int* [m];
        for (unsigned int i = 0; i < m; ++i) {
            data[i] = new int[n];
        }
    }

    // Деструктор
    ~matrix() {
        for (unsigned int i = 0; i < m; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Перегрузка оператора [] для доступа по индексу
    int* operator[](unsigned int index) const {
        return data[index];
    }

    // Метод для заполнения массива случайными значениями от 0 до 9
    void fillRandom() {
        srand(time(nullptr));
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = rand() % 10;
            }
        }
    }

    // Перегрузка оператора вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const matrix& mat) {
        for (unsigned int i = 0; i < mat.m; ++i) {
            for (unsigned int j = 0; j < mat.n; ++j) {
                os << mat.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    // Перегрузка операторов +=, +, -=, -, *
    matrix& operator+=(const matrix& other) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    matrix operator+(const matrix& other) const {
        matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    matrix& operator-=(const matrix& other) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    matrix operator-(const matrix& other) const {
        matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    matrix operator*(const matrix& other) const {
        matrix result(m, other.n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < other.n; ++j) {
                result.data[i][j] = 0;
                for (unsigned int k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Перегрузка операторов != и ==
    bool operator!=(const matrix& other) const {
        if (m != other.m || n != other.n) {
            return true;
        }
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator==(const matrix& other) const {
        return !(*this != other);
    }
};
int main() {
    matrix mat1(3, 3);
    matrix mat2(3, 3);
    mat1.fillRandom();
    mat2.fillRandom();

    std::cout << "Matrix 1:" << std::endl << mat1 << std::endl;
    std::cout << "Matrix 2:" << std::endl << mat2 << std::endl;

    matrix mat3 = mat1 + mat2;
    std::cout << "Sum of matrices:" << std::endl << mat3 << std::endl;

    matrix mat4 = mat1 * mat2;
    std::cout << "Product of matrices:" << std::endl << mat4 << std::endl;

    if (mat1 != mat2) {
        std::cout << "Matrices are not equal" << std::endl;
    }
    else {
        std::cout << "Matrices are equal" << std::endl;
    }

    return 0;
}