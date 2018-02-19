#include<iostream>

using namespace std;

inline int checkNumbers(int a[], int n){
	int count = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] % 2 == 0){
			count++;
		}
	}
	return count; 
}

int main(){
	int numbers[100], max, min, n;
	cout<<"Хэдэн тоо оруулах вэ: ";
	cin>>n;
	for(int i = 1; i <= n; i++){
		cout<<i<<"-р тоог оруулна уу: ";
		cin>>numbers[i];
	}
	cout<<"Нийт тэгш элементийн тоо: "<<checkNumbers(numbers, n)<<"\n";
	return 0;
}
