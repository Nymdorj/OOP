#include<iostream>

using namespace std;

void swap(int *p, int *k){
	int t;
	t = *p;
	*p = *k;
	*k = t;
}

int main(){
	int a, b;
	cout<<"A тооны утгыг оруулна уу: "<<"\n";
	cin>>a;
	cout<<"B тооны утгыг оруулна уу: "<<"\n";
	cin>>b;
	cout<<"Утгыг солихоос өмнө: \n"<<"A: "<<a<<"\n"<<"B: "<<b<<"\n";
	swap(&a,&b);
	cout<<"Утгыг солисоны дараа: \n"<<"A: "<<a<<"\n"<<"B: "<<b<<"\n";
	return 0;
}
