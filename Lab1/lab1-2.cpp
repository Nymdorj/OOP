#include<iostream>

using namespace std;

int main(){
	int numbers[100], max, min, n;
	cout<<"Хэдэн тоо оруулах вэ: ";
	cin>>n;
	for(int i = 1; i <= n; i++){
		cout<<i<<"-р тоог оруулна уу: ";
		cin>>numbers[i];
	}
	max = numbers[1];
	min = numbers[1];
	for(int i = 2; i <=n; i++){
		if(max < numbers[i]){
			max = numbers[i];
		}
		if(min > numbers[i]){
			min = numbers[i];
		}	
	}
	cout<<"Хамгийн их тоо: "<<max<<"\n";
	cout<<"Хамгийн бага тоо: "<<min<<"\n";
	return 0;
}
