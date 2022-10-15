#pragma once
#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

class Matrix {

	int row, col;
	int** matrix;

public:
	Matrix(int r = 5, int c = 5);
	~Matrix();
	Matrix(const Matrix& other);
	int getrownumber()const {
		return row;
	}
	int getcolnumber()const {
		return col;
	}
	void setValue(int r, int c, int value);
	void Randomset();
	void identityMatrixset();
	void display();
	Matrix addmatrix(const Matrix& other);

};

Matrix::Matrix(int r, int c) {

	if (r >= 0 && col >= 0) {
		row = r;
		col = c;
	}
	else {
		row = 5;
		col = 5;
	}

	matrix = new int* [row];

	for (int i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < row; i++) {
		delete[]matrix[i];
	}
	delete[]matrix;
}

Matrix::Matrix(const Matrix& other) {
	row = other.row;
	col = other.col;
	
	matrix = new int* [row];

	for (int i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

void Matrix::setValue(int r, int c, int value) {

	matrix[r][c] = value;
}

void Matrix::display() {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Matrix::Randomset() {

	srand(time(NULL));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
}

void Matrix::identityMatrixset() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == j) {
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}
}

Matrix Matrix::addmatrix(const Matrix& other) {

	if (row != other.row || col != other.col) {
		cout << "Satir sutun sayisi esit olmalidir" << endl;
	}
	
	else {
		Matrix result(row, col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
			}
		}
		return result;

	}

}