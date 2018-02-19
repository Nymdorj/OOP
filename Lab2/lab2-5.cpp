#include<iostream>

using namespace std;

void swap(int &x, int &y){
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int main(){
	int a, b;
	cout<<"A тооны утгыг оруулна уу:";
	cin>>a;
	cout<<"B тооны утгыг оруулна уу:";
	cin>>b;
	cout<<"Утгыг солихоос өмнө: \n"<<"A: "<<a<<"\n"<<"B: "<<b<<"\n";
        swap(a,b);
        cout<<"Утгыг солисоны дараа: \n"<<"A: "<<a<<"\n"<<"B: "<<b<<"\n";
	return 0;
}
