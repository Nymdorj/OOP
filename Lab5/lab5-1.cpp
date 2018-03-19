#include <iostream>
#include <string.h>

using namespace std;

class Employee{
	private:
		int sequence;
		char *name;
		char *job;
		float worked_hours;
		float ceo_salary();
	public:
		Employee();
		Employee(int sequence, char *name, char *job, float worked_hours);
		~Employee();
		void set_first_values();
		void set_values(int sequence, char *name, char *job, float worked_hours);
		void show();
		char* get_name();
                void set_name(char n[]);
                int get_sequence();
                void set_sequence(int n);
		char* get_job();
                void set_job(char n[]);
		float calculate_salary();
		bool add_work_hour(float hour);
                float get_worked_hours();
                void set_worked_hours(float n);
		void empcopy(Employee &);
		void sortSalary(Employee e[], int n);
		void sortName(Employee e[], int n);
		bool checkSeq(Employee e[], int n, int seq);
		bool after(Employee &);
};

Employee::Employee(){
	this->sequence = -1;
	this->name = new char[20];
	this->job = new char[10];
	this->worked_hours = 0;
}

Employee::Employee(int seq, char *name, char *job, float hour){
	this->sequence = seq;
	this->worked_hours = hour;
	this->name = new char[strlen(name) + 1];
	this->job = new char[strlen(job) + 1];
	strcpy(this->name, name);
	strcpy(this->job, job);
}

Employee::~Employee(){
	delete[] this->name;
	delete[] this->job;
}

bool Employee::after(Employee &e){
	if(strcmp(name, e.get_name()) > 0)
		return true;
	else
		return false;
}

float Employee::get_worked_hours(){
	return this->worked_hours;
}

void Employee::set_worked_hours(float n){
	this ->sequence=n;
}

int Employee::get_sequence(){
	return this->sequence;
}

void Employee::set_sequence(int n){
	this ->sequence=n;
}

void Employee::set_name(char n[]){
	strcpy(this->name, n);
}

void Employee::set_job(char n[]){
	strcpy(this->job, n);
}

void Employee::set_first_values(){
	this->sequence = 0;
	strcpy(this->name, "");
	strcpy(this->job, "Ajilchin");
	this->worked_hours = 0;
}

void Employee::set_values(int sequence, char *name, char *job, float worked_hours){
	this->sequence = sequence;
	if(this->name != NULL){
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	if(this->job != NULL){
		delete[] this->job;
		this->job = new char[strlen(job) + 1];
		strcpy(this->job, job);
	}
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

void Employee::empcopy(Employee &e){
	strcpy(name, e.get_name());
	strcpy(job, e.get_job());
	worked_hours = e.get_worked_hours();
	sequence = e.get_sequence();
}

void Employee::show(){
	cout<<"***************** \nДугаар: "<<sequence<<"\n"<<"Нэр: "<<name<<"\n"<<"Албан тушаал: "<<job<<"\n"
	<<"Ажилласан цаг: "<<worked_hours<<"\n"<<"*****************"<<"\n";
}

void sortSalary(Employee e[], int n){
	for(int i = 1; i < n; i++){
		for(int k = i + 1; k < n; k++){
			if(e[i].calculate_salary() < e[k].calculate_salary()){
				Employee temp;
				temp.empcopy(e[i]);
				e[i].empcopy(e[k]);
				e[k].empcopy(temp);
			}
		}
	}
}

void sortName(Employee e[], int n){
	for(int i = 1; i < n; i++){
		for(int k = i + 1; k < n; k++){
			if(e[i].after(e[k])){
				Employee temp;
				temp.empcopy(e[i]);
				e[i].empcopy(e[k]);
				e[k].empcopy(temp);
			}
		}
	}
}

bool Employee::checkSeq(Employee e[], int n, int seq){
	for(int i = 1; i <= n; i++){
		if(e[i].get_sequence() == seq){
			return 0;
		}
	}
	return 1;
}

int main(){
	int boolean, n, seq, k, p = 1;
	char ner[20];
	char tushaal[10];
	float worked_hour;
	float hour;
	Employee emp[100];
	while(1){
		cout<<"_________________ \n1. Ажилчин бүртгэх \n";
		cout<<"2. Цалин харах \n";
		cout<<"3. Ажилласан цагийг нэмэх \n";
		cout<<"4. Ажилчиний мэдээлэл харах \n";
		cout<<"5. Ажилчидийг цалингаар нь эрэмбэлэх \n";
		cout<<"6. Ажилчидийг нэрээр нь эрэмбэлэх \n";
		cout<<"7. Бүх ажилчидийн мэдээллийг харах \n";
		cout<<"8. Гарах \n_________________ \n";
		cin>>k;
		switch(k){
			case 1:
				cout<<"Дугаар оруулна уу: ";
				cin>>seq;
				if(emp[p].checkSeq(emp, p, seq) == 1){
					cout<<"Нэрийг оруулна уу: ";
					cin>>ner;
					cout<<"Албан тушаалыг оруулна уу: ";
					cin>>tushaal;
					cout<<"Ажилласан цагийг оруулна уу: ";
					cin>>worked_hour;
					emp[p].set_values(seq, ner, tushaal, worked_hour);
					p++;
				}else{
					cout<<"\n ++++++Дугаар давтагдахгүй байх ёстой++++++\n";
				}
				break;
			case 2:
				cout<<"Хэд дэхь ажилчиний мэдээллийг харах вэ: "<<"\n";
				cin>>k;
				cout<<"Ажилчиний нэр: "<<emp[k].get_name()<<"\n"<<"Албан тушаал: "<<emp[k].get_job()<<"\n"<<"Цалин: "<<emp[k].calculate_salary()<<"\n";
				break;
			case 3:
				cout<<"Хэд дэхь ажилчиний цагийг нэмэх вэ: "<<"\n";
				cin>>k;
				cout<<"Хэдэн цаг нэмэх вэ? ";
				cin>>hour;
				boolean = emp[k].add_work_hour(hour);
				if(boolean = 1){
					cout<<"Ажилттай боллоо!!!!!"<<"\n";
				}else{
					cout<<"Ажилтгүй боллоо!!!!!\n";
				}
				break;
			case 4:
				cout<<"Ажилчиний дугаарыг оруулна уу: "<<"\n";
				cin>>k;
				emp[k].show();
				break;
			case 5:
				sortSalary(emp, p);
				break;
			case 6:
				sortName(emp, p);
				break;
			case 7:
				for(int i = 1; i < p; i++){
					cout<<"---------- \nДугаар: "<<emp[i].get_sequence()<<"\n"<<"Нэр: "<<emp[i].get_name()<<"\n"<<
					"Цалин: "<<emp[i].calculate_salary()<<"\n---------- \n";
				}	
				break;
			case 8:
				return 0;
				break;
		}
	}
	return 0;
}
