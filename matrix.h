#pragma once
#ifndef matrix_H
#define matrix_H

#include <iostream>

class matrix {
private:
	int** data; //двумерный массив
	unsigned int m;
	unsigned int n;

public:
	matrix(unsigned int rows, unsigned int colum); //конструктор
	~matrix(); //деструктор

	int* operator[](unsigned int i); //оператор доступа по индексу 
	void fillRandom(); //заполнение массива случайными значениями

	matrix operator+(const matrix& other);
	matrix operator-(const matrix& other);
	matrix operator*(const matrix& other);
	matrix& operator+=(const matrix& other);
	matrix& operator-=(const matrix& other);
	bool operator==(const matrix& other);
	bool operator!=(const matrix& other);

	friend std::ostream& operator<<(std::ostream& out, const matrix& matrix);
};

#endif