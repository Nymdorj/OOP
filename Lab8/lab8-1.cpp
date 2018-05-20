#include<iostream>
#include<string.h>
#include<vector>
#include "Student.h"
#include "Teacher.h"
#include "Lesson.h"
#include "Registration.h"

using namespace std;

int main(){
	int n, att;
	char today[40], state[20];
	vector<Registration> regist;
	Student *student = new Student((char *)"14b1seas2285", (char *)"Nyamdorj"); 
	Student *student1 = new Student((char *)"14b1seas1011", (char *)"Suh"); 
	Student *student2 = new Student((char *)"14b1seas2130", (char *)"Dorj"); 
	Student *student3 = new Student((char *)"14b1seas2425", (char *)"Bayar"); 

	Teacher *teacher = new Teacher((char *)"Bagsh");

	Lesson *lesson = new Lesson(1, (char *)"Sedev", *teacher, *student);
	lesson->setStudent(*student1);
	lesson->setStudent(*student2);
	lesson->setStudent(*student3);
	lesson->show();
	
	while(1){
		cout<<"1: Бүртгэх"<<"\n";
		cout<<"2: Ирц харах"<<"\n";
		cout<<"3: Гарах"<<"\n";
		cin>>n;
		switch(n){
			case 1:	
				cout<<"Он сар өдөр оруулна уу?"<<"\n";
				cin>>today;
				for(int i=0; i<lesson->getStudent().size(); i++){ 			
					cout<<lesson->getStudent()[i].getName()<<"\n";
					cout<<"1: Ирсэн"<<"\n";
					cout<<"2: Ирээгүй"<<"\n";
					cin>>att;
					switch(att){
						case 1:
							strcpy(state,"Ирсэн");
							break;
						case 2:
							strcpy(state,"Ирээгүй");
							break;
					}
					Registration *reg = new Registration(*lesson, lesson->getStudent()[i], (char*)today, (char*)state);
					regist.push_back(*reg);
				}
				break;
			case 2:
				for(Registration r : regist) r.show();
				break;
			case 3:
				return 0;
				break;
		}
	}
}
