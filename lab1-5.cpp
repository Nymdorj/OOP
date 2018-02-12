#include<iostream>

using namespace std;

inline int natural(int number){
	int count = 0, a[100];
	while(number > 0){
		a[count] = number % 10;
		count++;
		number /= 10;
	}
	cout<<"Натурал тооны оронгийн тоо: "<<count<<"\n";
	cout<<"Натурал тооны цифрүүд: "<<"\n";
	for(int i = count-1; i >= 0; i--){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	int number;
	cout<<"Натурал тоо оруулна уу: ";
	cin>>number;
	natural(number);
	return 0;
}
