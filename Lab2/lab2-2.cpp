#include<iostream>

using namespace std;

int main(){
	int a=125; //a хувьсагчид 125 гэсэн утгыг оноож байна.
	int *p = &a; //p хаяган хувьсагчид а хувьсагчийн хаягийг оноож байна.
	cout<<p<<"\n"; //p-д байгаа а хувьсагчийн хаяг бүхий p хувьсагчийг хэвлэж байна.
	cout<<*p<<"\n"; //p хаяган хувьсагчид байгаа хаяг дээрх утгыг хэвлэж байна.
	p++; //p хаяган хувьсагчийн утгыг нэгээр нэмэгдүүлж байна.
	cout<<p<<"\n"; //p-д байгаа утгыг хэвлэж байна.
	cout<<*p<<"\n"; //p-д байгаа хаяг дээрх утгыг хэвлэж байна.
}
