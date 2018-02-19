#include<iostream>
#define max(a, b, c) (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c)

using namespace std;

int main(){
	int a,b,c; 
	cout<<"А тоог оруулна уу: ";	
	cin >> a;
	cout<<"B тоог оруулна уу: ";	
	cin >> b;
	cout<<"C тоог оруулна уу: ";	
	cin >> c;
	int result = max(a,b,c);
	cout<<"A, B, C тоонуудын хамгийн их тоо нь: "<<result<<"\n";
	return 0;
}
