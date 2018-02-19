#include<iostream>

using namespace std;

inline int arefmatic(int a[], int n){
	int count = 0, result = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] % 2 != 0){
			result += a[i];
			count++;
		}
	}
	if(count != 0){
		return result / count;
	}else{
		return 0;
	} 
}

int main(){
	int numbers[100], max, min, n;
	cout<<"Хэдэн тоо оруулах вэ: ";
	cin>>n;
	for(int i = 1; i <= n; i++){
		cout<<i<<"-р тоог оруулна уу: ";
		cin>>numbers[i];
	}
	cout<<"Нийт сондгой элементийн арифматик дундаж: "<<arefmatic(numbers, n)<<"\n";
	return 0;
}
