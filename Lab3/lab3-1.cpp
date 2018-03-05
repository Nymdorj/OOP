#include <iostream>
#include <string.h>

using namespace std;

class Employee{
	private:
		int sequence;
		char name[20];
		char job[10];
		float worked_hours;
	public:
		void set_first_values();
		void get_values(int sequence, char name[20], char job[10], float worked_hours);
		void show();
		char* get_name();
		char* get_job();
		float calculate_salary();
		float ceo_salary();
		bool add_work_hour(float hour);
};

void Employee::set_first_values(){
	this->sequence = 0;
	strcpy(this->name, "");
	strcpy(this->job, "Ajilchin");
	this->worked_hours = 0;
}

void Employee::get_values(int sequence, char name[], char job[], float worked_hours){
	this->sequence = sequence;
	strcpy(this->name, name);
	strcpy(this->job, job);
	this->worked_hours = worked_hours;
}

char* Employee::get_name(){
	return name;
}

char* Employee::get_job(){
	return job;
}

float Employee::calculate_salary(){
	if(strcmp(this->job, "Zahiral") == 0){
		return this->worked_hours * 3000 + this->ceo_salary();
	}else{
		return this->worked_hours * 3000;
	}
}

float Employee::ceo_salary(){
	return 150000;
}

bool Employee::add_work_hour(float hour){
	if(hour>0 && hour<24){
		this->worked_hours = this->worked_hours + hour;
		return 1;
	}else{
		return 0;
	}
}

void Employee::show(){
	cout<<"***************** \nДугаар: "<<sequence<<"\n"<<"Нэр: "<<name<<"\n"<<"Албан тушаал: "<<job<<"\n"
	<<"Ажилласан цаг: "<<worked_hours<<"\n"<<"*****************"<<"\n";
}

int main(){
	int boolean, seq, k, p = 1;
	char ner[20];
	char tushaal[10];
	float worked_hour;
	float hour;
	Employee emp;

	while(1){	
		cout<<"_________________ \n1. Ажилчин бүртгэх \n";
		cout<<"2. Цалин харах \n";
		cout<<"3. Ажилласан цагийг нэмэх \n";
		cout<<"4. Ажилчиний мэдээлэл харах \n";
		cout<<"5. Гарах \n_________________ \n";
		cin>>k;
		switch(k){
			case 1:
				cout<<"Дугаар оруулна уу: ";
				cin>>seq;
				cout<<"Нэрийг оруулна уу: ";
				cin>>ner;
				cout<<"Албан тушаалыг оруулна уу: ";
				cin>>tushaal;
				cout<<"Ажилласан цагийг оруулна уу: ";
				cin>>worked_hour;
				emp.get_values(seq, ner, tushaal, worked_hour);
				break;
			case 2:
				cout<<"Ажилчиний нэр: "<<emp.get_name()<<"\n"<<"Албан тушаал: "<<emp.get_job()<<"\n"<<"Цалин: "<<emp.calculate_salary()<<"\n";
				break;
			case 3:
				cout<<"Хэдэн цаг нэмэх вэ? ";
				cin>>hour;
				boolean = emp.add_work_hour(hour);
				if(boolean = 1){
					cout<<"Ажилттай боллоо!!!!!"<<"\n";
				}else{
					cout<<"Ажилтгүй боллоо!!!!!\n";
				}
				break;
			case 4:
				emp.show();
				break;
			case 5:
				return 0;
				break;
		}
	}
	return 0;
}
