#include<iostream>
#include "matrix.h"
using namespace std;

Matrix::Matrix(){
    rowSize = colSize = 100;
    int i, j;
    a = new int*[rowSize];
    for (i = 0; i < rowSize; i++){
        *(a+i) = new int[colSize];
    }

    for (i = 0; i < rowSize; i++){
        for (j = 0; j < colSize; j++){
            a[i][j] = 0;
	}
    }
}

Matrix::Matrix(int rs, int cl){
    rowSize = rs;
    colSize = cl;
    int i, j;
    a = new int*[rowSize];
    for (i = 0; i < rowSize; i++){
        a[i] = new int[colSize];
    }

    for (i = 0; i < rowSize; i++){
        for (j = 0; j < colSize; j++){
            a[i][j] = 0;
	}
    }
}

Matrix::Matrix(const Matrix &M){
    rowSize = M.rowSize;
    colSize = M.colSize;
    int i, j;
    a = new int*[rowSize];
    for(i = 0; i < rowSize; i++){
       a[i] = new int[colSize];
    }

    for (i = 0; i < rowSize; i++){
        for (j = 0; j < colSize; j++){
            a[i][j] = M.a[i][j];
	}
    }
}

Matrix::~Matrix(){
    int i, j;
    for(i = 0; i < rowSize; i++){
            delete[] a[i];
    }
    delete[] a;
}

void Matrix::print() const{
    int i, j;
    for(i = 0; i < rowSize; i++){
        for(j = 0; j < colSize; j++){
            cout << a[i][j] << " " ;
	}
        cout << endl;
    }
}

void Matrix::read(){
    int i, j;
    cout << "Матрицийн уртын оруулна уу: ";
    cin >> colSize;
    cout << "Матрицийн өргөнийг оруулна уу: ";
    cin >> rowSize;
    for(i = 0; i < rowSize; i++){
        for(j = 0; j < colSize; j++){
	    cout << i << ":" << j << "-рх тоог оруулна уу: " << endl;
            cin >> a[i][j];
	}
    }
}

Matrix Matrix::operator +(const Matrix &M){
    int i, j, crow = 0, ccol = 0;
    Matrix C;

    for(i = 0; i < this->rowSize; i++){
       ccol = 0;
       for(j = 0; j < this->colSize; j++){
       		C.a[i][j] = this->a[i][j]+M.a[i][j];
      		ccol++;
       }
       crow++;
    }

    C.rowSize = crow;
    C.colSize = ccol;

    return C;
}

Matrix Matrix::operator +=(const Matrix &M){
    return *this = *this + M;
}

Matrix Matrix::operator -(const Matrix &M){
    int i, j, crow = 0, ccol = 0;
    Matrix C;

    for(i = 0; i < this->rowSize; i++){
       ccol = 0;
       for(j = 0; j < this->colSize; j++){
       		C.a[i][j] = this->a[i][j]-M.a[i][j];
       		ccol++;
       }
       crow++;
    }

    C.rowSize = crow;
    C.colSize = ccol;
    return C;
}

Matrix Matrix::operator -=(const Matrix &M){
    return *this = *this - M;
}

Matrix Matrix::operator ++(){
    int i, j, k, crow = 0, ccol = 0;
    Matrix C;
    for(i = 0; i < this->rowSize; i++){
       ccol = 0;
       for(j = 0; j < this->colSize; j++){
           C.a[i][j] = this->a[i][j]++;
       }
    }
    C.rowSize = this->rowSize;
    C.colSize = this->colSize;

    return C;
}

Matrix Matrix::operator --(){
    int i, j, k, crow = 0, ccol = 0;
    Matrix C;
    for(i = 0; i < this->rowSize; i++){
       ccol = 0;
       for(j = 0; j < this->colSize; j++){
           C.a[i][j] = this->a[i][j]--;
       }
    }
    C.rowSize = this->rowSize;
    C.colSize = this->colSize;

    return C;
}


Matrix Matrix::operator =(const Matrix &M){
    int i, j;
    for(int i = 0; i < rowSize; i++){
	delete[] a[i];
    }

    delete[] a;

    rowSize = M.rowSize;
    colSize = M.colSize;
    a = new int*[rowSize];

    for(i = 0; i < rowSize; i++){
        a[i] = new int[colSize];
    }

    for(i = 0; i < rowSize; i++){
        for(j = 0; j < colSize; j++){
            a[i][j] = M.a[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator *(const Matrix &M){
    int i, j, s, k, crow = 0, ccol = 0;
    Matrix C;

    for(i = 0; i < this->rowSize; i++){
       ccol = 0;
       for(k = 0; k < M.colSize; k++){
            s = 0;
            for(j = 0; j < this->colSize; j++){
               s = s + this->a[i][j]*M.a[j][k];
            }
            C.a[crow][ccol] = s;
            ccol++;
        }
        crow++;
    }

    C.rowSize = crow;
    C.colSize = ccol;

    return C;
}

Matrix Matrix::operator *=(const Matrix &M){
    return *this = *this * M;
}

Matrix Matrix::operator ,(const Matrix &M){
    int i, j, k = 0,  t;
    Matrix c(M);
    for(i = 0; i < rowSize; i++){
        for(j = k; j < colSize; j++){	
           t = c.a[i][j];
           c.a[i][j] = c.a[j][i];
           c.a[j][i] = t;
        }
        k++;
    }
    return *this = c;
}

int Matrix::getRowSize(){
	return this->rowSize;
}

int Matrix::getColSize(){
	return this->colSize;
}

void Matrix::setRowSize(int sz){
	this->rowSize = sz;
}

void Matrix::setColSize(int sz){
	this->colSize = sz;
}

int Matrix::getEl(int x, int y){
	return a[x][y];
}

void Matrix::setEl(int x, int y, int v){
	a[x][y] = v;
}
