#include "student.h"
#include "string.h"
#include "iostream"

using namespace std;

Student::Student(){
	set_id((char *)" ");	
	set_name((char *)" ");	
	set_kurs(1);
	set_gpa(0);
	number++;
}

Student::Student(char studentId[], char studentName[], int k, float gp){
	set_id(studentId);
	set_name(studentName);	
	set_kurs(k);
	set_gpa(gp);
	number++;
}

Student::Student(Student &s){
	set_id(s.get_id());
	set_name(s.get_name());	
  	set_gpa(s.get_gpa());
  	set_kurs(s.get_kurs());
	number++;
}

Student::~Student(){
	delete[] id;
	delete[] name;
	number--;
}

int Student :: number = 0;

void Student::set_kurs(int k){
	if(k > 0){
		kurs = k;
	}
}

int Student::get_kurs(){
	return kurs;
}

void Student::set_gpa(float gp){
	if(gp >= 0 && gp <= 4){
		gpa = gp;
	}
}

float Student::get_gpa(){
	return gpa;
}

void Student::set_id(char studentId[]){
	if(id != NULL){
		delete[] id;
	}
	id = new char[strlen(studentId) + 1];
	strcpy(id, studentId);
}

char* Student::get_id(){
	return id;
}

void Student::set_name(char studentName[]){
	if(name != NULL){
		delete[] name;
	}
	name = new char[strlen(studentName) + 1];
	strcpy(name, studentName);
}

char* Student::get_name(){
	return name;
}

bool Student::lessThan(Student &s){
    return !greatThan(s);
}

bool Student::isEqual(Student &s){
    return kurs == s.get_kurs();
}

bool Student::greatThan(Student &s){
	if(kurs>s.get_kurs())
		return true;
	else
		return false;
}

bool Student::after(Student &s){
    cout<<"NAME"<< name << endl;
    cout<<"GET"<< s.get_name() <<endl;
    if(strcmp(name, s.get_name()) > 0){
   	cout<<"TRUE"<< endl;
	return true;
    }
    else{
	return false;
    }
}

bool Student::before(Student &s){
    return !after(s);
}

void Student::printNumber(){
	cout<<"Нийт " << number <<" обьект байна."<<"\n";
}

void Student::stdcopy(Student &s){
	set_id(s.get_id());
	set_name(s.get_name());	
  	set_gpa(s.get_gpa());
  	set_kurs(s.get_kurs());
}
