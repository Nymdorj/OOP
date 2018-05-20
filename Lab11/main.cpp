#include <iostream>
#include "matrix.h"

using namespace std;

int main(){
    Matrix A,B,C;
    A.read();
    B.read();
    C = A*B;
    cout << endl << "A: "<< endl;
    A.print();
    cout << endl;
    cout << "B: "<< endl;
    B.print();
    cout << endl;
    cout << "C = A*B: "<< endl;
    C.print(); 
    cout << endl;
    C,C;
    cout << "C,: "<< endl;
    C.print();
    cout << endl;
    cout << "++C: "<< endl;
    ++C;
    C.print();
    cout << endl;
    cout << "--C: "<< endl;
    --C;
    C.print();
    cout << endl;
    cout << "C = A+B: "<< endl;
    C = A+B;
    C.print();
    cout << endl;
    cout << "C = A-B: "<< endl;
    C = A-B;
    C.print();
    cout << endl;
    cout << "C += B: "<< endl;
    C += B;
    C.print();
    cout<<endl;
    cout << "C -= B: "<< endl;
    C -= B;
    C.print();
    cout<<endl;
    cout << "C *= B: "<< endl;
    C *= B;
    C.print();
}
