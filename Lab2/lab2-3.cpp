#include <iostream>

using namespace std;

int main(){
  	int numbers[5];  //numbers гэсэн массив зарлаж байна.
  	int * p; //p гэсэн хаяган хувьсагч зарлаж байна.
  	p = numbers; //p-д numbers массивын хаягийг оноож байна.  
	*p = 10; //p-д байгаа хаяган дээрх утгыг 10 болгож байна.
  	p++;  //p  хаяган хувьсагчийн утгыг нэгээр нэмэгдүүлж байна. 
	*p = 20; //p-д байгаа хаяган дээрх утгыг 20 болгож байна.
  	p = &numbers[2];  
	*p = 30;
  	p = numbers + 3;  
	*p = 40;
  	p = numbers;  
	*(p+4) = 50;
  	for (int n=0; n<5; n++)
		cout << numbers[n] << ", ";	
}
