#include "student.h"
#include "iostream"

using namespace std;

void sortName(Student s[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(s[i].after(s[j])){
                Student temp((char *)" ", (char *)" ", 1, 0);
		temp.stdcopy(s[i]);
                s[i].stdcopy(s[j]);
                s[j].stdcopy(temp);
            }
        }
    }
}

void sortKurs(Student s[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(s[i].greatThan(s[j])){
                Student temp((char *)" ", (char *)" ", 1, 0);
		temp.stdcopy(s[i]);
                s[i].stdcopy(s[j]);
                s[j].stdcopy(temp);
            }
            else if(s[i].isEqual(s[j])){
                if(s[i].after(s[j])){
                    Student temp((char *)" ", (char *)" ", 1, 0);
		    temp.stdcopy(s[i]);
                    s[i].stdcopy(s[j]);
                    s[j].stdcopy(temp);
                }
            }
        }
    }
}

int main(){
	Student *s = new Student[9];
	new (s) Student((char *)"16b1seas2285", (char *)"Galaa", 4, 3.5);
	new (s+1) Student((char *)"15b1seas1202", (char *)"Bat", 3, 3.4);
	new (s+2) Student((char *)"14b1seas5090", (char *)"Barca", 4, 3.3);
	new (s+3) Student((char *)"14b1seas2312", (char *)"Wade", 1, 2.8);
	new (s+4) Student((char *)"12b1seas3480", (char *)"Dolgoon", 2, 3.0);
	new (s+5) Student((char *)"14b1seas4123", (char *)"Pool", 4, 3.5);
	new (s+6) Student((char *)"14b1seas2456", (char *)"Liver", 3, 2.9);
	new (s+7) Student((char *)"14b1seas2789", (char *)"Lone", 1, 2.8);
	new (s+8) Student((char *)"15b1seas3645", (char *)"Saraa", 2, 3.0);
	
	cout<<"#"<<"\t"<<"Нэр"<<"\t"<<"Дугаар"<<"\t\t"<<"Курс"<<"\t"<<endl;
	for(int i=0; i<9; i++){
        	cout << i + 1 << ":\t" << s[i].get_name() << "\t" << s[i].get_id() << "\t" << s[i].get_kurs() << endl;
    	}
	cout<<"Sort Name"<<endl;
	sortName(s,9);
	for(int i=0; i<9; i++){
        	cout << i + 1 << ":\t" << s[i].get_name() << "\t" << s[i].get_id() << "\t" << s[i].get_kurs() << endl;
    	}
	cout<<"Sort Kurs"<<endl;
	sortKurs(s,9);
	for(int i=0; i<9; i++){
		cout<<i+1<<":\t"<<s[i].get_name()<<"\t"<<s[i].get_id()<<"\t"<<s[i].get_kurs()<<endl;
	}
	cout<<"Обьектийн тоо: "<<endl;
	s[0].printNumber();
}
