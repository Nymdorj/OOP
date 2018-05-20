#include "Student.h"
#include <string.h>
#include <iostream>

using namespace std;

Student::Student(){
	setStudentId((char *)" ");	
	setName((char *)" ");	
}

Student::Student(const Student &s){
	setStudentId(s.studentId);
	setName(s.name);	
}

Student::Student(char *id, char *name){
	setStudentId(id);
	setName(name);	
}

Student::~Student(){
	delete[] studentId;
	delete[] name;
}

void Student::setStudentId(char *id){
	if(studentId != NULL){
		delete[] studentId;
	}
	studentId = new char[strlen(id) + 1];
	strcpy(studentId, id);
}

char* Student::getStudentId(){
	return studentId;
}

void Student::setName(char *n){
	if(this->name != NULL){
		delete[] this->name;
	}
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}

char* Student::getName(){
	return this->name;
}
