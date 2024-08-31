#ifndef LAB1_H
#define LAB1_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <stdio.h>

using namespace std;

void ex1();
void add(FILE*, char*);
void show1(FILE*, char*);
void show_all(FILE*, char*);
void delete_all(FILE*, char*);
void zamenaMinMax(FILE*, char*);
void zamena_strok(FILE*, char*);
void seek(FILE*, int);

class Matrix {
public:
	double** arr;
	int size1;
	int size2;
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix& ob);
	~Matrix();
	void setValues();
	void showMatrix();
	void MinMax();
	void perestanovka();
};

void zapis(FILE*, Matrix&);
void chtenie(FILE*, Matrix&);

#endif